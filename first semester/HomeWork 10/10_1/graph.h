#pragma once
#include <string>
#include <vector>

struct Graph;

Graph* parseFile(const std::string& filename);

void deleteGraph(Graph* graph);

std::vector<std::vector<int>> countryAllocation(Graph* graph);

void printGraph(Graph* graph);
