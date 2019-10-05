#ifndef STACKARR_HPP
#define STACKARR_HPP

using namespace std;

class Stack_Arr{
  private:
    int *arr;
    int capacity;
    int top;

  public:
    Stack_Arr();
    ~Stack_Arr();
    void initialise(int cap);
    void push(int num);
    void pop();
    int peek();
    bool isEmpty();
    bool isFull();
    void printStack();
};
#endif
