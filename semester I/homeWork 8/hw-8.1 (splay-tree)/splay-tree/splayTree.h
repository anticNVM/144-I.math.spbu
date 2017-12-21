#pragma once
#include <string>

typedef std::string KeyType;
typedef std::string ValueType;

struct Map;

// Добавить значение по заданному ключу в ассоциативный массив.
// Если такой ключ уже есть, значение заменяется на новое.
void add(const KeyType& key, const ValueType& value, Map* map);

// Получить значение по заданному ключу из ассоциативного массива.
// Если такого ключа нет, возвращается пустая строка.
const ValueType& get(const KeyType& key, Map* map);

// Проверить наличие заданного ключа.
bool isExist(const KeyType& key, Map* map);

// Удалить заданный ключ и связанное с ним значение из ассоциативного массива.
// Если такого ключа нет, функция ничего не делает.
void deleteKey(const KeyType& key, Map* map);
