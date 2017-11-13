#include "hashTable.h"
#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

const int INITIAL_SIZE = 64;

struct HashTable {
    vector<pair<string, int>> array;
};

int hashFunc(const string& key);
int doubleHashFunc(const string& key);
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
    auto firstHash = hashFunc(key) % table->array.capacity();
    auto secondHash = doubleHashFunc(key) % table->array.capacity();
    if (table->array[firstHash].first == key) {
        //cout << "YetExist" << endl;
        return;
    } else {
        for (unsigned i = 0; i < table->array.capacity(); ++i) {
            if (table->array[firstHash].first == "") {
                table->array[firstHash].first = key;
                table->array[firstHash].second = value;
                break;
            } else {
                firstHash = (firstHash + secondHash) % table->array.capacity();
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
        auto firstHash = hashFunc(key) % table->array.capacity();
        auto secondHash = doubleHashFunc(key) % table->array.capacity();
        for (unsigned i = 0; i < table->array.capacity(); ++i) {
            if (table->array[firstHash].first == key) {
                table->array[firstHash].first = "";
                table->array[firstHash].second = -1;
                return;
            } else {
                firstHash = (firstHash + secondHash) % table->array.capacity();
            }
        }
    }
}

int* getValue(const std::string& key, HashTable* table, const std::string& def)
{
    auto firsthash = hashFunc(key) % table->array.capacity();
    auto secondHash = doubleHashFunc(key) % table->array.capacity();
    for (unsigned i = 0; i < table->array.capacity(); ++i) {
        if (table->array[firsthash].first == "" && table->array[firsthash].second == 0) {
            return nullptr;
        } else if (table->array[firsthash].first == key) {
            return &table->array[firsthash].second;
        } else {
            firsthash = (firsthash + secondHash) % table->array.capacity();
        }
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
    auto firstHash = hashFunc(key) % table->array.capacity();
    auto secondHash = doubleHashFunc(key) % table->array.capacity();
    for (unsigned i = 0; i < table->array.capacity(); ++i) {
        if (table->array[firstHash].first == "" && table->array[firstHash].second == 0) {
            return false;
        } else if (table->array[firstHash].first == key) {
            return true;
        } else {
            firstHash = (firstHash + secondHash) % table->array.capacity();
        }
    }
}

float getFactor(HashTable* table)
{
    vector<string> keys;
    getKeys(table, keys);
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
    return 2 * result + 1;
}

void resizeTable(HashTable*& table)
{
    HashTable* newTable = createTable((table->array.capacity() / INITIAL_SIZE) + 1);
    vector<string> keys;
    getKeys(table, keys);
    for (auto key : keys) {
        add(key, newTable, *getValue(key, table));
    }
    HashTable* buffer = table;
    table = newTable;
    deleteTable(buffer);
}
