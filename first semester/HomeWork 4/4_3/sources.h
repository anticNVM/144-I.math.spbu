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

// возвращает указатель на открытый файл или nullptr, если файл не удалось открыть
FILE* fopenImproved(char* fileName, const char* spec);

// выгружает данные из файла в PhoneBook без удаления информации в файле
void unload(FILE* file, PhoneBook* book);

// загружает данные из PhoneBook в файл (с удалением предыдущей информации)
void load(PhoneBook* notes, FILE* file);

// создает телефонный справочник
PhoneBook* createBook();

// создает телефонную запись
PhoneNotation* createNotation();

// добавляет запись в PhoneBook
// возвращает 0, если запись успешно добавлена, -1 иначе
int addNotation(PhoneNotation* note, PhoneBook* book);

// печатает в консоль запись <id) name number>
void printNotation(PhoneNotation* note);

// печатает в консоль все записи PhoneBook
void printPhoneBook(PhoneBook* book);

// возвращает запись из PhoneBook по номеру
PhoneNotation* findByNumber(const std::string& number, PhoneBook* book);

// возвращает запись из PhoneBook по имени
PhoneNotation* findByName(const std::string& name, PhoneBook* book);

#endif // SOURCES

