#include <stdio.h>
#include "commentsanalizer.h"

using namespace std;

int main()
{
    const char filename[] = "input.txt";
    FILE* file = fopen(filename, "r");
    if (file == nullptr) {
        printf("ERROR: \"%s\" cannot be opened\n", filename);
        return 1;
    }
    printf("Comments in \"%s\": \n\n", filename);
    stateMachine(file);
    printf("\n");

    fclose(file);
    return 0;
}

