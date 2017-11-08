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

void addFirst(int value, CycleList* cycle)
{
    CycleListElement* newElement = new CycleListElement{value, newElement, newElement};
    cycle->begin = newElement;
}

void insert(int value, Iterator* previous)
{
    CycleListElement* tempNext = index->next;
    CycleListElement* tempPrev = index->next->previous;
    CycleListElement* newElement = new CycleListElement{value, tempPrev, tempNext};
    index->next = newElement;
    index->next->previous = newElement;
}

void remove(Iterator *current)
{
    int value = cycle->value;
    cycle->previous->next = cycle->next;
    cycle->next->previous = cycle->previous;
    delete cycle;
    return value;
}

int getValue(Iterator *current)
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
