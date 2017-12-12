#include "allocation.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> graph;
    vector<int> capitals;
    string filename = "input.txt";

    bool isSuccess = parseFile(filename, graph, capitals);
    if (!isSuccess) {
        cout << "ERROR: " << filename << " cannot be opened \n\n";
        return 1;
    } else {
        cout << "<< \"" << filename << "\"" << " successfully opened >> \n\n";
    }

    cout << "\tADJACENCY MATRIX: \n\n";
    printGraph(graph);
    auto allocation = countryAllocation(graph, capitals);

    cout << "\n\tCOUNTRY ALLOCATION: \n\n";
    printAllocation(allocation);

    return 0;
}
