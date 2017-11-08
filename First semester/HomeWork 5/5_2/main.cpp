#include <iostream>
#include "cyclelist.h"

using namespace std;

int main()
{
//    CycleList* myCycle = createCycle();
//    insertFirst(25, myCycle);
//    CycleListElement* current = getFirst(myCycle);
//    for (int i = 0; i < 5; ++i) {
//        cout << getValue(current) << endl;
//        current = next(current);
//    }
    int n = 10;
    int m = 3;

    CycleList* cycle = createCycle();
    insertFirst(0, cycle);
    CycleListElement* cycleElement = getFirst(cycle);
    for (int i = 1; i < n; ++i) {

    }

    return 0;
}

