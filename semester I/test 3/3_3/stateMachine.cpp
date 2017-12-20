#include "stateMachine.h"
#include <string.h>

int status(char ch);

bool stateMachine(const char* str)
{
    int stateTable[6][6] = {
      /* let d-  '.' '@' _%+ else   */
        { 1,  1,  1, -1,  1, -1},   // start
        { 1,  1,  1,  2,  1, -1},   // read right symbol before '@'
        { 3,  3, -1, -1, -1, -1},   // read '@'
        { 3,  3,  4, -1, -1, -1},   // read right symbol after '@'
        { 5,  3, -1, -1, -1, -1},   // read '.'
        { 3,  3,  4, -1, -1, -1}    // ended with letter
    };
    int state = 0;
    int i = 0;
    while (i < strlen(str)) {
        state = stateTable[state][status(str[i])];
        if (state == -1) {
            break;
        }
        i++;
    }
    return (state == 5);
}

int status(char ch)
{
    if (ch >= 'A' && ch <= 'Z') {
        return 0;
    } else if ((ch >= '0' && ch <= '9') || (ch == '-')) {
        return 1;
    } else if (ch == '.') {
        return 2;
    } else if (ch == '@') {
        return 3;
    } else if (ch == '_' || ch == '%' || ch == '+') {
        return 4;
    } else {
        return 5;
    }

}
