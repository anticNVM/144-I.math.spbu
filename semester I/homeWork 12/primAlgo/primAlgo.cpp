#include "primAlgo.h"
#include <stdio.h>
#include <limits.h>
#include <assert.h>

const int INF = INT_MAX;

struct Graph {
    int** adjacencyMatrix = nullptr;
    int size = 0;

    Graph(const int amountOfVertexes);
    Graph(const Graph& obj);
    ~Graph();
};

Graph::Graph(const int amountOfVertexes)
{
    size = amountOfVertexes;
    adjacencyMatrix = new int*[size]{};
    for (int i = 0; i < size; ++i) {
        adjacencyMatrix[i] = new int[size]{};
    }
}

Graph::Graph(const Graph &obj)
{
    size = obj.size;
    adjacencyMatrix = new int*[size]{};
    for (int i = 0; i < size; ++i) {
        adjacencyMatrix[i] = new int[size]{};
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            adjacencyMatrix[i][j] = obj.adjacencyMatrix[i][j];
        }
    }
}

Graph::~Graph()
{
    for (int i = 0; i < size; ++i) {
        delete[] adjacencyMatrix[i];
    }
    delete[] adjacencyMatrix;
}

Graph* parseFile(const char filename[])
{
    FILE* file = fopen(filename, "r");
    if (file == nullptr) {
        return nullptr;
    }
    int amountOfVertexes = 0;
    fscanf(file, "%d", &amountOfVertexes);
    Graph* graph = new Graph(amountOfVertexes);
    for (int i = 0; i < graph->size; ++i) {
        for (int j = 0; j < graph->size; ++j) {
            fscanf(file, "%d", &graph->adjacencyMatrix[i][j]);
            if (graph->adjacencyMatrix[i][j] == 0) {
                graph->adjacencyMatrix[i][j] = INF;
            }
        }
    }
    fclose(file);
    return graph;
}

void deleteGraph(Graph* graph)
{
    graph->~Graph();
}

Graph* copy(Graph* graph)
{
    return new Graph(*graph);
}

void printGraph(Graph* graph)
{
    for (int i = 0; i < graph->size; ++i) {
        printf("|");
        for (int j = 0; j < graph->size; ++j) {
            if (graph->adjacencyMatrix[i][j] == INF) {
                printf("%3s |", "-");
            } else {
                printf("%3d |", graph->adjacencyMatrix[i][j]);
            }
        }
        printf("\n");
    }
}

int getAmountOfVertexes(Graph* graph)
{
    return graph->size;
}

bool isAllVisited(const bool array[], const int size)
{
    for (int i = 0; i < size; ++i) {
        if (!array[i]) {
            return false;
        }
    }
    return true;
}

int** primAlgorithm(Graph* graph)
{
    Graph* adjMatrixOfVisited = copy(graph);
    int** minCoveringTree = new int*[graph->size - 1]{};
    for (int i = 0; i < graph->size - 1; ++i) {
        minCoveringTree[i] = new int[2];
    }
    int currentEdge = 0;
    bool visitedVertexes[graph->size]{};
    visitedVertexes[0] = true;
    for (int i = 0; i < graph->size; ++i) {
        adjMatrixOfVisited->adjacencyMatrix[i][0] = INF;
    }
    int nearestVertex = 0;
    int minDistance = INF;
    int parent = 0;
    while (!isAllVisited(visitedVertexes, graph->size)) {
        for (int i = 0; i < graph->size; ++i) {
            if (visitedVertexes[i]) {
                for (int j = 0; j < graph->size; ++j) {
                    if (adjMatrixOfVisited->adjacencyMatrix[i][j] < minDistance) {
                        minDistance = adjMatrixOfVisited->adjacencyMatrix[i][j];
                        nearestVertex = j;
                        parent = i;
                    }
                }
            }
        }
        assert(minDistance != INF);
        minCoveringTree[currentEdge][0] = parent;
        minCoveringTree[currentEdge][1] = nearestVertex;
        currentEdge++;
        visitedVertexes[nearestVertex] = true;
        for (int i = 0; i < graph->size; ++i) {
            adjMatrixOfVisited->adjacencyMatrix[i][nearestVertex] = INF;
        }
        minDistance = INF;
    }
    return minCoveringTree;
}
