#include <iostream>

using namespace std;

// any file that uses the SLL class must include this header file
#include "SLL.hpp"

int main(){

	// Test case 0: instantiate object - compile
	SLL S0;

	// Test case 1: test the search() method
	// Expected: null ptr
	cout << "TS1: " << endl;
	Node* ptr;
	ptr = S0.search("hello");
	cout << ptr << endl;
	cout << endl; // end of TS1

	// Test case 2: test the display() method
	// Expected: empty list
	cout << "TS2: " << endl;
	S0.displayList();
	cout << endl; // end of TS2

	// Test case 3a: test the insert() method
	// insert into an empty list
	// Expected: print the list, see the contents of node
	cout << "TS3a: " << endl;
	S0.insert(nullptr,"hello");
	S0.displayList();
	cout << endl; // end of TS3a

	// Test case 3b: test the insert() method
	// insert before head
	// Expected: print the list, see the contents of 2 nodes
	cout << "TS3b: " << endl;
	S0.insert(nullptr,"there");
	S0.displayList();
	cout << endl; // end of TS3b

	// Test case 3c: test the insert() method
	// insert  elsewhere in the list (specify "afterMe" node)
	// Expected: print the list, see the contents of all nodes
	// in correct order
	cout << "TS3c: " << endl;
	ptr = S0.search("hello");
	S0.insert(ptr,"woot");
	S0.displayList();
	cout << endl; // end of TS3c

	// Test case 3d: test the insert() method
	// insert  elsewhere in the list (specify "afterMe" node)
	// Expected: print the list, see the contents of all nodes
	// in correct order
	cout << "TS3d: " << endl;
	ptr = S0.search("there");
	S0.insert(ptr,"bee");
	S0.displayList();
	cout << endl; // end of TS3c

	// Test case 4a: test the deleteNode() method
	// delete a known existing node
	// Expected: print the list, see the contents of all nodes
	// in correct order
	cout << "TS4a: " << endl;
	ptr = S0.search("there");
	S0.deleteNode(ptr);
	S0.displayList();
	cout << endl; // end of TS4

	// Test case 4b: test the deleteNode() method
	// delete a known existing node
	// Expected: print the list, see the contents of all nodes
	// in correct order
	cout << "TS4b: " << endl;
	ptr = S0.search("hello");
	S0.deleteNode(ptr);
	S0.displayList();
	cout << endl; // end of TS4b

	// Test case 4c: test the deleteNode() method
	// delete a known existing node
	// Expected: print the list, see the contents of all nodes
	// in correct order
	cout << "TS4c: " << endl;
	ptr = S0.search("woot");
	S0.deleteNode(ptr);
	S0.displayList();
	cout << endl; // end of TS4c

	// Test case 5: test the destructor
	// deallocate entire list
	// Expected: print the list, empty list
	S0.~SLL();
	cout << "disp list after destructor call: " << endl;
	S0.displayList();

	return 0;
}
