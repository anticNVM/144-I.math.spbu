#include <iostream>
using namespace std;

int fibonacciRecursively(int n);
int fibonacciIteratively(int n);

int main()
{
    cout << "Enter # of the fibonacci numbers: ";
    int n = 0;
    cin >> n;
    cout << "F(" << n << ") = " << fibonacciIteratively(n) << endl;
    return 0;
}

int fibonacciRecursively(int n)
{
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    return fibonacciRecursively(n - 1) + fibonacciRecursively(n - 2);
}

int fibonacciIteratively(int n)
{
    int fibNums[2] = {};
    fibNums[0] = 0;
    fibNums[1] = 1;

    for (int i = 0; i < (n - 1); ++i) {
        int temp = 0;
        temp = fibNums[0] + fibNums[1];
        fibNums[0] = fibNums[1];
        fibNums[1] = temp;
    }
    return fibNums[1];
}
