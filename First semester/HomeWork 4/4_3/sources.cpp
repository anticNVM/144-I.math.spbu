#include "sources.h"
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;

struct PhoneNotation {
    string name = "";
    string number = "";
};

struct PhoneBook {
    const int maxSize = 100;
    PhoneNotation** notations = nullptr;
    int index = 0;
};

PhoneBook* createBook()
{
    PhoneBook* newBook = new PhoneBook{};
    newBook->notations = new PhoneNotation*[newBook->maxSize]{};
    return newBook;
}

PhoneNotation* createNotation()
{
    PhoneNotation* note = new PhoneNotation{};
    cout << "<Creation new phone-notation>\n";
    cout << "Enter a name: ";
    cin >> note->name;
    cout << "Enter a number: ";
    cin >> note->number;

    return note;
}

bool addNotation(PhoneBook* book)
{
    // добвить проверку на уникальность
    if (book->index < book->maxSize) {
        PhoneNotation* note = createNotation();
        book->notations[book->index] = note;
        (book->index)++;
        return true;
    } else {
        return false;
    }
}

void printNotation(PhoneNotation* note)
{
    cout << setw(20) << note->name << setw(20) << note->number << endl;
}

void printPhoneBook(PhoneBook* book)
{
    cout << "Current Phone Book: \n";
    cout << setw(20) << "NAME" << setw(20) << "NUMBER: " << endl;
    for (int i = 0; i < book->index; ++i) {
        printNotation(book->notations[i]);
    }
    cout << endl;
}

string findByNumber(const std::string& number, PhoneBook* book)
{
    for (int i = 0; i < book->index; ++i) {
        PhoneNotation* note = book->notations[i];
        if (note->number == number) {
            return note->name;
        }
    }
    return nullptr;
}

string findByName(const std::string& name, PhoneBook* book)
{
    for (int i = 0; i < book->index; ++i) {
        PhoneNotation* note = book->notations[i];
        if (note->name == name) {
            return note->number;
        }
    }
    return nullptr;
}

bool unload(PhoneBook* book, const string& filename)
{
    FILE* file = fopen(filename.c_str(), "r");
    if (file == nullptr) {
        return false;
    }
    int i = 0;
    bool isName = true;
    string buffer = "";
    while (fscanf(file, "%s", buffer.c_str()) != EOF) {
        if (isName) {
            book->notations[i]->name = buffer;
        } else {
            book->notations[i]->number = buffer;
            (book->index)++;
            i++;
        }
        buffer.clear();
        isName = !isName;

    }
    fclose(file);
    return true;
}

bool upload(PhoneBook* notes, const string& filename)
{
    FILE* file = fopen(filename.c_str(), "w");
    if (file == nullptr) {
        return false;
    }
    for (int i = 0; i < notes->index; ++i) {
        fprintf(file, "%20s - ", notes->notations[i]->number.c_str());
        fprintf(file, "%10s\n", notes->notations[i]->number.c_str());
    }
    fclose(file);
    return true;
}

char menu()
{
    printf("--MENU--\n");
    printf("0 - exit \n");
    printf("1 - add note \n");
    printf("2 - print all notes \n");
    printf("3 - find number by name \n");
    printf("4 - find name bu bumber \n");
    printf("5 - save current data in file \n");
    printf(">>> ");
    char choice = 0;
    scanf("%c", &choice);
    return choice;
}

//enum struct Choices {
//    add,
//    print,
//    findNumber,
//    findName,
//    save,
//    exit
//};

void mainLoop(PhoneBook* book)
{
    char usersChoice = menu();
    while (usersChoice != '0') {
        switch (usersChoice) {
        case '1':
        {
            if (!addNotation(book)) {
                printf("The note cannot be added because the directory is full \n");
            }
            break;
        }
        case '2':
        {
            printPhoneBook(book);
            break;
        }
        case '3':
        {
            string number = "";
            printf("Please, enter a number to search: ");
            cin >> number;
            string name = findByNumber(number, book);
            cout << name << endl;
            break;
        }
        case '4':
        {
            string name = "";
            printf("Please, enter a name to search: ");
            cin >> name;
            string number = findByNumber(name, book);
            cout << number << endl;
            break;
        }
        case '5':
        {
            string filename = "";
            if (upload(book, filename)) {
                printf("Notes successfully saved to \'%s\' \n", filename.c_str());
            } else {
                printf("ERROR: \'%s\' cannot be opened. \n", filename.c_str());
            }
            break;
        }
        default:
            printf("Wrong input. Please, try again \n");
            break;
        }
        usersChoice = menu();
    }
}

void displayWelcome()
{
    printf("kek \n");
}
