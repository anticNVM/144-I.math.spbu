#include "hashTable.h"
#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

const int INITIAL_SIZE = 32;

struct HashTable {
    vector<pair<string, int>> array;
};

int myHash(const string& key);
void resizeTable(HashTable* table);

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

void add(const std::string& key, HashTable* table, int value)
{
    // add behavior for existed key
    auto h1 = myHash(key) % table->array.capacity();
    auto h2 = myHash(key) % (table->array.capacity() - 1) + 1;
    if (table->array[h1].first == key) {
        return;
    } else {
        for (unsigned i = 0; i < table->array.capacity(); ++i) {
            if (table->array[h1].first == "") {
                table->array[h1].first = key;
                table->array[h1].second = value;
                return;
            } else {
                h1 = (h1 + h2) % table->array.capacity();
            }
        }
        if (getFactor(table) > 0.7) {
            resizeTable(table);
        }
    }
}

void remove(const std::string& key, HashTable* table, const string& def)
{
    if (!isInTable(key, table)) {
        cout << def << endl;
        return;
    } else {
        auto h1 = myHash(key) % table->array.capacity();
        auto h2 = myHash(key) % (table->array.capacity() - 1) + 1;
        for (unsigned i = 0; i < table->array.capacity(); ++i) {
            if (table->array[h1].first == key) {
                table->array[h1].first = "";
                table->array[h1].second = -1;
                return;
            } else {
                h1 = (h1 + h2) % table->array.capacity();
            }
        }
    }
}

int* getValue(const std::string& key, HashTable* table, const std::string& def)
{
    if (!isInTable(key, table)) {
        cout << '<' << def << '>' << endl;
        return nullptr;
    } else {
        auto h = myHash(key) % table->array.capacity();
        return &table->array[h].second;
    }
}

void getKeys(HashTable* table, std::vector<std::string>& keys)
{
    for (auto basket : table->array) {
        if (basket.first != "") {
            keys.push_back(basket.first);
        }
    }
}

bool isInTable(const std::string& key, HashTable* table)
{
    auto h1 = myHash(key) % table->array.capacity();
    auto h2 = myHash(key) % (table->array.capacity() - 1) + 1;
    for (unsigned i = 0; i < table->array.capacity(); ++i) {
        if (table->array[h1].first == "" && table->array[h1].second == 0) {
            return false;
        } else if (table->array[h1].first == key) {
            return true;
        } else {
            h1 = (h1 + h2) % table->array.capacity();
        }
    }
}

int getFactor(HashTable* table)
{
    return table->array.size() / table->array.capacity();
}

int myHash(const string& key)
{
    int result = 0;
    int p = 7;
    for (auto ch : key) {
        result = (result * p) + ch;
    }
    return result;
}

void resizeTable(HashTable* table)
{
    HashTable* newTable = createTable(table->array.capacity() / INITIAL_SIZE);
    for (auto backet : table->array) {
        if (backet.first != "") {
            add(backet.first, newTable, backet.second);
        }
    }
    HashTable* buffer = table;
    table = newTable;
    deleteTable(buffer);
}
