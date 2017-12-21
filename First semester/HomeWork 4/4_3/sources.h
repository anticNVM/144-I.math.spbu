#ifndef SOURCES
#define SOURCES

#include <stdio.h>
#include <string>

// массив телефонных записей размером 100
struct PhoneBook;

// телефонная запись
struct PhoneNotation;

// выводит приветствие и краткое описание
void displayWelcome();

// позволяет работать с пользователем в интерактивном режиме
// реализуются следующие команды:
// 0 - выйти
// 1 - добавить запись (имя и телефон)
// 2 - распечатать все имеющиеся записи
// 3 - найти имя по телефону
// 4 - найти телефон по имени
// 5 - сохранить текущие данные в файл
void mainLoop(PhoneBook* book, const std::string& filename);

// выгружает данные из файла в PhoneBook без удаления информации в файле
bool unload(PhoneBook* book, const std::__cxx11::string& filename);

// загружает данные из PhoneBook в файл (с удалением предыдущей информации)
bool upload(PhoneBook* notes, const std::__cxx11::string& filename);

// создает телефонный справочник
PhoneBook* createBook();

// удаляет локальную телефонную книгу
void deleteBook(PhoneBook* book);

// создает телефонную запись
PhoneNotation* createNotation();

// добавляет запись в PhoneBook
// возвращает 0, если запись успешно добавлена, -1 иначе
bool addNotation(PhoneBook* book);

// печатает в консоль все записи PhoneBook
void printPhoneBook(PhoneBook* book);

// возвращает первую найденную запись из PhoneBook по номеру
std::__cxx11::string findByNumber(const std::string& number, PhoneBook* book);

// возвращает первую найденную запись из PhoneBook по имени
std::__cxx11::string findByName(const std::string& name, PhoneBook* book);

#endif // SOURCES

