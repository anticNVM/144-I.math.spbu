#include <iostream>
#include "../stack/stack.h"

using namespace std;

string sortStation(string& infix);

int main()
{
    string infix = "4";
    sortStation(infix);
    return 0;
}

string sortStation(string& infix)
{
    string postfix = "";
    Stack* stack = createStack();
    for (auto token : infix) {
        if (isdigit(token)) {
            postfix += token;
        }
    }
    deleteStack(stack);
    return postfix;
}
