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
TypeElement pop(Stack* stack);

// возвращает значение верхнего элемента стека
TypeElement top(Stack* stack);

// проверяет стек на пустоту
bool isEmpty(Stack* stack);
