#include "sources.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct PhoneNotation {
    string name;
    string number;
};

struct PhoneBook {
    const int maxSize = 100;
    PhoneNotation** notations;
    int index = 0;
};

PhoneBook* createBook()
{
    PhoneBook* newBook = new PhoneBook{};
    newBook->notations = new PhoneNotation*[newBook->maxSize];
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

int addNotation(PhoneNotation* note, PhoneBook* book)
{
    // добвить проверку на уникальность
    if (book->index < book->maxSize) {
        book->notations[book->index] = note;
        (book->index)++;
        return 0;
    } else {
        return -1;
    }
}

void printNotation(PhoneNotation* note)
{
    cout << note->name << " \t ";
    cout << note->number << endl;
}

void printPhoneBook(PhoneBook* book)
{
    cout << "Current Phone Book: \n";
    for (int i = 0; i < book->index; ++i) {
        cout << i + 1 << ") ";
        printNotation(book->notations[i]);
    }
    cout << endl;
}

PhoneNotation* findByNumber(const std::string& number, PhoneBook* book)
{
    for (int i = 0; i < book->index; ++i) {
        PhoneNotation* note = book->notations[i];
        if (note->number == number) {
            return note;
        }
    }
    return nullptr;
}

PhoneNotation* findByName(const std::string& name, PhoneBook* book)
{
    for (int i = 0; i < book->index; ++i) {
        PhoneNotation* note = book->notations[i];
        if (note->name == name) {
            return note;;
        }
    }
    return nullptr;
}

// http://ci-plus-plus-snachala.ru/?p=1473
bool unload(const string& filename, PhoneBook* book)
{
    FILE* file = fopen(filename.c_str(), "r");
    if (file == nullptr) {
        return false;
    }
    const int size = 100;
    char* buffer[size] = {};
    const char* separators = " \t\n";
    while (!feof(file)) {
        char* word = nullptr;
        fgets(buffer, size, file);
        if (strlen(buffer) == 0) {
            break;
        }
        word = strtok(buffer, separators);
    }
    return true;
}

bool upload(PhoneBook* notes, const string& filename)
{
    FILE* file = fopen(filename.c_str(), "w");
    if (file == nullptr) {
        return false;
    }
    for (int i = 0; i < notes->index; ++i) {
        fputs((notes->notations[i]->name).c_str(), file);
        fprintf(file, "%c", '\t');
        fprintf(file, "%p\n", (notes->notations[i]->number).c_str());
    }
    return true;
}
