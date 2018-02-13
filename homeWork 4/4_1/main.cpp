#include <iostream>
#include <math.h>

using namespace std;

// рязрядность 2х представления
const int CAPACITY = 32;

// возвращает булевое представление number
bool* representation(int number);

// возвращает сумму а и b в булевом представлении
bool* sumOfRepresentations(bool* a, bool* b);

// печатает в консоль 2х представление number
void outputRepr(int number, bool *repr);

int main()
{
    setlocale(LC_ALL, "rus");

    cout << "Введите 2 числа (a, b) через пробел: ";
    int a = 0;
    int b = 0;
    cin >> a >> b;

    bool* reprA = representation(a);
    bool* reprB = representation(b);
    outputRepr(a, reprA);
    outputRepr(b, reprB);
    bool* sum = sumOfRepresentations(reprA, reprB);
    outputRepr(a + b, sum);
    int sumFromBinToInt = 0;
    for (int i = CAPACITY - 1; i >= 0; --i) {
        if (sum[i]) {
            sumFromBinToInt += pow(2, CAPACITY - i - 1);
        }
    }
    cout << sumFromBinToInt << endl;

    delete[] reprB;
    delete[] reprA;
    delete[] sum;

    return 0;
}

bool* representation(int number)
{
    bool* repr = new bool[CAPACITY]{};
    int bit = 0x80000000;
    for (int i = 0; i < CAPACITY; ++i) {
        repr[i] = (number & bit);
        bit = bit >> 1;
	// it`s a magic, WoW
        bit = bit & 0x7FFFFFFF;	      
    }
    return repr;
}

bool* sumOfRepresentations(bool* a, bool* b)
{
    bool* sum = new bool[CAPACITY]{};
    int buffer = 0;
    for (int i = (CAPACITY - 1); i >= 0; --i) {
        int temp =  a[i] + b[i] + buffer;
        sum[i] = temp % 2;
        buffer = temp / 2;
    }
    return sum;
}

void outputRepr(int number, bool* repr)
{
    cout << "Двоичное представление " << number << ":\t";
    for (int i = 0; i < CAPACITY; ++i) {
        cout << repr[i];
    }
    cout << endl;
}
