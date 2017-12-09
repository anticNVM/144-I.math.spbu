#include "hashTable.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

// now str consists only of letters
void referenceStr(string& str);

int main()
{
    ifstream fin("text.in.txt");
    if (!fin.is_open()) {
        cout << "ERROR: File cannot be opened." << endl;
        return 1;
    }
    HashTable* table = createTable();
    while (!fin.eof()) {
        string word = "";
        fin >> word;
        referenceStr(word);
        if (word != "") {
            add(word, table);
            (*getValue(word, table))++;
        }
    }
    auto keys = getKeys(table);
    sort(keys.begin(), keys.end());
    cout << "  <Frequency of meeting words in text> \n";
    for (auto key : keys) {
        cout << setw(15) << key << setw(5) << *getValue(key, table) << endl;
    }
    cout << "\nLoad Factor of hash table is " << getFactor(table) << endl << endl;

    deleteTable(table);
    fin.close();
    return 0;
}

void referenceStr(string& str)
{
    string newStr = "";
    for (auto ch : str) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            newStr += ch;
        }
    }
    str = newStr;
}
