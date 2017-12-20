#ifndef SOURCES
#define SOURCES

#include <stdio.h>
#include <string>

struct PhoneBook;
struct PhoneNotation;

// выводит приветствие и краткое описание
void displayWelcome();

//
void mainLoop(PhoneBook* book);

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
bool addNotation(PhoneBook* book);

// печатает в консоль все записи PhoneBook
void printPhoneBook(PhoneBook* book);

// возвращает запись из PhoneBook по номеру
std::__cxx11::string findByNumber(const std::string& number, PhoneBook* book);

// возвращает запись из PhoneBook по имени
std::__cxx11::string findByName(const std::string& name, PhoneBook* book);

#endif // SOURCES

