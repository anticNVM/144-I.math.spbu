#include "hashTable.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// now str consists only of letters
void referenceStr(string& str);

int main()
{
    ifstream fin("text.in.txt");
    if (fin.good()) {
        HashTable* table = createTable();
        while (!fin.eof()) {
            string word = "";
            fin >> word;
            referenceStr(word);
            if (word != "") {
                // cout << "log" << ' ';
                add(word, table);
                (*getValue(word, table))++;
            }
        }
        vector<string> keys;
        getKeys(table, keys);
        cout << "  <Frequency of meeting words in text> \n";
        for (auto key : keys) {
            cout << setw(15) << key << setw(5) << (*getValue(key, table)) << endl;
        }
        cout << "\nLoad Factor of hash table is " << getFactor(table) << endl << endl;
        deleteTable(table);
    } else {
        cout << "ERROR: File cannot be opened." << endl;
    }
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
