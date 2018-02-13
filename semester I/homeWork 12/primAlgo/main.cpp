#include "primAlgo.h"
#include <stdio.h>

using namespace std;

void printAdjacencyList(int** tree, const int amountOfVertexes);

int main()
{
    const char filename[] = "input.txt";
    Graph* myGraph = parseFile(filename);
    if (myGraph == nullptr) {
        printf("ERROR: \'%s\' cannot be opened", filename);
        return 1;
    }
    printf("\n\tADJACENCY MATRIX: \n\n");
    printGraph(myGraph);
    printf("\n");

    int** minCoveringTree = primAlgorithm(myGraph);
    int graphSize = getAmountOfVertexes(myGraph);
    printf("\n\tMINIMUM SPANNING TREE: \n\n");
    printAdjacencyList(minCoveringTree, graphSize);
    printf("(spanning tree is presented in adjacency list form) \n\n");

    for (int i = 0; i < graphSize - 1; ++i) {
        delete[] minCoveringTree[i];
    }
    delete[] minCoveringTree;
    deleteGraph(myGraph);
    return 0;
}

void printAdjacencyList(int** tree, const int amountOfVertexes)
{
    for (int j = 0; j < 2; ++j) {
        printf("|");
        for (int i = 0; i < amountOfVertexes - 1; ++i) {
            printf("%3d |", tree[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
