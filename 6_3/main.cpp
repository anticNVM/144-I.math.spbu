#include <iostream>
#include "charStack.h"

using namespace std;

string sortStation(const string& infix);
bool isOperator(char token);
int priorityOfOperator(char operat);


int main()
{
    string infix = "4";
    sortStation(infix);
    return 0;
}

string sortStation(const string& infix)
{
    string postfix = "";
    Stack* stack = createStack();
    for (auto token : infix) {
        if (isdigit(token)) {
            postfix += token;
        } else if (isOperator(token)) {
            while (!isEmpty(stack) && priorityOfOperator(top)) {

            }
        }
    }
    deleteStack(stack);
    return postfix;
}
