#ifndef PRIMALGO
#define PRIMALGO

// граф, представлен в виде матрицы смежности
struct Graph;

// по данной в файле матрице смежности строит граф
Graph* parseFile(const char filename[]);

// удаляет граф
void deleteGraph(Graph* graph);

// печатает в консоль граф в виде матрицы смежности
void printGraph(Graph* graph);

// копирует граф и возвращает указатель на него
Graph* copy(Graph* graph);

// возвращает число вершин графа
int getAmountOfVertexes(Graph* graph);

// по данному графу строит минимальное остовное дерево
// возвращает список смежности
int** primAlgorithm(Graph* graph);

#endif // PRIMALGO

