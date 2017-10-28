#ifndef SORTEDLIST
#define SORTEDLIST

// тип значения, добавляемого в список
typedef int TypeElement;

// сортированный список
struct SortedList;

// возвращает указатель на новый список
SortedList* createList();

// очищает список (удаляте все элементы списка)
void clearList(SortedList* list);

// удаляет список
void deleteList(SortedList* list);

// добавляет элемент в список в соответствии со значеним
void push(TypeElement value, SortedList* list);

// удаляет элемент из list по индексу
// если индекс не найден, то возвращает -1, иначе 0
int remove(SortedList* list, int index);

// возвращает значение элемента в списке по индексу, но не удаляет его
// если индекс не найден, то возвращает -1
TypeElement getValue(SortedList* list, int index);

// возвращает индекс первого вхождения value в lst
// если значение не найдено, возвращает -1
int getIndex(TypeElement value, SortedList* list);

// возвращает размер списка
int getSize(SortedList* list);

// проверяет, пуcт ли список
bool isEmpty(SortedList* list);

// печатает в консоль все значения списка через пробел
void printList(SortedList* list);

//void test();

#endif // SORTEDLIST

