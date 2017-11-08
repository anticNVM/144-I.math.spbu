#include <iostream>
#include "../stackInt/stackInt.h"

using namespace std;

/**
    Программа проверяет баланс скобок в строке
**/

// сохраняет введенную из консоли последовательность в brackets
void inputSequence(string& brackets);

// проверяет, является ли скобка открывающей
bool isOpeningBracket(char bracket);

// проверяет, являются ли скобки парой
bool isPair(char opening, char close);

// проверяет сбалансированность скобочной последовательности
bool checkBrackets(const string& brackets);

int main()
{
    string brackets = "";
    cout << "Enter a bracket sequence for checking: \n";
    inputSequence(brackets);
    bool isBalanced = checkBrackets(brackets);
    cout << isBalanced << endl;
    return 0;
}

bool checkBrackets(const string& brackets)
{
    Stack* stack = createStack();
    bool isBalanced = true;
    for (auto bracket : brackets) {
        if (isOpeningBracket(bracket)) {
            push(bracket, stack);
        } else {
            bool flag = true;
            TypeElement topBracket = top(stack, &flag);
            if (flag && isPair(topBracket, bracket)) {
                pop(stack);
            } else {
                isBalanced = false;
                break;
            }
        }
    }
    if (!isEmpty(stack)) {
        isBalanced = false;
    }
    deleteStack(stack);
    return isBalanced;
}

void inputSequence(string& brackets)
{
    getline(cin, brackets);
}

bool isOpeningBracket(char bracket)
{
    return (bracket == '(' || bracket == '{' || bracket == '[');
}

bool isPair(char opening, char close)
{
    switch (opening) {
    case '(':
        return close == ')';
    case '{':
        return close == '}';
    case '[':
        return close == ']';
    default:
        return false;
    }
}
