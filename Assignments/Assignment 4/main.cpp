/****************************************************************/
/*                   Assignment 4 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.cpp"
// you may include more libraries as needed

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    CountryNetwork CountryNet;
    int choice = 0;
    string newc = "";
    string prev = "";
    int rotate = 0;
    while (choice != 8) {
      displayMenu();
      cin >> choice;
      if (choice < 9) {
      switch (choice) {
        case 1:
          CountryNet.loadDefaultSetup();
          break;
        case 2:
          CountryNet.printPath();
          break;
        case 3:
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
        case 4:
          cout << "Enter a country name:"<< endl;
          cin.ignore();
          getline(cin,newc);
          CountryNet.deleteCountry(newc);
          CountryNet.printPath();
          break;
        case 5:
          CountryNet.reverseEntireNetwork();
          CountryNet.printPath();
          break;
        case 6:
          cout << "Enter the count of values to be rotated:" << endl;
          cin >> rotate;
          CountryNet.rotateNetwork(rotate);
          CountryNet.printPath();
          break;
        case 7:
          cout << "Network before deletion" << endl;
          CountryNet.printPath();
          CountryNet.deleteEntireNetwork();
          cout << "Network after deletion" << endl;
          CountryNet.printPath();
          break;
        case 8:
          cout << "Quitting... cleaning up path:" << endl;
          CountryNet.printPath();
          CountryNet.deleteEntireNetwork();
          cout << "Path cleaned" << endl;
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
    cout << " 3. Add Country " << endl;
    cout << " 4. Delete Country " << endl;
    cout << " 5. Reverse Network" << endl;
    cout << " 6. Rotate Network" << endl;
    cout << " 7. Clear Network " << endl;
    cout << " 8. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
