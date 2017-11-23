#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    int a = 0;
    fin >> a;
    cout << "Hello World!   " << a << endl;
    return 0;
}

