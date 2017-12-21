#include "sources.h"
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    PhoneBook* myBook = createBook();
    const string filename = "telephoneDirectory.txt";
    if (!unload(myBook, filename)) {
        FILE* file = fopen(filename.c_str(), "w");
        fclose(file);
        unload(myBook, filename);
    }
    displayWelcome();
    mainLoop(myBook, filename);

    deleteBook(myBook);
    return 0;
}



