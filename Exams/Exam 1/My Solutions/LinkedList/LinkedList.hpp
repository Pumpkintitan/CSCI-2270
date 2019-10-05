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
    void removeNthFromEnd(int n);
    void printList();
    void loadList(int*, int);

};

// Additional class used for testing (do not update this class):
class Check {
public:
    bool areIdentical(struct Node *a, struct Node *b);
};