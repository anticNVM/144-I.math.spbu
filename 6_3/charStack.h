#pragma once

// тип элементов, помещаемых в стек
typedef char TypeElement;

// стек
struct Stack;

// возвращает указатель на новый стек
Stack* createStack();

// удаляет стек
void deleteStack(Stack* stack);

// добавляет элемент стек
void push(TypeElement value, Stack* stack);

// удаляет элемент с вершины и сохраняет его значение в value
// возвращает false, если элемент не найден, иначе true
bool pop(Stack* stack, TypeElement& value);

// сохраняет значение верхнего в value
// возвращает false, если элемент не найден, иначе true
bool top(Stack* stack, TypeElement& value);

// проверяет стек на пустоту
bool isEmpty(Stack* stack);
