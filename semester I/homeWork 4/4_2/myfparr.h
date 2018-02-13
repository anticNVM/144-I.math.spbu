#ifndef MYFPARR_H
#define MYFPARR_H

// Функция создает массив целых чисел размера size,
// и заполняет его случайными числами от 0 до maxRand
int* fillArr(const int size, const int maxRand = 40);

// Функция выводит в консоль элементы массива через пробел
void printArr(int* array, const int size);

#endif // MYFPARR_H

