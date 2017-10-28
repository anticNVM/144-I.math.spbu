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

// вставляет новый элемент списка за текщим
void insert(int value, CycleListElement* current, CycleList *cycle);

// удаляет текущий элемент списка
void remove(CycleListElement* current, CycleList *cycle);

// возвращает значение текущего элемента списка
int getValue(CycleListElement* current);

// возвращает указатель на элемент, следующий за текущим через step
CycleListElement* moveSeveralTimes(CycleListElement* current, int step);

// возвращает размер списка
int getSize(CycleList* cycle);

#endif // CYCLELIST

