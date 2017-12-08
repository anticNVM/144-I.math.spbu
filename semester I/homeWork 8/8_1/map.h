#pragma once
#include <string>

using std::string;

struct Map;

void add(Map* map, const string& key, const string& value);

string getValue(Map* map, const string& key);

bool isExists(Map* map, const string& key);

void remove(Map* map, const string& key);

Map* createMap();

void deleteMap(Map* map);

void printRoot(Map* map);
