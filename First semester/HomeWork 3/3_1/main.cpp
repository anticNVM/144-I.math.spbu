#include <iostream>
#include <time.h>

using namespace std;

void quickSort(int* array, int left, int right);
int separation(int* array, int left, int right);
void insertionSort(int* array, const int size, int left);
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

    quickSort(nums, 0, lenArr - 1);

    cout << "Sorted array: \n";
    printArray(nums, lenArr);

    delete[] nums;
    return 0;
}

void quickSort(int* array, int left, int right)
{
    int size = (right - left + 1);

    if (size == 1 || size == 0) {
        return;
    } else if (size == 2 && array[0] > array[1]) {
        swap(array[0], array[1]);
    } else if (size < 10) {
        insertionSort(array, size, left);
        return;
    } else {
        int pointer = separation(array, left, right);
        quickSort(array, left, (pointer - 1));
        quickSort(array, (pointer + 1), right);
    }
}

int separation(int* array, int left, int right)
{
    int leftPtr = left;
    int rightPtr = right;

    while (leftPtr < rightPtr) {
        if (array[leftPtr] < array[rightPtr]) {
            leftPtr++;
        }
        else {
            swap(array[leftPtr], array[rightPtr]);
            rightPtr--;
            while (leftPtr < rightPtr) {
                if (array[rightPtr] >= array[leftPtr]) {
                    rightPtr--;
                }
                else {
                    swap(array[leftPtr], array[rightPtr]);
                    leftPtr++;
                    break;
                }
            }
        }
    }
    return leftPtr;
}

void insertionSort(int* array, const int size, int left)
{
    for (int i = (left + 1); i < (left + size); ++i) {
        int j = i;
        while (j > 0 && array[j] < array[j - 1]) {
            swap(array[j], array[j - 1]);
            j--;
        }
    }
}

int* fillArray(const int size)
{
    srand(time(nullptr));
    int* array = new int[size] {};
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % (size * 3);
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
