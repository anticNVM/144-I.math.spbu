#include "stack.h"

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

bool pop(Stack* stack, TypeElement& value)
{
    if (stack->head != nullptr) {
        value = stack->head->value;
        StackElement* next = stack->head->next;
        delete stack->head;
        stack->head = next;
        return true;;
    } else {
        return false;
    }
}

bool top(Stack* stack, TypeElement& value)
{
    if (stack->head != nullptr) {
        value = stack->head->value;
        return true;
    } else {
        return false;
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
        TypeElement temp;
        pop(stack, temp);
    }
    delete stack;
}
