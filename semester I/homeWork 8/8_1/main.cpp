#include <iostream>
#include "map.h"

using namespace std;

int main()
{
    Map* map = createMap();
    add(map, "test", "lul");
    add(map, "cow", "mu");
    add(map, "test", "kek");
    cout << getValue(map, "test") << endl;
    cout << isExists(map, "cow") << endl;


    return 0;
}