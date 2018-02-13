#include <iostream>
#include "map.h"

using namespace std;

void printMenu();

int main()
{
    Map* map = createMap();
    cout << "INTERACTIVE MOD FOR WORKING WITH ASSOCIATIVE ARRAY \n\n";
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
            cout << "\n\'" << key << "\' is successfully added to dictionary \n\n";
            break;
        case '2':
            cout << "Enter key: ";
            cin >> key;
            cout << endl << getValue(map, key) << endl << endl;
            break;
        case '3':
            cout << "Enter key: ";
            cin >> key;
            cout << "\n\'" << key << "\' is "
                 << (isExists(map, key) ? "exists " : "not exists ") << endl << endl;
            break;
        case '4':
            cout << "Enter key: ";
            cin >> key;
            remove(map, key);
            cout << "\n\'" << key << "\' is successfully deleted from dictionary \n\n";
            break;
        case '5':
            cout << endl;
            printTree(map);
            cout << endl;
            break;
        case '6':
            cout << endl;
            printRoot(map);
            cout << endl;
            break;
        case '0':
            break;
        default:
            cout << "Wrong input( Please, try again \n\n";
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
