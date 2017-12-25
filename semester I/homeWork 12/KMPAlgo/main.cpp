#include "kmpalgo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    const char filename[] = "input.txt";
    FILE* file = fopen(filename, "r");
    if (file == nullptr) {
        printf("ERROR: \"%s\" cannot be opened. \n", filename);
        return 1;
    }

    char* haystack = (char*)malloc(sizeof(char));
    char* needle = (char*)malloc(sizeof(char));
    char buffer = 0;
    int index = 0;

    // read haystack from file
    buffer = getc(file);
    while (buffer != EOF) {
        haystack[index] = buffer;
        haystack = (char*)realloc(haystack, (index + 1) * sizeof(char));
        index++;
        buffer = getc(file);
    }
    haystack[index] = '\0';
    fclose(file);
    printf("TEXT FOR SEARCHING IN: \n%s \n", haystack);

    // read needle from stdin
    buffer = 0;
    index = 0;
    printf("Please, enter pattern to search : \n");
    buffer = getchar();
    while (buffer != '\n') {
        needle[index] = buffer;
        needle = (char*)realloc(needle, (index + 1) * sizeof(char));
        index++;
        buffer = getchar();
    }
    needle[index] = '\0';

    // array of endings of matched substrings
    int* matchedIndexes = KMP(haystack, needle);

    // print indexes of matched substrs
    printf("\nMATCHES FOR PATTERN: \n\n");
    int i = 0;
    if (matchedIndexes[i] == 0) {
        printf("no matches \n");
    } else {
        printf("indexes: ");
        while (matchedIndexes[i] != 0) {
            printf("%d ", (matchedIndexes[i] - (int)strlen(needle) + 1));
            i++;
        }
        printf("\n");
    }
    printf("\n");

    free(matchedIndexes);
    free(haystack);
    free(needle);

    return 0;
}

