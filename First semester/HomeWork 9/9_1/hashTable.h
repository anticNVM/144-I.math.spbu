#pragma once

#include <string>
#include <vector>

struct HashTable;

HashTable* createTable();

void deleteTable(HashTable* table);

void clearTable(HashTable* table);

void add(const std::string& key, HashTable* table, int value = 0);

void remove(const std::string& key, HashTable* table);

int getValue(const std::string& key, HashTable* table);

std::vector<std::string>& keys(HashTable* table);

bool isInTable(const std::string& key, HashTable* table);

int getFactor(HashTable* table);
