#include <iostream>

using namespace std;

int status(char ch)
{
    if (isalpha(ch)) {
        return 0;
    } else if (isdigit(ch) || ch == '_') {
        return 1;
    } else {
        return 2;
    }
}

int main()
{
    int table[3][3] = {
        {1, -1, -1},
        {2,  2, -1},
        {2,  2, -1}
    };
    string str = "a";
    int state = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (table[state][status(str[i])] == -1)
            break;

        state = table[state][status(str[i])];
        i++;
    }
    if (state != 2) {
        cout << ":(" << endl;
    } else {
        cout << "It`s OK!" << endl;
    }
    return 0;
}

