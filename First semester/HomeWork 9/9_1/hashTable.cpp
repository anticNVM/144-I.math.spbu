#include "hashTable.h"
#include <vector>
#include <utility>
#include <string>

using namespace std;

int INITIAL_SIZE = 64;

struct HashTable {
    vector<pair<string, int>> array;
    int fillFactor = array.size() / array.capacity();
};

int myHash(const string& key);

HashTable* createTable()
{
    HashTable* newTable = new HashTable;
    newTable->array.resize(INITIAL_SIZE);
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
    auto h = myHash(key) % table->array.capacity();
    while (table->array[h].first != key) {

    }
}

void remove(const std::string& key, HashTable* table);

int getValue(const std::string& key, HashTable* table);

std::vector<std::string>& keys(HashTable* table);

bool isInTable(const std::string& key, HashTable* table);

int getFactor(HashTable* table);

int myHash(const string& key)
{
    int result = 0;
    int p = 7;
    for (auto ch : key) {
        result = (result * p) + ch;
    }
    return result;
}
