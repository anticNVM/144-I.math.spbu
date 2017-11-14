#pragma once
#include <string>
#include <vector>

// hash table with open addressing (keys = string, value = int)
struct HashTable;

// return hash table
// default param. index = coefficient of capacity
HashTable* createTable(int index = 1);

// delete hash table
void deleteTable(HashTable* table);

// clear hash table
// set capacity of table by default
void clearTable(HashTable* table);

// add pair of key and value to hash table
void add(const std::string& key, HashTable*& table, int value = 0);

// delete key from table and set to zero value
void remove(const std::string& key, HashTable* table);

// return pointer to value of key in table
// if key not exist, return nullptr
int* getValue(const std::string& key, HashTable* table);

// add all keys from table to vector keys
void getKeys(HashTable* table, std::vector<std::string>& keys);

// return true if key in table, else return false
bool isInTable(const std::string& key, HashTable* table);

// return fill factor of hash table
float getFactor(HashTable* table);
