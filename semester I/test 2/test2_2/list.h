#ifndef SORTEDLIST
#define SORTEDLIST

// тип значения, добавляемого в список
typedef int TypeElement;

// список
struct List;

// возвращает указатель на новый список
List* createList();

// очищает список (удаляте все элементы списка)
void clearList(List* list);

// удаляет список
void deleteList(List* list);

// добавляет элемент в список по индексу
void push(TypeElement value, List* list, int index = -1);

// удаляет элемент из list по индексу
// если индекс не найден, то возвращает -1, иначе 0
int remove(List* list, int index);

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

// печатает в консоль все значения списка через пробел
void printList(List* list);

//void test();

#endif // SORTEDLIST

