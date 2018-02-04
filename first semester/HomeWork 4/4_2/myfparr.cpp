#include <iostream>
#include <ctime>
#include "myfparr.h"

int* fillArr(const int size, const int maxRand)
{
    srand(time(NULL));
    int* array = new int[size];
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % maxRand;
    }
    return array;
}

void printArr(int* array, const int size)
{
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}
