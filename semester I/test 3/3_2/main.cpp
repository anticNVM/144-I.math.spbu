#include <iostream>
#include <fstream>
#include "list.h"
#include <string>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cout << "ERROR: file cannot be opened. \n";
        return 1;
    }
    List* list = createList();
    while (!fin.eof()) {
        string buffer = "";
        getline(fin, buffer);
        if (buffer == "") {
            break;
        }
        add(buffer, list);
    }
    fin.close();
    List* unique = getUnique(list);

    cout << "LIST OF STRINGS \n";
    printList(list);

    cout << "\nLIST OF UNIQUE STRINGS \n";
    if (getSize(unique) == 0) {
        cout << "list is empty (" << endl;
    } else {
        printList(unique);
    }
    cout << endl;

    deleteList(list);
    deleteList(unique);
    return 0;
}

