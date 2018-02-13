#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include "mergesort.h"
#include "list.h"

using namespace std;

char selectSorting();

int main()
{
    ifstream fin("input.txt");
    map<string, string> dict{};
    if (!fin.is_open()) {
        cout << "ERROR: file cannot be opened. \n";
        return 1;
    }
    List* list = createList();
    char choice = selectSorting();
    while (!fin.eof()) {
        string name = "";
        string number = "";
        fin >> name >> number;
        string key = "";
        string value = "";
        if (choice == '1') {
            key = name;
            value = number;
        } else {
            key = number;
            value = name;
        }
        if (key != "") {
            dict[key] = value;
            add(key,list);
        }
    }
    fin.close();
    mergeSort(list);

    moveTo(list);
    int size = getSize(list);
    for (int i = 0; i < size; ++i) {
        cout << setw(15) << getCurrentValue(list) << " - "
             << setw(15) << dict.at(getCurrentValue(list)) << endl;
        if (!isEnd(list)) {
            next(list);
        }
    }

    deleteList(list);
    return 0;
}

char selectSorting()
{
    cout << "Choose the way to sort: \n"
         << "1 - by name \n"
         << "2 - by number \n>>> ";
    char choice = 0;
    cin >> choice;
    while (choice != '1' && choice != '2') {
        cout << "Please, enter correct input \n>>> ";
        cin >> choice;
    }
    return choice;
}
