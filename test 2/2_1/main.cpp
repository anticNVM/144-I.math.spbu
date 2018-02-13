#include <iostream>
#include "list.h"
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cout << "ERROR: File cannot be opened!\n";
        return 1;
    }
    List* list = createList();
    while (!fin.eof()) {
        int num = 0;
        fin >> num;
        add(num, list);
    }
    pop(list);

    reverse(list);
    cout << "Reversed list:\n";
    printList(list);

    deleteList(list);
    fin.close();

    return 0;
}

