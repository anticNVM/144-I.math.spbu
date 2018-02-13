#include <iostream>
#include <fstream>
#include "../stackInt/stackInt.h"

using namespace std;

string sortStation(const string& infix);
bool isOperator(char token);
int priorityOfOperator(char operation);

int main()
{
    ifstream fin("testData.in.txt");
    ofstream fout("testData.out.txt");
    string expression;
    while (getline(fin, expression)) {
        fout << sortStation(expression) << endl;
    }
    fin.close();
    fout.close();

    return 0;
}

string sortStation(const string& infix)
{
    string postfix = "";
    Stack* stack = createStack();
    for (auto token : infix) {
        if (isdigit(token) || isalpha(token)) {
            postfix += token;
            postfix += ' ';
        } else if (isOperator(token)) {
            while (!isEmpty(stack) &&
                   priorityOfOperator(token) <= priorityOfOperator(top(stack))) {
                postfix += pop(stack);
                postfix += ' ';
            }
            push(token, stack);
        } else if (token == '(') {
            push(token, stack);
        } else if (token == ')') {
            while (top(stack) != '(') {
                postfix += pop(stack);
                postfix += ' ';
            }
            pop(stack);
        } else {
            continue;
        }
    }
    while (!isEmpty(stack)) {
        postfix += pop(stack);
        postfix += ' ';
    }
    deleteStack(stack);
    return postfix;
}

bool isOperator(char token)
{
    return (token == '+' || token == '-' || token == '*' || token == '/');
}

int priorityOfOperator(char operation)
{
    switch (operation) {
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

