#include <iostream>
#include "cycleList.h"

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

    current = getFirst(squad);
    int currentSize = getSize(squad);
    while (currentSize > 1) {
        //printCycle(squad);
        current = moveNext(current, m);
        CycleListElement* prev = previous(current);
        remove(current, squad);
        current = prev;
        currentSize--;
    }
    cout << "The last warrior is ";
    printCycle(squad);

    deleteCycle(squad);
    return 0;
}

