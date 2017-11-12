#include <iostream>
#include <hashTable.h>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fin("text.in.txt");
    HashTable* myTable = createTable();
    //cout << "kek" << endl;
    while (!fin.eof()) {
        string word = "";
        fin >> word;
        if (word != "") {
            add(word, myTable);
            (*getValue(word, myTable))++;
        }
    }
    cout << *getValue("mama", myTable) << endl;
    deleteTable(myTable);
    return 0;
}

