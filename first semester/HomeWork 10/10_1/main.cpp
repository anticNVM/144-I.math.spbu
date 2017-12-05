#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
    Graph* graph = parseFile("input.txt");

    deleteGraph(graph);
    return 0;
}
