#ifndef QUEUEST_HPP
#define QUEUEST_HPP
#include "STACKARR.hpp"
using namespace std;

class Queue{
  private:
      Stack_Arr primary;
      Stack_Arr secondary;
      //int front;
      //int rear;
  public:
      Queue();
      ~Queue();
      void initialiseQueue(int cap);
      void enqueue(int num);
      int dequeue();
      bool isFull();
      bool isEmpty();
};
#endif
