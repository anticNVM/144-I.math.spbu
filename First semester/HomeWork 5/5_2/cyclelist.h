#ifndef CYCLELIST
#define CYCLELIST

struct CycleList;

struct Iterator;

// создает циклический список
CycleList* createCycle();

// удаляет список
void deleteCycle(CycleList* cycle);

// добавляет первый элемент в список
void addFirst(int value, CycleList* cycle);

// вставляет одиночный элемент index в список cycle сразу после previous
void insert(int value, Iterator* previous);

// удаляет элемент, на который указывает current
void remove(Iterator* current);

// получает значение элемента по итератору
int getValue(Iterator* current);
CycleListElement* next(CycleListElement* current);
CycleListElement* previous(CycleListElement* current);
int lengthCycle(CycleList* cycle);
CycleListElement* getFirst(CycleList* cycle);

#endif // CYCLELIST

