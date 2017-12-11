#include "allocation.h"
#include <fstream>
#include <limits>
#include <set>
#include <utility>

using namespace std;

const int INF = INT32_MAX;

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

bool parseFile(const string& filename, vector<vector<int> >& graph, vector<int>& capitals)
{
    ifstream fin(filename);
    if (!fin.is_open()) {
        return false;
    }

    string buffer = "";
    getline(fin, buffer);
    vector<int> values = parseString(buffer);
    int edges = values[0];
    int vertexes = values[1];

    graph.resize(vertexes);
    for (int i = 0; i < vertexes; ++i) {
        for (int j = 0; j < vertexes; ++j) {
            graph[i].push_back(INF);
        }
    }

    for (int i = 0; i < edges; ++i) {
        getline(fin, buffer);
        values = parseString(buffer);
        graph[values[0]][values[1]] = values[2];
        graph[values[1]][values[0]] = values[2];
    }

    int capitalsAmount = 0;
    fin >> capitalsAmount;
    int buff = 0;
    for (int i = 0; i < capitalsAmount; ++i) {
        fin >> buff;
        capitals.push_back(buff);
    }

    fin.close();
    return true;
}

// to лямбда
pair<int, int> nearestVertex(const vector<vector<int> >& graph, const int from)
{
    int minDist = INF;
    int to = 0;
    for (unsigned i = 0; i < graph.size(); ++i) {
        if (graph[from][i] < minDist) {
            minDist = graph[from][i];
            to = i;
        }
    }

    return pair<int, int> (to, minDist);
}

vector<vector<int>> countryAllocation(const vector<vector<int> >& graph, const vector<int>& capitals)
{
    set<int> noVisited;
    for (unsigned i = 0; i < graph.size(); ++i) {
        noVisited.insert(i);
    }
    for (auto i : capitals) {
        noVisited.erase(i);
    }
    vector<vector<int>> allocation(capitals.size());
    for (unsigned i = 0; i < capitals.size(); ++i) {
        allocation[i].push_back(capitals[i]);
    }

    int i = 0;
    int minDistance = INF;
    int nearestCity = 0;
    // добавить проверку на связность
    while (!noVisited.empty()) {
        //int currentCapital = capitals[i];
        for (auto city : allocation[i]) {
            auto vertex = nearestVertex(graph, city);
            if (vertex.second < minDistance) {
                nearestCity = vertex.first;
            }
        }
        allocation[i].push_back(nearestCity);
        noVisited.insert(nearestCity);
        i = (i + 1) % capitals.size();
    }
    return allocation;
}
