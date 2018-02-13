#include "lexicalanalizer.h"
#include <stdio.h>

using namespace std;

int main()
{
    const char filename[] = "input.txt";
    FILE* file = fopen(filename, "r");
    if (file == nullptr) {
        printf("\"%s\" cannot be opened.", filename);
        return 1;
    }
    const int length = 256;
    char str[length] = {};
    while (fscanf(file, "%s", str) != EOF) {
        if (stateMachine(str)) {
            printf("YES: \'%s\' is real number \n", str);
        } else {
            printf("NO:  \'%s\' is not real number \n", str);
        }
    }
    printf("\n");
    fclose(file);

    return 0;
}

