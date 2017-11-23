#include <stdio.h>
#include <math.h>
#include <cmath>

int main()
{
    int a = 0;          // Р”РµР»РёРјРѕРµ
    int b = 0;          // Р”РµР»РёС‚РµР»СЊ
    int k = 0;          // Р§Р°СЃС‚РЅРѕРµ
    printf("Enter A(dividend): ");
    scanf("%d", &a);
    printf("Enter B(divider): ");
    scanf("%d", &b);

    if ((a >= 0 && b > 0) || (a <= 0 && b < 0)) {
        a = std::abs(a);
        b = std::abs(b);
        while (a >= b) {
            a = a - b;
            k++;
        }
    }
    else if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
        a = (-1) * std::abs(a);
        b = std::abs(b);
        while (a < 0) {
            a = a + b;
            k++;
        }
        k = k * (-1);
    }
    printf("Quotient is (%d)\n\n", k);

    return 0;
}
