#include <iostream>
#include "list.h"
#include <fstream>

using namespace std;

void reverseList(List* list);

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
    remove(list);
    reverseList(list);
    printList(list);

    deleteList(list);
    fin.close();
    return 0;
}

void reverseList(List *list)
{

}
