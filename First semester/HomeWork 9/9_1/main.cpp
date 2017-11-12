#include <iostream>
#include <hashTable.h>
#include <fstream>

using namespace std;

int main()
{
    istream cin("text.in.txt");
    HashTable* myTable = createTable();

    deleteTable(myTable);
    return 0;
}

