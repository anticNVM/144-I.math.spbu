#include "queue.h"
#include <assert.h>
#include <limits.h>

const int MIN_PRIORITY = INT_MIN;

struct QueElement {
    TypeElement value;
    int priority;
    QueElement* next;
};

struct Queue {
    QueElement* begin;
    QueElement* end;
    int size;
    int maxPriority;
};

Queue* create()
{
    return new Queue{nullptr, nullptr, 0, MIN_PRIORITY};
}

void deleteQue(Queue* que)
{
    if (que->size != 0) {
        while (que->begin != nullptr) {
            QueElement* temp = que->begin;
            que->begin = temp->next;
            delete temp;
        }
    }
    delete que;
}

void addFirst(Queue *que, TypeElement value, int priority)
{
    QueElement* newElem = new QueElement{value, priority, nullptr};
    que->begin = newElem;
    que->end = newElem;
    que->maxPriority = priority;
    que->size++;
}

void enqueue(Queue *que, TypeElement value, int priority)
{
    if (que->size == 0) {
        addFirst(que, value, priority);
        return;
    }
    QueElement* newElem = new QueElement{value, priority, nullptr};
    que->end->next = newElem;
    que->end = newElem;
    if (priority > que->maxPriority) {
        que->maxPriority = priority;
    }
    que->size++;
}

void updateMaxPriority(Queue* que)
{
    assert(que->begin != nullptr);
    QueElement* current = que->begin;
    que->maxPriority = MIN_PRIORITY;
    while (current->next != nullptr) {
        if (current->priority > que->maxPriority) {
            que->maxPriority = current->priority;
        }
    }
}

TypeElement dequeue(Queue *que)
{
    if (que->size == 0) {
        return 0;
    }
    if (que->begin == que->end) {
        QueElement* temp = que->begin;
        que->begin = nullptr;
        que->end = nullptr;
        TypeElement buff = temp->value;
        delete temp;
        que->size--;
        return buff;

    }
    if (que->begin->priority == que->maxPriority) {
        QueElement* temp = que->begin;
        que->begin = que->begin->next;
        TypeElement buff = temp->value;
        delete temp;
        que->size--;
        updateMaxPriority(que);
        return buff;
    }
    QueElement* current = que->begin->next;
    QueElement* prev = que->begin;
    while (current->priority != que->maxPriority) {
        prev = current;
        current = current->next;
    }
    if (que->end == current) {
        TypeElement buff = current->value;
        prev->next = nullptr;
        delete que->end;
        que->end = prev;
        que->size--;
        updateMaxPriority(que);
        return buff;
    }
    prev->next = current->next;
    TypeElement buff = current->value;
    delete current;
    que->size--;
    updateMaxPriority(que);
    return buff;
}
