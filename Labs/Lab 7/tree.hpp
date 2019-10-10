#include <iostream>
using namespace std;
#define COUNT 10

/*
Each node in the tree has this structure
*/
struct Node
{
  int data;
  Node *left;
  Node *right;
  Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};


/*
Variables and functions for Tree ADT
*/
class Tree
{

  public:
    Node *root;
    Tree();
    void createTree();
    void deleteTree(Node *root);
    int sumNodes(Node *root);
    void preOrderTraverse(Node *root);
    void print2DUtil(Node *root, int space);
};
