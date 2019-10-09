#ifndef STACKLL_HPP
#define STACKLL_HPP

class StackLL
{
  private:
    struct Node
    {
        char key;
        Node *next;
    };

    // pocharer to item to be popped next
    Node* stackHead;

  public:
    StackLL();
    ~StackLL();
    bool isEmpty();
    void push(char key);
    void pop();
    char peek();
};

#endif
