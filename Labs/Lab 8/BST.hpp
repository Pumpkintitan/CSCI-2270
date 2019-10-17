#ifndef BST_HPP
#define BST_HPP

using namespace std;

struct Node{
    int key;
    Node* left ;
    Node* right;
};

class BST{
    private:
        Node* root;
        Node* createNode(int data);
        /** since root is a private member we need helper functions
         to access root for insertion, searching and printing.
         These helper functions is used for performing recursion **/

        Node* addNodeHelper(Node*, int);
        void printTreeHelper(Node*);
        void print2DUtilHelper(Node *, int);

        Node* searchKeyHelper(Node*, int);

        Node* getMinValueNode(Node*);
        Node* getMaxValueNode(Node*);

        void destroyNode(Node *root);

        Node* deleteNode(Node*, int);


    public:
        Node* getRoot();                // Returns the root of the tree;
        void addNode(int);              // function to insert a node in the tree.
        bool searchKey(int);            // function to search a data in the tree
        void printTree();               //function to print the tree
        BST();                          // default constructor
        BST(int data);                  // parameterized constructor
        ~BST();                         // destructor
        void removeRange(int, int);
        void print2DUtil(int);
        bool isValidBST();

};
#endif
