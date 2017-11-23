#include <iostream>
using namespace std;

void reverseArray(int* array, const int size);
int lengthArrayInput(char c);
int* userFillArray(int lenArr, char c);
int* joinArray(int* arrN, const int n, int* arrM, const int m);
void printArray(int* arr, const int size);

int main()
{
    int n = lengthArrayInput('N');
    int* arrN = userFillArray(n, 'N');
    int m = lengthArrayInput('M');
    int* arrM = userFillArray(m, 'M');

    reverseArray(arrN, n);
    reverseArray(arrM, m);

    int* arrNM = joinArray(arrN, n, arrM, m);
    reverseArray(arrNM, n + m);

    delete[] arrN;
    delete[] arrM;

    cout << "Changed array: \n";
    printArray(arrNM, n + m);
    cout << endl;

    delete[] arrNM;
    return 0;
}

void reverseArray(int* array, const int size)
{
    for (int i = 0; i < (size / 2); ++i) {
        array[i] = array[i] ^ array[size - 1 - i];
        array[size - 1 - i] = array[i] ^ array[size - 1 - i];
        array[i] = array[i] ^ array[size - 1 - i];
    }
}
int lengthArrayInput(char c)
{
    cout << "Enter " << c << ": ";
    int lenArr = 0;
    cin >> lenArr;
    return lenArr;
}
int* userFillArray(int lenArr, char c)
{
    int* array = new int[lenArr];
    cout << "Enter first " << c << " numbers in array through space: ";
    for (int i = 0; i < lenArr; ++i) {
        cin >> array[i];
    }
    return array;
}
int* joinArray(int* arrN, const int n, int* arrM, const int m)
{
    int* arrNM = new int[n + m];
    for (int i = 0; i < n; ++i) {
        arrNM[i] = arrN[i];
    }
    for (int i = 0; i < m; ++i) {
        arrNM[n + i] = arrM[i];
    }
    return arrNM;
}
void printArray(int* arr, const int size)
{
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << ' ';
    }
}
