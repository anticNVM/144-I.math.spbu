#include <iostream>
#include "ui.h"
#include "sortedList.h"

using namespace std;

int main()
{
    SortedList* myList = createList();
    char choice = 0;
    do {
        displayMenu();
        choice = getChoice();
        menu(myList, choice);
    } while (choice != '0');

    return 0;
}
