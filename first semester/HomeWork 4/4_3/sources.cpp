#include "sources.h"
#include <iostream>
#include <string>

using namespace std;

struct PhoneNotation {
    int id;
    string name;
    string number;
};

struct PhoneBook {
    static const int maxSize = 100;
    PhoneNotation* notations[maxSize];
    int index = 0;
};

PhoneBook* createBook()
{
    PhoneBook* newBook = new PhoneBook{};
    return newBook;
}

PhoneNotation* createNotation()
{
    PhoneNotation* note = new PhoneNotation{};
    cout << "<Creation new phone-notation>\n";
    cout << "Enter a name: ";
    getline(cin, note->name);
    cout << "Enter a number: ";
    getline(cin, note->number);

    return note;
}

int addNotation(PhoneNotation* note, PhoneBook* book)
{
    // добвить проверку на уникальность
    if (book->index < book->maxSize) {
        note->id = book->index;
        book->notations[book->index] = note;
        (book->index)++;
        return 0;
    } else {
        return -1;
    }
}

void printNotation(PhoneNotation* note)
{
    cout << note->id << ") ";
    cout << note->name << " \t ";
    cout << note->number << endl;
}

void printPhoneBook(PhoneBook* book)
{
    cout << "Current Phone Book: \n";
    for (int i = 0; i < book->index; ++i) {
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
}

PhoneNotation* findByName(const std::string& name, PhoneBook* book)
{
    for (int i = 0; i < book->index; ++i) {
        PhoneNotation* note = book->notations[i];
        if (note->name == name) {
            return note;
        }
    }
}

// todo
// http://www.cplusplus.com/reference/string/string/
// http://www.cyberforum.ru/cpp-beginners/thread98315.html
// http://ci-plus-plus-snachala.ru/?p=1473
void unload(FILE* file, PhoneBook* book)
{
    int id = 0;
    while (!feof(file)) {
        string str = "";
        if (!fgets(str.c_str(), str.size(), file)) {
            break;
        }
        PhoneNotation* note = new PhoneNotation{};
        note->id = id;

    }
}

void load(PhoneBook* notes, FILE* file)
{

}

FILE* fopenImproved(char* fileName, const char* spec){

}
