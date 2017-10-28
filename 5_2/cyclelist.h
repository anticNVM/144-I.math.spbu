#ifndef CYCLELIST
#define CYCLELIST

struct CycleListElement;
struct CycleList;

CycleList* createCycle();
void deleteCycle(CycleList* cycle);
void insertFirst(int value, CycleList* cycle);
void insert(int value, CycleListElement* prev);
int pop(CycleListElement* current);
int getValue(CycleListElement* current);
CycleListElement* next(CycleListElement* current);
CycleListElement* previous(CycleListElement* current);
int lengthCycle(CycleList* cycle);
CycleListElement* getFirst(CycleList* cycle);

#endif // CYCLELIST

