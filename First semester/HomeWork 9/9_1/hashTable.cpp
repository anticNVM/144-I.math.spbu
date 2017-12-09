#include "hashTable.h"
#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

const int INITIAL_SIZE = 64;

struct HashTable {
    vector<pair<string, int>> array;
};

// polynomial hash with p = 7
int hashFunc(const string& key);

// polynomial hash with p = 3, return odd
int doubleHashFunc(const string& key);

// increase size of table doubly
void resizeTable(HashTable*& table);


HashTable* createTable(int index)
{
    HashTable* newTable = new HashTable{};
    newTable->array.resize(INITIAL_SIZE * index);
    return newTable;
}

void deleteTable(HashTable* table)
{
    delete table;
}

void clearTable(HashTable* table)
{
    for (auto backet : table->array) {
        backet.first.clear();
        backet.second = 0;
    }
    table->array.resize(INITIAL_SIZE);
}

void add(const std::string& key, HashTable*& table, int value)
{
    // add behavior for existed key
    auto hashValue = hashFunc(key) % table->array.capacity();
    auto hashStep = doubleHashFunc(key) % table->array.capacity();
    for (unsigned i = 0; i < table->array.capacity(); ++i) {
        if (table->array[hashValue].first == key) {
            return;
        } else if (table->array[hashValue].first == "") {
            table->array[hashValue].first = key;
            table->array[hashValue].second = value;
            break;
        } else {
            hashValue = (hashValue + hashStep) % table->array.capacity();
        }
    }
    if (getFactor(table) > 0.7) {
        resizeTable(table);
    }
}

void remove(const std::string& key, HashTable* table)
{
    // bevavior for existed key
    auto hashValue = hashFunc(key) % table->array.capacity();
    auto hashStep = doubleHashFunc(key) % table->array.capacity();
    for (unsigned i = 0; i < table->array.capacity(); ++i) {
        if (table->array[hashValue].first == key) {
            table->array[hashValue].first = "";
            table->array[hashValue].second = -1;
            return;
        } else {
            hashValue = (hashValue + hashStep) % table->array.capacity();
        }
    }
}

int* getValue(const std::string& key, HashTable* table)
{
    // bevavior for existed key
    auto hashValue = hashFunc(key) % table->array.capacity();
    auto hashStep = doubleHashFunc(key) % table->array.capacity();
    for (unsigned i = 0; i < table->array.capacity(); ++i) {
        if (table->array[hashValue].first == "" && table->array[hashValue].second == 0) {
            break;
        } else if (table->array[hashValue].first == key) {
            return &table->array[hashValue].second;
        } else {
            hashValue = (hashValue + hashStep) % table->array.capacity();
        }
    }
    return nullptr;
}

vector<string> getKeys(HashTable* table)
{
    vector<string> keys;
    for (auto basket : table->array) {
        if (basket.first != "") {
            keys.push_back(basket.first);
        }
    }
    return keys;
}

bool isInTable(const std::string& key, HashTable* table)
{
    auto hashValue = hashFunc(key) % table->array.capacity();
    auto hashStep = doubleHashFunc(key) % table->array.capacity();
    for (unsigned i = 0; i < table->array.capacity(); ++i) {
        if (table->array[hashValue].first == "" && table->array[hashValue].second == 0) {
            break;
        } else if (table->array[hashValue].first == key) {
            return true;
        } else {
            hashValue = (hashValue + hashStep) % table->array.capacity();
        }
    }
    return false;
}

float getFactor(HashTable* table)
{
    auto keys = getKeys(table);
    return (float(keys.size()) / float(table->array.capacity()));
}

int hashFunc(const string& key)
{
    int result = 0;
    int p = 7;
    for (auto ch : key) {
        result = (result * p) + ch;
    }
    return result;
}

int doubleHashFunc(const string& key)
{
    int result = 0;
    int p = 3;
    for (auto ch : key) {
        result = (result * p) + ch;
    }
    return (2 * result + 1);
}

void resizeTable(HashTable*& table)
{
    HashTable* newTable = createTable((table->array.capacity() / INITIAL_SIZE) * 2);
    auto keys = getKeys(table);
    for (auto key : keys) {
        add(key, newTable, *getValue(key, table));
    }
    HashTable* buffer = table;
    table = newTable;
    deleteTable(buffer);
}
