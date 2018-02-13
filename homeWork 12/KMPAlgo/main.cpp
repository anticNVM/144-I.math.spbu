#include "kmpalgo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

void printIndexes(int* matchedIndexes, char* needle);
char* readHaystack(FILE* file);
char* readNeedle();

int main()
{
    const char filename[] = "input.txt";
    FILE* file = fopen(filename, "r");
    if (file == nullptr) {
        printf("ERROR: \"%s\" cannot be opened. \n", filename);
        return 1;
    }

    char* haystack = readHaystack(file);
    printf("TEXT FOR SEARCHING IN: \n%s \n", haystack);

    char* needle = readNeedle();
    fclose(file);

    // array of endings of matched substrings
    int* matchedIndexes = KMP(haystack, needle);

    // print indexes of matched substrs
    printf("\nMATCHES FOR PATTERN: \n\n");
    printIndexes(matchedIndexes, needle);

    free(matchedIndexes);
    free(haystack);
    free(needle);

    return 0;
}

char* readHaystack(FILE* file)
{
    char buffer = 0;
    int index = 0;
    char* haystack = (char*)malloc(sizeof(char));
    buffer = getc(file);
    while (buffer != EOF) {
        haystack[index] = buffer;
        haystack = (char*)realloc(haystack, (index + 1) * sizeof(char));
        index++;
        buffer = getc(file);
    }
    haystack[index] = '\0';
    return haystack;
}

char* readNeedle()
{
    char buffer = 0;
    int index = 0;
    char* needle = (char*)malloc(sizeof(char));
    printf("Please, enter pattern to search : \n");
    buffer = getchar();
    while (buffer != '\n') {
        needle[index] = buffer;
        needle = (char*)realloc(needle, (index + 1) * sizeof(char));
        index++;
        buffer = getchar();
    }
    needle[index] = '\0';
    return needle;
}

void printIndexes(int* matchedIndexes, char* needle)
{
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
}
