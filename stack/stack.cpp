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

TypeElement pop(Stack* stack)
{
    TypeElement value = stack->head->value;
    StackElement* next = stack->head->next;
    delete stack->head;
    stack->head = next;
    return value;
}

TypeElement top(Stack* stack)
{
    return stack->head->value;
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
