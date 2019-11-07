// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"


using namespace std;

node* HashTable::createNode(int key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    table = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        table[i] = nullptr;
}

//function to calculate hash function
unsigned int HashTable::hashFunction(int key)
{
    return (key % tableSize);
}

// TODO Complete this function
//function to search
node* HashTable::searchItem(int key)
{
    //Compute the index by using the hash function
    int index = hashFunction(key);
    // node* temp = table[index];
    // while (temp != nullptr) {
    //   if (temp->key == key) {
    //     return table[index];
    //   }
    //   temp = temp->next;
    // }
    // return NULL;


    if (table[index] != nullptr) {
      node* temp = table[index];
      while (temp->key != key && temp->next != NULL) {
        temp = temp->next;
      }
      return temp;
    } else {
      return NULL;
    }

}

//TODO Complete this function
//function to insert
bool HashTable::insertItem(int key)
{
    if(!searchItem(key))
    {
        int index = hashFunction(key);
          node* temp = createNode(key, NULL);
          table[index] = temp;

        // TODO :
        // Use the hash function on the key to get the index/slot,
        // create a new node with the key and insert it in this slot's list

     }
    else{
        cout<<"duplicate entry: "<<key<<endl;
        int index = hashFunction(key);
        node* temp = createNode(key, table[index]->next);
        table[index]->next = temp;
        return false;
    }

}

//TODO Complete this function
// function to display hash table
void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++) {
        cout << i <<"|| ";
        node* temp = table[i];
        while (temp != NULL) {
          cout << temp->key << " ";
          temp = temp->next;
        }
    }

 }
