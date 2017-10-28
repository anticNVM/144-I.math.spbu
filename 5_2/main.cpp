#include <iostream>
#include "cyclelist.h"

using namespace std;

int main()
{
    cout << "Enter n and m through space: ";
    int n = 0;
    int m = 0;
    cin >> n >> m;
    CycleList* squad = createCycle();
    addFirst(0, squad);
    CycleListElement* current = getFirst(squad);
    for (int i = 1; i < n; i++) {
        insert(i, current, squad);
        current = next(current);
    }
    printCycle(squad);

    return 0;
}

