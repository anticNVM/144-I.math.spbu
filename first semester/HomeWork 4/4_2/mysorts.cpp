#include <iostream>
#include "mysorts.h"

int separation(int* array, int left , int right);

void quickSort(int* array, const int size, int left, int right)
{
    if (size == 1 || size == 0) {
        return;
    }
    else if (size == 2 && array[0] > array[1]) {
        std::swap(array[0], array[1]);
    }
    else if (size < 10) {
        insertionSort(array, size, left);
        return;
    }
    else {
        int pointer = separation(array, left, right);
        quickSort(array, pointer - left, left, pointer - 1);
        quickSort(array, right - pointer, pointer + 1, right);
    }
}
int separation(int* array, int left , int right)
{
    int leftPtr = left;
    int rightPtr = right;

    while (leftPtr < rightPtr) {
        if (array[leftPtr] < array[rightPtr]) {
            leftPtr++;
        }
        else {
            std::swap(array[leftPtr], array[rightPtr]);
            rightPtr--;
            while (leftPtr < rightPtr) {
                if (array[rightPtr] >= array[leftPtr]) {
                    rightPtr--;
                }
                else {
                    std::swap(array[leftPtr], array[rightPtr]);
                    leftPtr++;
                    break;
                }
            }
        }
    }
    return leftPtr;
}

void insertionSort(int array[], const int size, int left)
{
    for (int i = left + 1; i < left + size; ++i) {
        int j = i;
        while (j > 0 && array[j] < array[j - 1]) {
            std::swap(array[j], array[j - 1]);
            j--;
        }
    }
}
