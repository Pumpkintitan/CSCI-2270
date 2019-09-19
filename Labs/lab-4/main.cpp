#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList li;
	cout<<"Adding nodes to List:"<<endl;
	// 2
	li.insert(NULL,2);
	li.printList();
	// -1->2
	li.insert(NULL, -1);
	li.printList();
	// -1->2->-7
	li.insert(li.searchList(2),-7);
	li.printList();
  // -1->2->-7->10
	li.insert(li.searchList(-7),10);
	li.printList();
	// -1->2->-7->10->3
	li.insert(li.searchList(10),3);
	li.printList();
	// -1->2->-7->10->3->5
	li.insert(li.searchList(3),5);
	li.printList();
	// -1->2->-7->10->3->5->-4
	li.insert(li.searchList(5),-4);
	li.printList();
	cout<<endl;


	/*******************************
	Silver Problem - Implement the deleteAtIndex function
	********************************/

  cout<<"Running delete function."<<endl;

	cout<<"Deleting node at index: 3"<<endl;
	if(!li.deleteAtIndex(3))
	{
		cout<<"Delete failed!"<<endl;
	}
	li.printList();
	cout<<endl;

    cout << "Deleting at index: 0" << endl;
    if(!li.deleteAtIndex(0))
	{
		cout<<"Delete failed!"<<endl;
	}
	li.printList();
	cout<<endl;

	/*******************************
	Gold Problem - Implement the swapFirstAndLast function
	********************************/

    cout << "Swapping First and last nodes" << endl;

    if(!li.swapFirstAndLast()) {
        cout << "Swapping Failed!" << endl;
    }
    li.printList();
    cout << endl;
}
