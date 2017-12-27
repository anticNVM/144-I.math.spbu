#include <iostream>
#include "map.h"
#include <fstream>

using namespace std;

void printMenu();

int main()
{
    //ifstream cin("input.txt");
    Map* map = createMap();
    char choice = 0;
    while (choice != '0') {
        printMenu();
        cout << ">>> ";
        cin >> choice;
        string key = "";
        string value = "";
        switch (choice) {
        case '1':
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter value: ";
            cin >> value;
            add(map, key, value);
            break;
        case '2':
            cout << "Enter key: ";
            cin >> key;
            cout << getValue(map, key) << endl;
            break;
        case '3':
            cout << "Enter key: ";
            cin >> key;
            cout << isExists(map, key) << endl;
            break;
        case '4':
            cout << "Enter key: ";
            cin >> key;
            remove(map, key);
            break;
        case '5':
            printTree(map);
            break;
        case '6':
            printRoot(map);
            break;
        case '0':
            break;
        default:
            cout << "Wrong input( \n";
            break;
        }
    }

    deleteMap(map);
    return 0;
}

void printMenu()
{
    cout << "1 - add \n";
    cout << "2 - get \n";
    cout << "3 - check \n";
    cout << "4 - remove \n";
    cout << "5 - print tree \n";
    cout << "6 - print only root \n";
    cout << "0 - exit \n";
}
