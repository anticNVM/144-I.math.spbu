#include "stackInt.h"

struct StackElement {
    TypeElement value;
    StackElement* next;
};

struct Stack {
    StackElement* head;
};

void push(TypeElement value, Stack* stack)
{
    StackElement* newElement = new StackElement{value, stack->head};
    stack->head = newElement;
}

TypeElement pop(Stack* stack, bool* isSuccessful)
{
    if (stack->head != nullptr) {
        TypeElement value = stack->head->value;
        StackElement* next = stack->head->next;
        delete stack->head;
        stack->head = next;
        if (isSuccessful) {
            *isSuccessful = true;
        }
        return value;
    } else {
        if (isSuccessful) {
            *isSuccessful = false;
        }
        return {};
    }
}

TypeElement top(Stack* stack, bool* isSuccessful)
{
    if (stack->head != nullptr) {
        if (isSuccessful) {
            *isSuccessful = true;
        }
        return stack->head->value;
    } else {
        if (isSuccessful) {
            *isSuccessful = false;
        }
        return {};
    }
}

bool isEmpty(Stack* stack)
{
    return (stack->head == nullptr);
}

Stack* createStack()
{
    return new Stack{};
}

void deleteStack(Stack* stack)
{
    while (!isEmpty(stack)) {
        pop(stack);
    }
    delete stack;
}
