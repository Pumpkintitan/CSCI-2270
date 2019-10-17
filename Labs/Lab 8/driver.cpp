#include <iostream>
#include "BST.hpp"
using namespace std;

int main (int argc, char* argv[]){
  cout<<"Creating tree"<<endl;
  BST tree(5);


  tree.addNode(2); //left child to 5
  tree.addNode(1); //left child to 1
  tree.addNode(4); //right child to 2
  tree.addNode(7); //right child to 5
  tree.addNode(10); //right child of 7
  tree.addNode(8); // left child of 10
  tree.addNode(6); // left child of 7

  cout<<"----------------Intial tree is ---------------"<<endl<<endl;
  tree.print2DUtil(1);

  cout<<"----------------Inorder traversal of the tree is ---------------"<<endl<<endl;
  tree.printTree();

  cout<<"Enter the range for nodes which need to be removed"<<endl;
  cout<<"lower bound?"<<endl;
  int lower;
  cin>>lower;
  cout<<endl;
  cout<<"upper bound?"<<endl;
  int upper;
  cin>>upper;
  cout<<endl;

  //SILVER TODO - Complete the TODOs in deleteNode() function which is called within removeRange() function
  tree.removeRange(lower,upper);

  cout<<"----------------Final tree after deletion is ---------------"<<endl<<endl;
  tree.print2DUtil(1);

  cout<<"----------------Inorder traversal of the tree after deletion ---------------"<<endl<<endl;
  tree.printTree();


  // GOLD TODO  - Complete this function
  cout<< tree.isValidBST() << endl;

}
