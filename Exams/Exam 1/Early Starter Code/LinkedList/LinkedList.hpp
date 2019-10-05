#include <iostream>

struct Node{
    int key;
    Node *next;
};

class LinkedList
{
private:
   Node *head;

public:
    LinkedList();
    ~LinkedList();
    void insert(Node *prev, int newKey);
    void printList();
    void loadList(int*, int);
};
