#include "graph.h"
#include <list>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Graph {
    list<vector<int>> peaks;
    int** distance = nullptr;
    vector<int> capitals;
};

vector<int> parseString(const string& str)
{
    vector<int> values;
    string temp = "";
    for (auto ch : str) {
        if (ch != ' ') {
            temp += ch;
        } else {
            values.push_back(atoi(temp.c_str()));
            temp.clear();
        }
    }
    return values;
}

Graph* parseFile(const string& filename)
{
    ifstream fin(filename);
    if (!fin.is_open())
        return nullptr;

    Graph* graph = new Graph{};

    string buffer = "";
    getline(fin, buffer);
    vector<int> values = parseString(buffer);
    int edgesAmount = values[0];
    int peaksAmount = values[1];

    graph->peaks.resize(peaksAmount + 1);
    graph->distance = new int[][peaksAmount];
    for (int i = 0; i < peaksAmount; ++i) {
        graph->distance[i] = new int[peaksAmount];
    }

    for (int i = 0; i < edgesAmount; ++i) {
        getline(fin, buffer);
        values = parseString(buffer);
        graph->peaks[values[0]].push_back(values[1]);
        graph->peaks[values[1]].push_back(values[0]);
        graph->distance[values[0]][values[1]] = values[2];
        graph->distance[values[1]][values[0]] = values[2];
    }

    int capitalsAmount = 0;
    fin >> capitalsAmount;
    int buff = 0;
    for (int i = 0; i < capitalsAmount; ++i) {
        fin >> buff;
        graph->capitals.push_back(buff);
    }

    fin.close();
    return graph;
}

void deleteGraph(Graph* graph)
{
    for (int i = 0; i < (graph->peaks.size() - 1); ++i) {
        delete[] graph->distance[i];
    }
    delete[] graph->distance;
    delete graph;
}

void print(Graph* graph)
{

}
