#include <iostream>
#include "BST.hpp"
using namespace std;
#define COUNT 10
/**
Create a node with key as data
**/

Node* BST:: createNode(int data)
{
    Node* newNode = new Node;
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BST::BST()
{

}

/**
parameterized constructor. It will create the root and put the data in the root.
**/

BST::BST(int data)
{
    root = createNode(data);
    cout<< "New tree created with "<<data<<endl;
}

/**
Destructor
**/

BST::~BST(){
     destroyNode(root);
}


Node* BST::getRoot(){
    return root;
}

 /**
 This function will destroy the subtree rooted at currNode.
 Think about in what order should you destroy. POSTORDER. or right-left-root
 **/
void BST:: destroyNode(Node *currNode){
     if(currNode!=NULL)
     {
         destroyNode(currNode->left);
         destroyNode(currNode->right);

         delete currNode;
         currNode = NULL;
     }
 }

/*
Prints a binary tree in a 2D fashion.
Note: The image of the tree is left rotated by 90 degrees.
*/
void BST::print2DUtilHelper(Node *currNode, int space)
{
    // Base case
    if (currNode == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtilHelper(currNode->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", currNode->key);

    // Process left child
    print2DUtilHelper(currNode->left, space);
}

void BST::print2DUtil( int space)
{
  print2DUtilHelper(root, space);
}



//---------------------------- INSERT NODE IN THE TREE --------------------------------------

/**
This function will add the data in the tree rooted at currNode.
We will call this function from addNode.
**/

Node* BST:: addNodeHelper(Node* currNode, int data)
{
    if(currNode == NULL){
        return createNode(data);
    }
    else if(currNode->key < data){
        currNode->right = addNodeHelper(currNode->right,data);
    }
    else if(currNode->key > data){
        currNode->left = addNodeHelper(currNode->left,data);
    }
    return currNode;

}


void BST:: addNode(int data)
{
    root = addNodeHelper(root, data);
    cout<<data<<" has been added"<<endl;
}

//-----------------------------------------PRINT TREE (INORDER TRAVERSAL)--------------------------------

/** This function will traverse the tree in-order and print out the node elements.
printTree() function will call this function.
**/

void BST:: printTreeHelper(Node* currNode){
     if(currNode)
     {
        printTreeHelper( currNode->left);
        cout << " "<< currNode->key;
        printTreeHelper( currNode->right);
     }
 }

void BST:: printTree(){
     printTreeHelper(root);
     cout<<endl;
}

 //------------------------------------------------SEARCH A KEY------------------------------------------
 /** This function will search the data in a tree
     We will call this function from searchKey.
 **/

Node* BST::searchKeyHelper(Node* currNode, int data){
    if(currNode == NULL)
        return NULL;

    if(currNode->key == data)
        return currNode;

    if(currNode->key > data)
        return searchKeyHelper(currNode->left, data);

    return searchKeyHelper (currNode->right, data);
}

// This function will return whether a key is in the tree
bool BST::searchKey(int key){
    Node* tree = searchKeyHelper(root, key);
    if(tree != NULL) {
        return true;
    }
    cout<<"Key not present in the tree"<<endl;
    return false;
}

//--------------------------- Get Max and Min value Node ------------------------------------------------

Node* BST::getMaxValueNode(Node* currNode){
    if(currNode->right == NULL){
        return currNode;
    }
    return getMaxValueNode(currNode->right);
}

Node* BST::getMinValueNode(Node* currNode){

    if(currNode->left == NULL){
      return currNode;
    }
    return getMinValueNode(currNode->left);
}


//--------------------------- Delete a Node ------------------------------------------------

// This function deletes the Node with 'value' as it's key. This is to be called inside removeRange() function
// SILVER TODO Complete the implementation of this function
Node* BST::deleteNode(Node *currNode, int value)
{

  if(currNode == NULL)
  {
    return NULL;
  }
  else if(value < currNode->key)
  {
    currNode->left = deleteNode(currNode->left, value);
  }
  else if(value > currNode->key)
  {
    currNode->right = deleteNode(currNode->right, value);
  }
  // We found the node with the value
  else
  {
    //TODO Case : No child
    if(currNode->left == NULL && currNode->right == NULL)
    {
      currNode = NULL;
    }
    //TODO Case : Only right child
    else if(currNode->left == NULL)
    {
      currNode = currNode->right;
    }
    //TODO Case : Only left child
    else if(currNode->right == NULL)
    {
      currNode = currNode->left;
    }
    //TODO Case: Both left and right child
    else
    {
      ///Replace with Minimum from right subtree
      getMinValueNode(currNode->right)->left = currNode->left;
      currNode = getMinValueNode(currNode->right);

    }

  }
return currNode;
}

// This function removes nodes with values in the range low and high.
// You need to call deleteNode() function inside this function

void BST::removeRange(int low, int high)
{
  for(int i=low; i<=high; i++){
    root=deleteNode(root,i);
  }
}

// ------------------------------------ Check for a Valid BST ------------------------------------------------

// GOLD TODO
bool BST::isValidBST()
{
  //TODO Uncomment below and Complete this function, you can use any logic (add a helper function if you want)
  return true;
}
