#include <iostream>
#include <string>
#include <fstream>
#include <list.h>

using namespace std;

bool isSymmetrical(List* list);

int main()
{
    ifstream fin("input.txt");
    if (!fin.good()) {
        cout << "ERROR: file not opened!" << endl;
        return 1;
    }

    string numbers = "";
    List* list = createList();
    while ((getline(fin, numbers))) {
        string tmpNum = "";
        for (auto ch : numbers) {
            if (ch != ' ' && ch != '\n') {
                tmpNum += ch;
            } else {
                push(atoi(tmpNum.c_str()), list);
                tmpNum = "";
            }
        }
        push(atoi(tmpNum.c_str()), list);
        tmpNum = "";

        cout << "Numbers: ";
        printList(list);
        if (isSymmetrical(list)) {
            cout << "True:  List of numbers is symmetrical" << endl;
        } else {
            cout << "False: List of numbers is not symmetrical" << endl;
        }
        cout << endl;

        clearList(list);
    }
    fin.close();
    deleteList(list);

    return 0;
}

bool isSymmetrical(List* list)
{
    int listSize = getSize(list);
    bool isSym = true;
    for (int i = 0; i < (listSize / 2); ++i) {
        if (getValue(list, i) != getValue(list, listSize - i - 1)) {
            isSym = false;
            break;
        }
    }
    return isSym;
}
