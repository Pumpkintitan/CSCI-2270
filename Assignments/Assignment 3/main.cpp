/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
// you may include more libraries as needed

// declarations for main helper-functions
void displayMenu();

int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    CountryNetwork CountryNet;
    int choice = 0;
    string reciever = "";
    string message = "";
    string newc = "";
    string prev = "";
    while (choice != 5) {
      displayMenu();
      cin >> choice;
      if (choice < 6) {
      switch (choice) {
        case 1:
          CountryNet.loadDefaultSetup();
          break;
        case 2:
          CountryNet.printPath();
          break;
        case 3:
          cout << "Enter name of the country to receive the message: "<< endl;
          cin.ignore();
          getline(cin,reciever);
          cout << "Enter the message to send: " << endl << endl;
          getline(cin,message);
          CountryNet.transmitMsg(reciever, message);
          break;
        case 4:
          cout << "Enter a new country name: " << endl;
          cin.ignore();
          getline(cin,newc);
          cout << "Enter the previous country name (or First): " << endl;
          getline(cin,prev);
          while (CountryNet.searchNetwork(prev) == NULL) {
            if (prev == "First") {
              break;
            }
            cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
            getline(cin,prev);
          }
          CountryNet.insertCountry(CountryNet.searchNetwork(prev), newc);
          CountryNet.printPath();
          break;
        case 5:
          cout << "Quitting..." << endl;
          break;
      }
    } else {
      cout << "Invalid Input" << endl;
    }
    }
    cout << "Goodbye!" << endl;
    return 0;
}


/*
 * Purpose; displays a menu with options
 */
void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
