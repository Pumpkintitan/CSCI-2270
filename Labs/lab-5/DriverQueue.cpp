#include <iostream>
#include "QueueLL.hpp"
using namespace std;

int main()
{
    // test queues
    QueueLL queue;

    // TC1: queue empty after created?
    cout << "(1) ";
    cout << "Queue empty? ";
    cout << (queue.isEmpty() ? "yes." : "no.");
    if(!queue.isEmpty()) cout << "  -- FAIL";
    cout << endl;

    // TC2: Push items
    // TODO SILVER - Complete your enqueue function
    cout << "(2) ";
    cout << "Enqueuing 1, 2, 3" << endl;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    // TC3: Queue not empty after pushing items
    cout << "(3) ";
    cout << "Queue empty? ";
    cout << (queue.isEmpty() ? "yes." : "no.");
    if(queue.isEmpty()) cout << "  -- FAIL";
    cout << endl;

    // TC4: peek
    cout << "(4) ";
    int topKey = queue.peek();
    cout << "Peeked key: " << topKey;
    if(topKey != 1) {
        cout << "  -- FAIL";
    }
    cout << endl;

    // TC5: pop items
    // TODO SILVER - Complete your dequeue function
    cout << "(5) Dequeuing everything" << endl;
    int testint = 0;
    int testvals[] = {1, 2, 3};
    while(!queue.isEmpty()) {
        topKey = queue.peek();
        queue.dequeue();
        cout << "  - dequeue: " << topKey;
        if(topKey != testvals[testint++]) {
            cout << "  -- FAIL";
        }
        cout << endl;
    }
    if(testint != 3) cout << "  -- FAIL" << endl;

    return 0;
}
