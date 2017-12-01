#include "list.h"
#include <iostream>
#include <assert.h>

using namespace std;

struct ListElement {
    TypeElement value;
    ListElement* next;
};

struct Iterator {
    ListElement* current;
    int index;
};

struct List {
    ListElement* sentinel;
    Iterator* iter;
    int size;
};

ListElement* & getCurrent(List* list)
{
    return list->iter->current;
}

void next(List* list)
{
    assert(getCurrent(list)->next != nullptr);
    getCurrent(list) = getCurrent(list)->next;
    (list->iter->index)++;
}

void begin(List* list)
{
    // -1
    getCurrent(list) = list->sentinel;
    list->iter->index = -1;
}

void moveTo(List* list, int index)
{
    if (index < list->iter->index) {
        begin(list);
    }
    while (list->iter->index != index) {
        next(list);
    }
}

void add(TypeElement value, List* list, int index)
{
    if (index == -1) {
        index = list->size - 1;
    } else {
        index--;
    }
    moveTo(list, index);
    ListElement* newElement = new ListElement{value, getCurrent(list)->next};
    getCurrent(list)->next = newElement;
    (list->size)++;
}

int pop(List* list, int index)
{
    if (index == -1) {
        index = list->size - 1;
    }
    if (index < list->size && index >= 0) {
        moveTo(list, index - 1);
        ListElement* buffer = getCurrent(list)->next;
        getCurrent(list)->next = buffer->next;
        delete buffer;
        (list->size)--;
        return 0;
    } else {
        return -1;
    }
}

TypeElement getValue(List* list, int index)
{
    if (index < list->size && index >= 0) {
        moveTo(list, index);
        return getCurrent(list)->value;
    } else {
        return -1;
    }
}

int getIndex(TypeElement value, List *list)
{
    begin(list);
    bool isExist = false;
    while (getCurrent(list)->next != 0) {
        next(list);
        if (getCurrent(list)->value == value) {
            isExist = true;
            break;
        }
    }
    return (isExist ? list->iter->index : (-1));
}

int getSize(List *list)
{
    return list->size;
}

bool isEmpty(List *list)
{
    return (list->sentinel->next == nullptr);
}

void reverse(List*& list)
{
    if (list == nullptr)
        return;

    List* reversedList = createList();
    begin(list);
    while (getCurrent(list)->next != nullptr) {
        next(list);
        add(getCurrent(list)->value, reversedList, 0);
    }
    deleteList(list);
    list = reversedList;
}

void printList(List *list)
{
    begin(list);
    while (getCurrent(list)->next != nullptr) {
        cout << getCurrent(list)->next->value << ' ';
        next(list);
    }
    cout << endl;
}

List* createList()
{
    ListElement* sent = new ListElement{-1, nullptr};
    Iterator* iter = new Iterator{sent, -1};
    return new List{sent, iter, 0};
}

void clearList(List *list)
{
    begin(list);
    while (getCurrent(list)->next != nullptr) {
        pop(list, 0);
    }
}

void deleteList(List* list)
{
    begin(list);
    while (getCurrent(list)->next != nullptr) {
        pop(list, 0);
    }
    delete list->sentinel;
    delete list->iter;
    delete list;
}
