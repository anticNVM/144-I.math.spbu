#include <iostream>
#include <stdio.h>
#include "myfparr.h"
#include "mysorts.h"

using namespace std;

int mostCommon(int* array, const int size);

int main()
{
    int lenArr = 100;
    int nums[lenArr] = {};
    char file[20] = "input.txt";

    FILE *input = fopen(file, "r");
    if (input != nullptr) {
        cout << file << " is successfully opened!" << endl;
        int amountOfNums = 0;
        while (!feof(input)) {
            fscanf(input, "%d", &nums[amountOfNums]);;
            amountOfNums++;
        }
        cout << "The most common number in file is (";
        cout << mostCommon(nums, amountOfNums - 1) << ")\n\n";
        fclose(input);
    } else {
        cout << "ERROR:  File not opened" << endl;
    }

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
