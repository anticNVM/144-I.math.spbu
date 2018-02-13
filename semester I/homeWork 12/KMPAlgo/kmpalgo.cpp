#include "kmpalgo.h"
#include <string.h>
#include <stdlib.h>

int* prefixFunc(const char* str);

int* KMP(const char *haystack, const char *needle)
{
    int lenHaystack = strlen(haystack);
    int lenNeedle = strlen(needle);
    int* result = (int*)malloc(sizeof(int));
    char* joinedStr = new char[lenHaystack + lenNeedle + 1]{};
    strcpy(joinedStr, needle);
    strcat(joinedStr, "#");
    strcat(joinedStr, haystack);
    int* pi = prefixFunc(joinedStr);
    int count = 0;
    for (int i = 0; i < lenHaystack; ++i) {
        if (pi[i + lenNeedle + 1] == lenNeedle) {
            result[count] = i;
            result = (int*)realloc(result, (count + 1) * sizeof(int));
            count++;
        }
    }
    result[count] = 0;

    delete[] joinedStr;
    delete[] pi;

    return result;
}

int* prefixFunc(const char *str)
{
    unsigned len = strlen(str);
    int* pi = new int[len]{0, };

    for (unsigned i = 1; i < len; ++i) {
        int j = pi[i - 1];
        while (j > 0 && str[i] != str[j]) {
            j = pi[j - 1];
        }
        if (str[i] == str[j]) {
            pi[i] = j + 1;
        } else {
            pi[i] = 0;
        }
    }

    return pi;
}
