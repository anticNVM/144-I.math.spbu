#include <iostream>
#include "stackInt.h"

using namespace std;

void stackTest() {
    Stack* stack = createStack();
    push(5, stack);
    push(9, stack);
    TypeElement elem = pop(stack);
    cout << elem << endl;
    cout << "isEmpty: " << isEmpty(stack) << endl;
    cout << top(stack) << endl;
    bool flag = true;
    cout << pop(stack, &flag) << " flag = " << flag << endl;
    // flag = 1 тк << ,видимо, правоассоциированная операция
    cout << top(stack, &flag) << " flag = " << flag << endl;
    cout << "flag = " << flag << endl;
    cout << "isEmpty: " << isEmpty(stack) << endl;
    cout << "OK\n";
    deleteStack(stack);
}

int main()
{
    // test
    stackTest();
    return 0;
}
