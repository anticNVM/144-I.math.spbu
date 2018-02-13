#include "mymath.h"

int lognExponentiation(int a, int n)
{
    if (n == 0) {
        return 1;
    } else if (n % 2 == 1) {
        return lognExponentiation(a, n-1) * a;
    } else {
        int t = lognExponentiation(a, n/2);
        return t * t;
    }
}

