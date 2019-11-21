#include<iostream>


class MinHeap
{
  // pointer to array of elements in heap
  int *heapArr;
  // maximum possible size of min heap
  int capacity;
  // Current number of elements in min heap
  int currentSize;

public:
  MinHeap(int capacity);
  int parent(int index);
  int leftChild(int index);
  int rightChild(int index);

  int getMin();
  void heapify(int index);
  int extractMin();
  void insertElement(int value);
  void print();
  void deleteKey(int key);

};
