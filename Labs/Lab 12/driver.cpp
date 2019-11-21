#include "MinHeap.hpp"
using namespace std;

int main()
{
  MinHeap heap(10);
  heap.insertElement(9);
  heap.insertElement(13);
  heap.insertElement(10);
  heap.insertElement(14);
  heap.insertElement(15);
  heap.insertElement(12);
  heap.insertElement(11);
  heap.insertElement(8);

  cout<<"***********Elements in the heap are **********"<<endl;
  heap.print();
  cout<<endl;

  // SILVER TODO: Find the smallest element in the heap. Complete the extractMin and heapify function.
  cout << "Smallest element extracted is: "<<heap.extractMin() <<endl<<endl;

  cout<<"***********Elements in the heap after extracting the smallest element**********"<<endl;
  heap.print();
  cout<<endl;


  // GOLD TODO: Delete a key from the heap. Complete the deleteKey function.
  int key = 15;
  cout << "Deleting a key from the heap: "<<endl<<endl;
  heap.deleteKey(key);
  cout<<"***********Elements in the heap after deleting the key**********"<<endl;
  heap.print();

  cout<<endl;
  return 0;
}
