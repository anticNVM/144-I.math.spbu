#include <iostream>
#include <fstream>
#include <map>
#include "mergesort.h"
#include "list.h"

using namespace std;

char selectSorting();

int main()
{
    ifstream fin("input.txt");
    map <string, string> dict = {};
    List* list = createList();
    if (!fin.is_open()) {
        return 1;
    }
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
    //int size = getSize(list);
    mergeSort(list);
    printList(list);
    deleteList(list);
    fin.close();
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

//    for (auto it = dict.begin(); it != dict.end(); ++it) {
//        cout << it->first << it->second << endl;
//    }
