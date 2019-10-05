#include <iostream>
#include "QueueLL.hpp"

using namespace std;

QueueLL::QueueLL()
{
    queueFront = nullptr;
    queueEnd = nullptr;
    size = 0;
}

QueueLL::~QueueLL()
{
    while( !isEmpty() )
        dequeue();
}

bool QueueLL::isEmpty()
{
    /*if(queueFront == nullptr || queueEnd == nullptr)
        return true;
    return false;*/
    return (!queueFront || !queueEnd);
}

void QueueLL::enqueue(int key)
{
    Node *nn = new Node;
    nn->key = key;
    nn->next = nullptr;

    if( isEmpty() )
    {
        queueFront = nn;
        queueEnd = nn;
    }
    else
    {
        queueEnd->next = nn;
        queueEnd = nn;
    }
    size++;
}

void QueueLL::dequeue()
{
    if(!isEmpty())
    {
        Node* temp = queueFront;
        queueFront = queueFront->next;
        delete temp;
        // if the queue is empty now update end pointer//
        if(queueFront == nullptr)
            queueEnd = nullptr;
        size--;
    }
    else{
        cout<<"queue is empty. can not deque"<<endl;
    }

}

int QueueLL::peek()
{
    if( !isEmpty() )
        return queueFront->key;
    else
    {
        cout<< " queue is empty. can not peek"<<endl;
        return -1;
    }
    //return 0;
}

int QueueLL::queueSize(){
  return size;


}
