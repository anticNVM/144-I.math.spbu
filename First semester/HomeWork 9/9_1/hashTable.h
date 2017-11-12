#pragma once

#include <string>
#include <vector>

struct HashTable;

HashTable* createTable(int index = 1);

void deleteTable(HashTable* table);

void clearTable(HashTable* table);

void add(const std::string& key, HashTable* table, int value = 0);

void remove(const std::string& key, HashTable* table);

int getValue(const std::string& key, HashTable* table);

void getKeys(HashTable* table, std::vector<std::string>& keys);

bool isInTable(const std::string& key, HashTable* table);

int getFactor(HashTable* table);
