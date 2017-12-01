#ifndef LIST_H
#define LIST_H

// тип значения, добавляемого в список
typedef int TypeElement;

// список
struct List;

// возвращает указатель на новый список
List* createList();

// очищает список (удаляте все элементы списка)
void clearList(List* list);

// удаляет список
void deleteList(List*& list);

// добавляет элемент в список по индексу
// (по умолчанию в конец списка)
void add(TypeElement value, List* list, int index = -1);

// удаляет элемент из list по индексу
// (по умочанию с конца списка)
// если индекс не найден, то возвращает -1, иначе 0
int pop(List* list, int index = -1);

// возвращает значение элемента в списке по индексу, но не удаляет его
// если индекс не найден, то возвращает -1
TypeElement getValue(List* list, int index);

// возвращает индекс первого вхождения value в lst
// если значение не найдено, возвращает -1
int getIndex(TypeElement value, List* list);

// возвращает размер списка
int getSize(List* list);

// проверяет, пуcт ли список
bool isEmpty(List* list);

// разворачивает список
void reverse(List*& list);

// печатает в консоль все значения списка через пробел
void printList(List* list);

#endif // LIST_H

