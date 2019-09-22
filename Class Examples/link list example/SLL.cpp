#include <iostream> // predefined header file (defined for you)
using namespace std;

#include "SLL.hpp" // your own header file
// <> vs "" -- compiler looks for the file in the C++ implementation
// vs in the current directory


SLL::SLL(){ // constructor definition
  head = nullptr;
}

SLL::~SLL(){

}

Node* SLL::search(string sKey){
  Node* crawler = head;

  while(crawler != nullptr && crawler != sKey) {
    crawler = crawler->next;
  }
  return crawler;
}

void SLL::displayList(){
  Node* crawler = head;
  while (crawler != nullptr) {
    cout << crawler->key << "->";
    crawler = crawler->next;
  }
  cout << "END" << endl;
}


void SLL::insert(Node* afterMe, string newValue){
  if(head == nullptr) {
    head = new Node;
    head->key = newValue;
    head->next = nullptr;

  }
  else if(afterMe==nullptr) {
    Node* newNode = new Node;
    newNode->key = newValue;
    newNode->next = head;
    head = newNode;
  }
  else {
    Node* newNode = new Node;
    newNode->key = newValue;
    newNode->next = afterMe->next;
    afterMe->next = newNode;

  }
}


void SLL::deleteNode(Node* deleteNode){

}
