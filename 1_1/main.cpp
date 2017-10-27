#include <stdio.h>

int main()
{
    int x = 0;
    printf("Enter X: ");
    scanf("%d", &x);

    long dx = x*x;
    long product = dx*(dx+x)+x+1;

    printf("X = %d: x^4+x^3+x^2+x+1 = %li\n\n", x, product);

    return 0;
}

