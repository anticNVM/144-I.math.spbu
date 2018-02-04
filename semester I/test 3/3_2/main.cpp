#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
    Queue* que = create();
    enqueue(que, 5, 1);
    enqueue(que, 10, 2);
    cout << dequeue(que) << endl;
    deleteQue(que);
    return 0;
}

