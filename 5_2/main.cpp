#include <iostream>
#include "cyclelist.h"

using namespace std;

int main()
{
    CycleList* myC = createCycle();
    addFirst(5, myC);

    cout << "test" << endl;

    return 0;
}

