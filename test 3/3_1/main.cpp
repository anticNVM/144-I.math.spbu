#include <iostream>
#include <math.h>

using namespace std;

int sumOfDigits(int number);

int main()
{
    int size = 0;
    cout << "Please, enter array`s size: ";
    cin >> size;
    int* numbers = new int[size]{};
    int* sumsOfDigits = new int[size]{};
    int maxSum = 0;
    cout << "Please, enter numbers to array: \n";
    for (int i = 0; i < size; ++i) {
        cin >> numbers[i];
        sumsOfDigits[i] = sumOfDigits(numbers[i]);
        if (sumsOfDigits[i] > maxSum) {
            maxSum = sumsOfDigits[i];
        }
    }
    cout << "\nNumbers with maximal sum of digits: \n";
    for (int i = 0; i < size; ++i) {
        if (sumsOfDigits[i] == maxSum) {
            cout << numbers[i] << endl;
        }
    }
    delete[] sumsOfDigits;
    delete[] numbers;
    return 0;
}

int sumOfDigits(int number)
{
    int sum = 0;
    number = abs(number);
    while (number > 0) {
        sum += (number % 10);
        number /= 10;
    }
    return sum;
}
