#include <iostream>
#include <string>
#include "../stack/stack.h"
using namespace std;

// возвращает значение выражения в постфиксной записи
int calculatePostfix(const string& expression);

// проверяет, является ли символ числом
bool isDigit(char symbol);

// возвращает результат бинарной операции (+-*/)
int calculateBinary(int leftOperand, int rightOperand, char operation);

// принимает строку из консоли и сохраняет ее в expression
void inputExpression(string& expression);

int main()
{
    cout << "Enter an expression: \n";
    string expression = "";
    inputExpression(expression);
    int result = calculatePostfix(expression);
    cout << "Result is " << result << endl;
    return 0;
}

void inputExpression(string& expression)
{
    getline(cin, expression);
}

int calculatePostfix(const string& expression)
{
    Stack* stack = createStack();
    for (auto symbol : expression) {
        if (isDigit(symbol)) {
            int digit = symbol - '0';
            push(digit, stack);
        } else if (symbol != ' '){
            int right = 0;
            pop(stack, right);
            int left = 0;
            pop(stack, left);
            int value = calculateBinary(left, right, symbol);
            push(value, stack);
        }
    }
    int result = 0;
    top(stack, result);

    deleteStack(stack);
    return result;
}

bool isDigit(char symbol)
{
    return (int(symbol) >= 48 && int(symbol) <= 57);    // 0 - 9
}

int calculateBinary(int leftOperand, int rightOperand, char operation)
{
    int result = 0;
    switch (operation) {
    case '+':
        result = leftOperand + rightOperand;
        break;
    case '-':
        result = leftOperand - rightOperand;
        break;
    case '*':
        result = leftOperand * rightOperand;
        break;
    case '/':
        result = leftOperand / rightOperand;
        break;
    default:
        break;
    }
    return result;
}
