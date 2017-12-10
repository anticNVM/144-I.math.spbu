#include <iostream>
#include "graph.h"
#include <vector>

using namespace std;

vector<vector<int>> countryAllocation(Graph* graph);

int main()
{
    Graph* graph = parseFile("input.txt");

    deleteGraph(graph);
    return 0;
}

vector<vector<int>> countryAllocation(Graph* graph)
{
    vector<vector<int>> allocation = graph;
}
