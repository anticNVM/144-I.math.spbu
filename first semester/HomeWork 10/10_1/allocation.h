#pragma once
#include <string>
#include <vector>

using std::vector;
using std::string;

// считывает данные из файла и формирует на их основе граф,
// представимый в виде матрицы смежности, и массив столиц
// @return false, если файл не был открыт, иначе true
bool parseFile(const string& filename, vector<vector<int>>& graph, vector<int>& capitals);

// по заданному графу и массиву столиц строит распределение "городов" по "странам"
// @return 2-мерный вектор, в каждой строке которого находятся
// 1) сначала номер соответствующей столицы
// 2) затем список городов, принадлежащий данной стране
vector<vector<int>> countryAllocation(const vector<vector<int>>& graph, const vector<int>& capitals);

// печатает в консоль матрицу смежности графа
void printGraph(const vector<vector<int>>& graph);

// печатает в консоль распределение городов по странам
void printAllocation(vector<vector<int>> allocation);
