#include <stdio.h>

int main()
{
    int sums[28]{};
    int count = 0;

    for (int i = 0; i <= 9; ++i)
        for (int j = 0; j <= 9; ++j)
            for (int k = 0; k <= 9; ++k)
                sums[i+j+k]++;

    for (int i = 0; i < 28; ++i)
        count += (sums[i]*sums[i]);

    printf("Lucky tickets: %d \n", count);

    return 0;
}
