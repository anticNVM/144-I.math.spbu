#include <iostream>
using namespace std;

int simply_exponentiation(int a, int n);
int logn_exponentiation(int a, int n);

int main()
{
    cout << "Enter the foundation of degree: ";
    int a = 0;
    cin >> a;
    cout << "Enter the exponent: ";
    int n = 0;
    cin >> n;
    cout << "[n]: \t" << a << "^" << n << " = " << simply_exponentiation(a, n) << endl;
    cout << "[logn]: " << a << "^" << n << " = " << logn_exponentiation(a, n) << endl;
    return 0;
}

int simply_exponentiation(int a, int n)
{
    if (n == 1) {
        return a;
    }
    return a * simply_exponentiation(a, n-1);
}
int logn_exponentiation(int a, int n)
{
    if (n == 0) {
        return 1;
    } else if (n % 2 == 1) {
        return logn_exponentiation(a, n-1) * a;
    } else {
        int t = logn_exponentiation(a, n/2);
        return t*t;
    }
}


