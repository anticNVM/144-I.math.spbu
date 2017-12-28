#include <mergesort.h>
#include "list.h"

using namespace std;

List* merge(List* listA, List* listB);

// beg ??
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

List* merge(List *listA, List *listB)
{
    List* merged = createList();
    moveTo(listA);
    moveTo(listB);
    while (true) {
        if (getCurrentValue(listA) <= getCurrentValue(listB)) {
            add(getCurrentValue(listA), merged);
            if (isEnd(listA)) {
                while (true) {
                    add(getCurrentValue(listB), merged);
                    if (isEnd(listB)) {
                        break;
                    } else {
                        next(listB);
                    }
                }
                break;
            } else {
                next(listA);
            }
        } else {
            add(getCurrentValue(listB), merged);
            if (isEnd(listB)) {
                while (true) {
                    add(getCurrentValue(listA), merged);
                    if (isEnd(listA)) {
                        break;
                    } else {
                        next(listA);
                    }
                }
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
