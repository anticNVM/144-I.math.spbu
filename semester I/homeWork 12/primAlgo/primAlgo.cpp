#include "primAlgo.h"
#include <stdio.h>

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
        }
    }
    fclose(file);
    return graph;
}

Graph* copy(Graph* graph)
{
    return new Graph(*graph);
}

void deleteGraph(Graph* graph)
{
    graph->~Graph();
}

void printGraph(Graph* graph)
{
    for (int i = 0; i < graph->size; ++i) {
        for (int j = 0; j < graph->size; ++j) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}
