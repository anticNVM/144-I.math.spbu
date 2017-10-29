#include "cyclelist.h"
#include <iostream>

using namespace std;

struct CycleListElement {
    int value;
    CycleListElement* next;
};

struct CycleList {
    CycleListElement* head;
    int size;
};

CycleList* createCycle()
{
    return new CycleList{nullptr, 0};
}

void deleteCycle(CycleList* cycle)
{
    while (cycle->size) {
        remove(cycle->head, cycle);
        (cycle->size)--;
    }
    delete cycle;
}

void addFirst(int value, CycleList* cycle)
{
    CycleListElement* newElement = new CycleListElement{value, nullptr};
    newElement->next = newElement;
    cycle->head = newElement;
    (cycle->size)++;
}

void insert(int value, CycleListElement* current, CycleList* cycle)
{
    CycleListElement* tempNext = current->next;
    CycleListElement* newElement = new CycleListElement{value, tempNext};
    current->next = newElement;
    (cycle->size)++;
}

void remove(CycleListElement* current, CycleList* cycle)
{

    CycleListElement* previous = moveSeveralTimes(current, cycle->size - 1);
    previous->next = current->next;
    if (cycle->head == current) {
        cycle->head = current->next;
    }
    delete current;
    (cycle->size)--;
}

int getValue(CycleListElement* current)
{
    return current->value;
}

CycleListElement* next(CycleListElement* current)
{
    return current->next;
}

CycleListElement* moveSeveralTimes(CycleListElement* current, int step)
{
    CycleListElement* newCurrent = current;
    for (int i = 0; i < step; ++i) {
        newCurrent = next(newCurrent);
    }
    return newCurrent;
}

CycleListElement* getFirst(CycleList* cycle)
{
    return cycle->head;
}

void printCycle(CycleList *cycle)
{
    CycleListElement* current = cycle->head;
    for (int i = 0; i < cycle->size; ++i) {
        cout << current->value << ' ';
        current = next(current);
    }
    cout << endl;
}

int getSize(CycleList* cycle)
{
    return cycle->size;
}

