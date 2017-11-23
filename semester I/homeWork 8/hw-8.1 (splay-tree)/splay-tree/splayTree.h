#pragma once
#include <string>

typedef std::string KeyType;
typedef std::string ValueType;

struct SplayTree;

// Добавить значение по заданному ключу в ассоциативный массив.
// Если такой ключ уже есть, значение заменяется на новое.
void add(const KeyType& key, const ValueType& value, SplayTree* tree);

// Получить значение по заданному ключу из ассоциативного массива.
// Если такого ключа нет, возвращается пустая строка.
const ValueType& get(const KeyType& key, SplayTree* tree);

// Проверить наличие заданного ключа.
bool isExist(const KeyType& key, SplayTree* tree);

// Удалить заданный ключ и связанное с ним значение из ассоциативного массива.
// Если такого ключа нет, функция ничего не делает.
void deleteKey(const KeyType& key, SplayTree* tree);
