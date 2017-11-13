#include <iostream>
#include <hashTable.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void referenceStr(string& str);

int main()
{
    ifstream fin("text.in.txt");
    HashTable* table = createTable();
    while (!fin.eof()) {
        string word = "";
        fin >> word;
        referenceStr(word);
        if (word != "") {
            cout << "kek" << ' ';
            add(word, table);
            (*getValue(word, table))++;
        }
    }
    fin.close();
    vector<string> keys;
    getKeys(table, keys);
    for (auto key : keys) {
        cout << key << ' ' << (*getValue(key, table)) << endl;
    }
    cout << endl << getFactor(table) << endl;
    deleteTable(table);
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
