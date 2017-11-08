#pragma once

// тип элементов, помещаемых в стек
typedef int TypeElement;

// стек
struct Stack;

// возвращает указатель на новый стек
Stack* createStack();

// удаляет стек
void deleteStack(Stack* stack);

// добавляет элемент стек
void push(TypeElement value, Stack* stack);

// удаляет элемент с вершины и возвращает его значение
// необязательный параметр isSuccessful == true, если элемент найден, иначе false
TypeElement pop(Stack* stack, bool* isSuccessful = nullptr);

// возвращает значение верхнего элемента стека
// необязательный параметр isSuccessful == true, если элемент найден, иначе false
TypeElement top(Stack* stack, bool* isSuccessful = nullptr);

// проверяет стек на пустоту
bool isEmpty(Stack* stack);
