#include "allocation.h"
#include <fstream>
#include <limits>
#include <set>
#include <utility>
#include <iostream>
#include <iomanip>
#include <algorithm>

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
    values.push_back(atoi(temp.c_str()));
    temp.clear();
    return values;
}

bool parseFile(const string& filename, vector<vector<int>>& graph, vector<int>& capitals)
{
    ifstream fin(filename);
    if (!fin.is_open()) {
        return false;
    }

    string buffer = "";
    getline(fin, buffer);
    vector<int> values = parseString(buffer);
    int vertexes = values[0];
    int edges = values[1];

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

vector<vector<int>> countryAllocation(const vector<vector<int>>& graph, const vector<int>& capitals)
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

    int currentCountry = 0;
    // граф несвязный -> бесконечный цикл :(
    while (!noVisited.empty()) {
        int minDistance = INF;
        int nearestCity = 0;
        for (auto city : allocation[currentCountry]) {
            for (unsigned i = 0; i < graph.size(); ++i) {
                if (graph[city][i] < minDistance && noVisited.count(i) == 1) {
                    minDistance = graph[city][i];
                    nearestCity = i;
                }
            }
        }
        if (minDistance != INF) {
            allocation[currentCountry].push_back(nearestCity);
            noVisited.erase(nearestCity);
        }
        currentCountry = (currentCountry + 1) % capitals.size();
    }
    return allocation;
}

void printGraph(const vector<vector<int>>& graph)
{
    for (unsigned i = 0; i < graph.size(); ++i) {
        cout << "|";
        for (unsigned j = 0; j < graph.size(); ++j) {
            cout << setw(3);
            (graph[i][j] != INF) ? (cout << graph[i][j]) : (cout << "-");
            cout << " |";
        }
        cout << endl;
    }
}

void printAllocation(vector<vector<int>> allocation)
{
    for (auto country : allocation) {
        cout << "Capital #" << country[0] << " -- cities: ";
        for_each (country.begin() + 1, country.end(), [](int city) {
           cout << city << " ";
        });
        cout << endl;
    }
    cout << endl;
}
