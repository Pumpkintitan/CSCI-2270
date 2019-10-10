#include <iostream>
#include "tree.hpp"
using namespace std;
#define COUNT 10


int main()
{
  Tree t;
  t.createTree();
  //cout<<t.root->data<<endl;
  t.print2DUtil(t.root, 0);


  // 1, 2, 4, 5, 3, 6, 7
  cout << "\nPreorder traversal of binary tree is \n";
  t.preOrderTraverse(t.root);
  cout<<endl;

  /**********************
  Gold - Find the sum of all the nodes in the tree
  ***********************/
  cout << "\nSum of all the nodes in tree is:"<<t.sumNodes(t.root);
  cout<<endl;

  /**********************
  Silver - Delete all the nodes from the tree
  ***********************/
  cout << "\nDeleting tree \n";
  t.deleteTree(t.root);
  t.root=NULL;
  cout<<endl;

  return 0;
}
