#include "ui.h"
#include <iostream>

using namespace std;

void displayMenu()
{
    cout << "Choose one: \n";
    cout << "0 - exit\n";
    cout << "1 - add value to list\n";
    cout << "2 - delete value from list\n";
    cout << "3 - print list\n";
}

char getChoice()
{
    char choice = 0;
    cout << ">>> ";
    cin >> choice;
    return choice;
}

void menu(SortedList *list, char choice)
{
    switch (choice) {
        case '1':
        {
            int val = 0;
            cout << "Enter a value: ";
            cin >> val;
            push(val, list);
            break;
        }
        case '2':
        {
            int val = 0;
            cout << "Enter a value for deleting: ";
            cin >> val;
            int id = getIndex(val, list);
            if (id == -1) {
                cout << "Element were not found.\n";
            } else {
                remove(list, id);
                cout << "Element was successfully deleted.\n";

            }
            break;
        }
        case '3':
        {
            if (!isEmpty(list)) {
                cout << "<Sorted List>" << endl;
                printList(list);
            } else {
                cout << "List is empty :(\n";
            }
            break;
        }
        case '0':
        {
            deleteList(list);
            cout << "List was successfully deleted.\n";
            break;
        }
        default:
        {
            cout << "Wrong input. Please, try again" << endl;
            break;
        }
    }
    cout << endl;
}
