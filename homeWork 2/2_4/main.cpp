#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void mySort(int* array, const int size);
int* fillArray(const int size);
void printArray(int* array, const int size);

int main()
{
    cout << "Enter array`s length: ";
    int lenArr = 0;
    cin >> lenArr;
    int* nums = fillArray(lenArr);

    cout << "Unsorted array: \n";
    printArray(nums, lenArr);

    mySort(nums, lenArr);

    cout << "Sorted array: \n";
    printArray(nums, lenArr);

    delete[] nums;
    return 0;
}

void mySort(int* array, const int size)
{
    int base = array[0];
    int leftPtr = 1;
    int rightPtr = size - 1;

    while (leftPtr < rightPtr) {
        if (array[leftPtr] < base) {
            leftPtr++;
        }
        else {
            while (leftPtr < rightPtr) {
                if (array[rightPtr] >= base) {
                    rightPtr--;
                } else {
                    swap(array[leftPtr], array[rightPtr]);
                    rightPtr--;
                    leftPtr++;
                    break;
                }
            }
        }
    }
}

int* fillArray(const int size)
{
    srand(time(nullptr));
    int* array = new int[size] {};
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % (size * 2);
    }
    return array;
}

void printArray(int* array, const int size)
{
    for (int i = 0; i < size; ++i) {
        cout << array[i] << ' ';
    }
    cout << endl;
}
