#include "sources.h"
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    PhoneBook* myBook = createBook();
    const string filename = "telephoneDirectory.txt";
    if (unload(myBook, filename)) {
        return 1;
    }
    displayWelcome();
    mainLoop(myBook);

    return 0;
}



