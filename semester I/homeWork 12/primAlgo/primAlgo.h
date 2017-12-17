#ifndef PRIMALGO
#define PRIMALGO

struct Graph;

Graph* parseFile(const char filename[]);
void deleteGraph(Graph* graph);
void printGraph(Graph* graph);
Graph* copy(Graph* graph);
int** primAlgorithm(Graph* graph);

#endif // PRIMALGO

