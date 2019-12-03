/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "ProducerConsumer.cpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
  cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}

int main(int argc, char const *argv[])
{
	ProducerConsumer PC;
	int choice;
	int num;
	int qsize;
	string produce;
	while (choice != 3) {
		menu();
		cin >> choice;
		switch(choice) {
			case 1:
				cout << "Enter the number of items to be produced:" << endl;
				cin >> num;
				for (int i = 0; i < num; i++) {
					cout << "Item" << i+1 << ":" << endl;
					cin >> produce;
					PC.enqueue(produce);
				}
				break;
			case 2:
				cout << "Enter the number of items to be consumed:" << endl;
				cin >> num;
				qsize = PC.queueSize();
				for (int i = 0; i < num; i++) {
					if (i == qsize) {
						cout << "No more items to consume from queue" << endl;
						i = num;
					} else {
						cout << "Consumed: " << PC.peek() << endl;
						PC.dequeue();
					}
				}
				break;
			case 3:
			cout << "Number of items in the queue:" << PC.queueSize();
				break;
		}
	}
}
