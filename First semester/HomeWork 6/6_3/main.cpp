#include <iostream>
#include "../stackInt/stackInt.h"

using namespace std;

string sortStation(const string& infix);
bool isOperator(char token);
int priorityOfOperator(char operat);


int main()
{
    // add files part
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
            while (!isEmpty(stack) &&
                   priorityOfOperator(top(stack)) > priorityOfOperator(token)) {
                postfix += pop(stack);
            }
            push(token, stack);
        } else if (token == '(') {
            push(token, stack);
        } else if (token == ')') {
            while (top(stack) != '(') {
//                postfix += pop(stack);
            }
            pop(stack);
        } else {
            continue;
        }
    }
    while (!isEmpty(stack)) {
        postfix += pop(stack);
    }
    deleteStack(stack);
    return postfix;
}

bool isOperator(char token)
{
    return (token == '+' || token == '-'|| token == '*'|| token == '/');
}

int priorityOfOperator(char operat)
{
    switch (operat) {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    default:
        return 0;
    }
}
