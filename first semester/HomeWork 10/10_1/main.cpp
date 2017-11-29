#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

void makeGraph(ifstream& fin, vector<vector<int>> graph);

int main()
{
    ifstream fin("input.txt");
    fin.close();
    return 0;
}

void makeGraph(ifstream& fin, vector<vector<int>> graph)
{
    int n = 0;
    int m = 0;
    fin << n << m;
    graph.resize(n);
    for (int i = 0; i < m; ++i) {
        graph[
    }
}
