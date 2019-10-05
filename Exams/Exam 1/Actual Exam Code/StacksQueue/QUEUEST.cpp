#include <iostream>
#include "QUEUEST.hpp"
using namespace std;


Queue::Queue()
{

}
Queue::~Queue()
{
  while(!isEmpty())
    dequeue();
}

/**
* This function will create the queue of size cap
* parameter: int cap
* return void
**/
void Queue:: initialiseQueue(int cap)
{
  primary.initialise(cap);
  secondary.initialise(cap);
}

/**
* This function will enqueue the argument num
* parameter: int num
* return void
**/
void Queue:: enqueue(int num){
    if(isFull())
    {
      cout<< " Queue is full. Can not enqueue"<<endl;
      return;
    }
    primary.push(num);
}
/**
* This function will dequeue from the queue.
* parameter: None
* return the dequeued value
* TODO: Implement this function
**/
int Queue:: dequeue(){
  return -1;
}
/**
* returns true if queue is full
**/
bool Queue:: isFull(){
  return primary.isFull();
}

/**
* returns true if queue is full.
**/
bool Queue:: isEmpty(){
  return primary.isEmpty();
}
