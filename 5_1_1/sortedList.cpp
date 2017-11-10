#include "sortedList.h"
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

struct SortedList {
    ListElement* sentinel;
    Iterator* iter;
    int size;
};

ListElement* & getCurrent(SortedList* list)
{
    return list->iter->current;
}

void next(SortedList* list)
{
    assert(getCurrent(list)->next != nullptr);
    getCurrent(list) = getCurrent(list)->next;
    (list->iter->index)++;
}

void begin(SortedList* list)
{
    // -1
    getCurrent(list) = list->sentinel;
    list->iter->index = -1;
}

void moveTo(SortedList* list, int index)
{
    if (index < list->iter->index) {
        begin(list);
    }
    while (list->iter->index != index) {
        next(list);
    }
}

void push(TypeElement value, SortedList* list)
{
    // add key to sort list
    begin(list);
    while (getCurrent(list)->next != nullptr && getCurrent(list)->next->value < value) {
        next(list);
    }
    ListElement* newElement = new ListElement{value, getCurrent(list)->next};
    getCurrent(list)->next = newElement;
    (list->size)++;
}

int remove(SortedList* list, int index)
{
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

TypeElement getValue(SortedList* list, int index)
{
    if (index < list->size && index >= 0) {
        moveTo(list, index);
        return getCurrent(list)->value;
    } else {
        return -1;
    }
}

int getIndex(TypeElement value, SortedList *list)
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

int getSize(SortedList *list)
{
    return list->size;
}

bool isEmpty(SortedList *list)
{
    return (list->sentinel->next == nullptr);
}

void printList(SortedList *list)
{
    begin(list);
    while (getCurrent(list)->next != nullptr) {
        cout << getCurrent(list)->next->value << ' ';
        next(list);
    }
    cout << endl;
}

SortedList* createList()
{
    ListElement* sent = new ListElement{-1, nullptr};
    Iterator* iter = new Iterator{sent, -1};
    return new SortedList{sent, iter, 0};
}

void clearList(SortedList *list)
{
    begin(list);
    while (getCurrent(list)->next != nullptr) {
        remove(list, 0);
    }
}

void deleteList(SortedList *list)
{
    begin(list);
    while (getCurrent(list)->next != nullptr) {
        remove(list, 0);
    }
    delete list->sentinel;
    delete list;
}

void test()
{
    SortedList* myLst = createList();
    push(5, myLst);
    push(4, myLst);
    push(6, myLst);
    printList(myLst);
    cout << getValue(myLst, 1) << endl;
    cout << getIndex(4, myLst) << endl;
    cout << getSize(myLst) << endl;
    cout << isEmpty(myLst) << endl;
    printList(myLst);
    clearList(myLst);
    printList(myLst);
    deleteList(myLst);
}
