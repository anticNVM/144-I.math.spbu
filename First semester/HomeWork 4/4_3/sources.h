#ifndef SOURCES
#define SOURCES

#include <stdio.h>
#include <iostream>

struct PhoneBook;
struct PhoneNotation;

// выводит приветствие и краткое описание
void displayWelcome();

// выводит меню и возвращает значение пользовательского ввода
char menuChoice();

// выгружает данные из файла в PhoneBook без удаления информации в файле
bool unload(PhoneBook* book, const std::__cxx11::string& filename);

// загружает данные из PhoneBook в файл (с удалением предыдущей информации)
bool upload(PhoneBook* notes, const std::__cxx11::string& filename);

// создает телефонный справочник
PhoneBook* createBook();

// создает телефонную запись
PhoneNotation* createNotation();

// добавляет запись в PhoneBook
// возвращает 0, если запись успешно добавлена, -1 иначе
int addNotation(PhoneNotation* note, PhoneBook* book);

// печатает в консоль запись <name number>
void printNotation(PhoneNotation* note);

// печатает в консоль все записи PhoneBook
void printPhoneBook(PhoneBook* book);

// возвращает запись из PhoneBook по номеру
PhoneNotation* findByNumber(const std::string& number, PhoneBook* book);

// возвращает запись из PhoneBook по имени
PhoneNotation* findByName(const std::string& name, PhoneBook* book);

#endif // SOURCES

