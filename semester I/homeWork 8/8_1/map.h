#pragma once
#include <string>

using std::string;

// ассоциативный массив строк
struct Map;

// добавляет пару key - value в массив
void add(Map* map, const string& key, const string& value);

// @return значение по ключу key
// @return "", если такого ключа не существует
string getValue(Map* map, const string& key);

// проверяет наличие ключа в массиве
bool isExists(Map* map, const string& key);

// удаляет пару значений по ключу из массива
void remove(Map* map, const string& key);

// возвращает указатель на новый массив
Map* createMap();

// удаляет массив
void deleteMap(Map* map);

// печатает ассоциативный массив в виде дерева
void printTree(Map* map);

// печатает корень дерева
void printRoot(Map* map);
