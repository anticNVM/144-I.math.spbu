#ifndef QUEUE
#define QUEUE

typedef int TypeElement;

struct Queue;

void enqueue(Queue* que, TypeElement value, int priority);

TypeElement dequeue(Queue* que);

Queue* create();

void deleteQue(Queue* que);

#endif // QUEUE

