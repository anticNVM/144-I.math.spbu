#include "primAlgo.h"
#include <stdio.h>

using namespace std;

int main()
{
    const char filename[] = "input.txt";
    Graph* myGraph = parseFile(filename);
    printGraph(myGraph);
    printf("\n");
    int** minCoveringTree = primAlgorithm(myGraph);
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%d ", minCoveringTree[i][j]);
        }
        printf("\n");
    }


    deleteGraph(myGraph);
    return 0;
}

