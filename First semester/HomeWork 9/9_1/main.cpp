#include <iostream>
#include <hashTable.h>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fin("text.in.txt");
    HashTable* myTable = createTable();
    string word = "";
    while (!fin.eof()) {
        word = fin.get();
        try {
            add(word, myTable);
        } catch (const string& msg) {

        }
        get(word, myTable)++;
    }
    cout << get("Mutter", myTable) << endl;
    deleteTable(myTable);
    return 0;
}

