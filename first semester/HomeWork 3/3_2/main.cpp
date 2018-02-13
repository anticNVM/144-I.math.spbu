#include <iostream>
#include <ctime>
#include "mysorts.h"
#include "myfparr.h"
#include "mymath.h"

using namespace std;

int binSearch(int* array, const int size, int value);

int main()
{
    srand(time(NULL));
    cout << "Enter array`s length (n): ";
    int n = 0;
    cin >> n;
    int max = lognExponentiation(10, 9);
    int* nums = fillArr(n, max);

    cout << "Created array: \n";
    printArr(nums, n);
    quickSort(nums, n, 0, n - 1);
    cout << "Sorted array: \n";
    printArr(nums, n);

    cout << "Enter amount of integers (k): ";
    int k = 0;
    cin >> k;

    cout << endl;
    for (int i = 0; i < k; i++) {
        int num = rand() % max;
        int t = binSearch(nums, n, num);
        if (t == -1) {
            cout << "(-)" << num << ":\t" << "NO!  It`s not belong to nums" << endl;
        } else {
            cout << "(+)" << num << ":\t" << "YES! It`s belong to nums" << endl;
        }
    }
    cout << endl;

    delete[] nums;
    return 0;
}

int binSearch(int* array, const int size, int value)
{
    int left = 0;
    int right = (size - 1);
    while (left <= right) {
        int medd = (left + right) / 2;
        if (value < array[medd]) {
            right = medd - 1;
        } else if (value > array[medd]) {
            left = medd + 1;
        } else {
            return medd;
        }
    }
    return -1;
}
