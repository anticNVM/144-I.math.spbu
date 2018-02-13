#include <iostream>
using namespace std;

void bubbleSort(int array[], const int size);
void countingSort(int array[], const int size);
int minInArray(int array[], const int size);
int maxInArray(int array[], const int size);

int main()
{
    cout << "Enter array`s size: ";
    int size = 0;
    cin >> size;
    int *array = new int[size] {};
    cout << "Enter a numbers in array through space: ";
    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }

    char choice = '0';
    bool flag = true;
    do {
        flag = true;
        cout << "Choose - bubble sort or counting sort. \nEnter (b or c): ";
        cin >> choice;
        switch (choice) {
            case 'b':
                bubbleSort(array, size);
                break;
            case 'c':
                countingSort(array, size);
                break;
            default:
                cout << "ERROR: Wrong input. Please, try again.\n\n";
                flag = false;
                break;
        }
    } while (!flag);

    cout << "Sorted array: \n";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << ' ';
    }
    cout << endl;

    delete[] array;
    return 0;
}

void bubbleSort(int array[], const int size)
{
    bool exit = false;
    while (!exit) {
        exit = true;
        for (int i = 1; i < size; ++i) {
            if (array[i] < array[i - 1]) {
                swap(array[i], array[i - 1]);
                exit = false;
            }
        }
    }
}

void countingSort(int array[], const int size)
{
    int min = minInArray(array, size);
    int max = maxInArray(array, size);

    int *diapason = new int[max - min + 1] {};
    for (int i = 0; i < size; ++i) {
        diapason[array[i] - min]++;
    }
    int k = 0;
    for (int i = min; i < (max + 1); ++i) {
        while (diapason[i - min] != 0) {
            array[k] = i;
            k++;
            diapason[i - min]--;
        }
    }
    delete[] diapason;
}

int minInArray(int array[], const int size)
{
    int min = array[0];
    for (int i = 0; i < size; ++i) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

int maxInArray(int array[], const int size)
{
    int max = array[0];
    for (int i = 0; i < size; ++i) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}
