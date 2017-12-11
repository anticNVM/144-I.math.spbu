#pragma once
#include <string>
#include <vector>
//#include <set>

using std::vector;
using std::string;
//using std::set;

bool parseFile(const string& filename, vector<vector<int>>& graph, vector<int>& capitals);

vector<vector<int>> countryAllocation(const vector<vector<int>>& graph, const vector<int>& capitals);

void printGraph(const vector<vector<int>> graph);
