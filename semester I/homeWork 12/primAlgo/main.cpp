#include "primAlgo.h"
#include <stdio.h>

using namespace std;

int main()
{
    const char filename[] = "input.txt";
    Graph* myGraph = parseFile(filename);
    printGraph(myGraph);

    deleteGraph(myGraph);

    return 0;
}

