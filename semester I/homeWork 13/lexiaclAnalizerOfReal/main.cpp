#include <iostream>
#include <lexicalanalizer.h>

using namespace std;

int main()
{
    char str[] = "12.23";
    cout << stateMachine(str) << endl;
    return 0;
}

