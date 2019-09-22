/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{

}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName)
{
  if(head == nullptr) {
    head = new Country;
    head->name = countryName;
    head->next = nullptr;
    head->numberMessages = 0;
    cout << "adding: " << head->name << " (HEAD)" << endl;
  }
  else if(previous==nullptr) {
    Country* newNode = new Country;
    newNode->name = countryName;
    newNode->next = head;
    head = newNode;
    newNode->numberMessages = 0;
    cout << "adding: " << newNode->name << " (HEAD)" << endl;
  }
  else {
    Country* newNode = new Country;
    newNode->name = countryName;
    newNode->next = previous->next;
    previous->next = newNode;
    newNode->numberMessages = 0;
    cout << "adding: " << newNode->name << " (prev: " << previous->name << ")" << endl;
  }
}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
  insertCountry(nullptr, "United States");
  insertCountry(searchNetwork("United States"), "Canada");
  insertCountry(searchNetwork("Canada"), "Brazil");
  insertCountry(searchNetwork("Brazil"), "India");
  insertCountry(searchNetwork("India"), "China");
  insertCountry(searchNetwork("China"), "Australia");
  searchNetwork("Australia")->next = nullptr;
  printPath();
}

/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
  Country* ptr = head;
  while (ptr != NULL && ptr->name != countryName)
  {
      ptr = ptr->next;
  }
  return ptr;
}

/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string message)
{
  if (head == NULL) {
    cout << "Empty list" << endl;
  } else if (searchNetwork(receiver) == NULL) {
    cout << "Country not found" << endl;
  } else {
    Country* sender = head;
    while (true) {
      sender->message = message;
      sender->numberMessages++;
      cout << sender->name << " [# messages received: " << sender->numberMessages << "] received: " << sender->message << endl;
      if (sender->name == receiver) {
        break;
      }
      sender = sender->next;
    }
  }
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
  Country* temp = head;
  cout << "== CURRENT PATH ==" << endl;
  if (head == NULL) {
    cout << "nothing in path" << endl;
  } else {
    while(temp->next != NULL){
      cout<< temp->name <<" -> ";
      temp = temp->next;
    }
    cout <<temp->name<<" -> "<<"NULL"<< endl;
  }

   cout << "===" << endl;
}
