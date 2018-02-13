#ifndef CYCLELIST
#define CYCLELIST

// элемент циклического списка
struct CycleListElement;

// циклический список
struct CycleList;

// создает циклический список
CycleList* createCycle();

// удаляет циклический список
void deleteCycle(CycleList* cycle);

// добавляет первый элемент в список
void addFirst(int value, CycleList* cycle);

// вставляет новый элемент списка за текущим
void insert(int value, CycleListElement* current, CycleList *cycle);

// удаляет текущий элемент списка
void remove(CycleListElement* current, CycleList *cycle);

// возвращает значение текущего элемента списка
int getValue(CycleListElement* current);

// возвращает указатель на элемент, следующий за текущим
CycleListElement* next(CycleListElement* current);

// возвращает указатель на предыдущий элемент
CycleListElement* previous(CycleListElement* current);

// возвращает указатель на элемент, следующий за текущим через step
CycleListElement* moveNext(CycleListElement* current, int step);

// возвращает указатель на 1 элемент списка
CycleListElement* getFirst(CycleList* cycle);

// возвращает размер списка
int getSize(CycleList* cycle);

// выводит значения элементов списка в консоль через пробел
void printCycle(CycleList* cycle);

#endif // CYCLELIST

