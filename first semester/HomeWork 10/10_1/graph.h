#pragma once
#include <string>

struct Graph;

Graph* parseFile(const std::string& filename);

void deleteGraph(Graph* graph);

void print(Graph* graph);
