#include "sources.h"
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <fstream>

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
    for (int i = 0; i < newBook->maxSize; ++i) {
        newBook->notations[i] = new PhoneNotation{};
    }
    return newBook;
}

void deleteBook(PhoneBook* book)
{
    for (int i = 0; i < book->maxSize; ++i) {
        delete book->notations[i];
    }
    delete[] book->notations;
    delete book;
}

PhoneNotation* createNotation()
{
    PhoneNotation* note = new PhoneNotation{};
    cout << "\n<Creation new phone-notation>\n";
    cout << "Enter a name: ";
    cin >> note->name;
    cout << "Enter a number: ";
    cin >> note->number;
    cout << endl;

    return note;
}

bool addNotation(PhoneBook* book)
{
    // мб добвить проверку на уникальность
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
    cout << setw(15) << note->name << setw(15) << note->number << endl;
}

void printPhoneBook(PhoneBook* book)
{
    cout << setw(15) << "NAME" << setw(15) << "NUMBER" << endl;
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
    return "";
}

string findByName(const std::string& name, PhoneBook* book)
{
    for (int i = 0; i < book->index; ++i) {
        PhoneNotation* note = book->notations[i];
        if (note->name == name) {
            return note->number;
        }
    }
    return "";
}

bool unload(PhoneBook* book, const string& filename)
{
    ifstream fin(filename);
    if (!fin.is_open()) {
        return false;
    }
    int i = 0;
    bool isName = true;
    string buffer = "";
    while (!fin.eof()) {
        fin >> buffer;
        if (buffer.size() == 0) {
            break;
        }
        if (isName) {
            book->notations[i]->name += buffer;
        } else {
            book->notations[i]->number += buffer;
            (book->index)++;
            i++;
        }
        buffer.clear();
        isName = !isName;

    }
    fin.close();
    return true;
}

bool upload(PhoneBook* notes, const string& filename)
{
    FILE* file = fopen(filename.c_str(), "w");
    if (file == nullptr) {
        return false;
    }
    for (int i = 0; i < notes->index; ++i) {
        fprintf(file, "%20s ", notes->notations[i]->name.c_str());
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
    printf("3 - find name by number \n");
    printf("4 - find number by name \n");
    printf("5 - save current data in file \n");
    printf(">>> ");
    char choice = 0;
    cin >> choice;
    cin.get();
    return choice;
}

void mainLoop(PhoneBook* book, const string& filename)
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
        // name search
        case '3':
        {
            string number = "";
            printf("Please, enter a number to search: ");
            cin >> number;
            string name = findByNumber(number, book);
            cout << endl << "  " << ((name != "") ? name : "There is no such note :(");
            cout << endl << endl;
            break;
        }
        // number search
        case '4':
        {
            string name = "";
            printf("Please, enter a name to search: ");
            cin >> name;
            string number = findByName(name, book);
            cout << endl << "  " << ((number != "") ? number : "There is no such note :(");
            cout << endl << endl;
            break;
        }
        case '5':
        {
            if (upload(book, filename)) {
                printf("\nNotes successfully saved to \'%s\' \n\n", filename.c_str());
            } else {
                printf("\nERROR: \'%s\' cannot be opened. \n\n", filename.c_str());
            }
            break;
        }
        default:
            printf("Wrong input. Please, try again \n\n");
            break;
        }
        usersChoice = menu();
    }
}

void displayWelcome()
{
    cout << "...Welcome to the Telephone Dictionary...\n";
    cout << "Please, choose one of following items from MENU: \n\n";
}
