#include "cyclelist.h"

struct CycleListElement {
    int value;
    CycleListElement* previous;
    CycleListElement* next;
};

struct CycleList {
    CycleListElement* begin;
};

CycleList* createCycle()
{
    return new CycleList{nullptr};
}

void deleteCycle(CycleList* cycle)
{
    int length = lengthCycle(cycle);
    while (length) {
        pop(cycle->begin);
        length--;
    }
    delete cycle;
}

void insertFirst(int value, CycleList* cycle)
{
    CycleListElement* newElement = new CycleListElement{value, newElement, newElement};
    cycle->begin = newElement;
}

void insert(int value, CycleListElement* prev)
{
    CycleListElement* tempNext = prev->next;
    CycleListElement* tempPrev = prev->next->previous;
    CycleListElement* newElement = new CycleListElement{value, tempPrev, tempNext};
    prev->next = newElement;
    prev->next->previous = newElement;
}

int pop(CycleListElement* current)
{
    int value = current->value;
    current->previous->next = current->next;
    current->next->previous = current->previous;
    delete current;
    return value;
}

int getValue(CycleListElement* current)
{
    return current->value;
}

CycleListElement* next(CycleListElement* current)
{
    return current->next;
}

CycleListElement* previous(CycleListElement* current)
{
    return current->previous;
}

int lengthCycle(CycleList* cycle)
{
    CycleListElement* current = cycle->begin;
    int length = 0;
    if (current) {
        length++;
        while (current->next != cycle->begin) {
            length++;
            current = current->next;
        }
    }
    return length;
}

CycleListElement* getFirst(CycleList* cycle)
{
    return cycle->begin;
}
