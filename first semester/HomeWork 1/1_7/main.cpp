#include <stdio.h>

int main()
{
    int n = 0;
    printf("Enter N: ");
    scanf("%d", &n);

    int *nums = new int[n + 1] {};
    for (int i = 0; i <= n; ++i) {
        nums[i] = 1;
    }
    nums[0] = 0;
    nums[1] = 0;

    for (int i = 2; i <= n; ++i) {
        if (nums[i] == 1) {
            for (int j = (2 * i); j <= n; j += i) {
                nums[j] = 0;
            }
        }
    }

    printf("Primes (2:%d): \n", n);
    for (int i = 0; i <= n; ++i) {
        if (nums[i] == 1)
            printf("%d ", i);
    }
    printf("\n\n");

    delete[] nums;
    return 0;
}

