#include <mergesort.h>
#include "list.h"

using namespace std;

List* merge(List* listA, List* listB);

void mergeSort(List*& list)
{
    moveTo(list);
    if (isEnd(list)) {
        return;
    }
    int size = getSize(list);
    int middle = size / 2;
    List* leftList = createList();
    List* rightList = createList();

    for (int i = 0; i < middle; ++i) {
        add(getCurrentValue(list), leftList);
        next(list);
    }
    for (int i = middle; i < size; ++i) {
        add(getCurrentValue(list), rightList);
        if (!isEnd(list)) {
            next(list);
        }
    }
    mergeSort(leftList);
    mergeSort(rightList);
    clearList(list);
    list = merge(leftList, rightList);
}

void mergeTail(List* merged, List* list)
{
    while (true) {
        add(getCurrentValue(list), merged);
        if (isEnd(list)) {
            break;
        } else {
            next(list);
        }
    }
}

List* merge(List *listA, List *listB)
{
    List* merged = createList();
    moveTo(listA);
    moveTo(listB);
    while (true) {
        if (getCurrentValue(listA) <= getCurrentValue(listB)) {
            add(getCurrentValue(listA), merged);
            if (isEnd(listA)) {
                mergeTail(merged, listB);
                break;
            } else {
                next(listA);
            }
        } else {
            add(getCurrentValue(listB), merged);
            if (isEnd(listB)) {
                mergeTail(merged, listA);
                break;
            } else {
                next(listB);
            }
        }
    }
    deleteList(listA);
    deleteList(listB);

    return merged;
}
