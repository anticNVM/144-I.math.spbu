#include "commentsanalizer.h"
#include <stdio.h>

int status(char ch);

void stateMachine(FILE* file)
{
    int amountOfStates = 0;
    fscanf(file, "%d", &amountOfStates);
    int amountOfTokens = 0;
    fscanf(file, "%d", &amountOfTokens);
    int** stateTable = new int*[amountOfStates];
    for (int i = 0; i < amountOfStates; ++i) {
        stateTable[i] = new int[amountOfTokens];
    }
    for (int i = 0; i < amountOfStates; ++i) {
        for (int j = 0; j < amountOfTokens; ++j) {
            fscanf(file, "%d", &stateTable[i][j]);
        }
    }

//    int stateTable[4][3] = {
//     /* 's' '/' '*'     */
//        {0,  1,  0},    // read symbols, not a comment
//        {0,  1,  2},    // read '/' (means begin of comment, if next symbol is '*')
//        {2,  2,  3},    //`read comment
//        {2,  0,  3}     // read '*' (means end of comment, if next symbol is '/')
//    };

    int currentState = 0;
    int previousState = 0;
    char token = fgetc(file);
    while (token != EOF) {
        previousState = currentState;
        currentState = stateTable[currentState][status(token)];
        if (previousState == 1 && currentState == 2) {
            printf("/");
        }
        if (currentState == 2 || currentState == 3) {
            printf("%c", token);
        }
        if (previousState == 3 && currentState == 0) {
            printf("/\n");
        }
        token = fgetc(file);
    }
    for (int i = 0; i < amountOfStates; ++i) {
        delete[] stateTable[i];
    }
    delete[] stateTable;
}

int status(char ch)
{
    if (ch == '/') {
        return 1;
    } else if (ch == '*') {
        return 2;
    } else {
        return 0;
    }
}
