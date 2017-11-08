#include <iostream>
#include "myfparr.h"
#include "mysorts.h"

using namespace std;

int mostCommon(int* array, const int size);

int main()
{
    cout << "Enter array`s length: ";
    int lenArr = 0;
    cin >> lenArr;
    int* nums = fillArr(lenArr, lenArr);

    cout << "Created array: \n";
    printArr(nums, lenArr);
    quickSort(nums, lenArr, 0, lenArr - 1);
    cout << "Sorted array: \n";
    printArr(nums, lenArr);

    cout << "The most common number in this array is (";
    cout << mostCommon(nums, lenArr) << ")\n\n";

    delete[] nums;
    return 0;
}

int mostCommon(int* array, const int size)
{
    int counter = 1;
    int maxCounter = 1;
    int mostFindNum = array[0];
    for (int i = 0; i < (size - 1); ++i) {
        if (array[i] == array[i + 1]) {
            counter++;
        } else {
            if (counter > maxCounter) {
                maxCounter = counter;
                mostFindNum = array[i];
            }
            counter = 1;
        }
    }
    if (counter > maxCounter) {
        mostFindNum = array[size - 1];
    }
    return mostFindNum;
}
