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
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{
  if (head == NULL) {
    return true;
  } else {
    return false;
  }
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
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
void CountryNetwork::deleteCountry(string countryName) {
  if (searchNetwork(countryName) == NULL) {
    cout << "Country does not exist." << endl;
  } else {
  Country* temp = head;
  Country* prev = NULL;
  if (head->name == countryName) {
    Country* newNode = head;
    head = head->next;
    delete newNode;
  } else {
    while (temp->name != countryName) {
      prev = temp;
      temp = temp->next;
    }
    prev->next = temp->next;
    delete temp;
  }
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
 * @see insertCountry, deletecountry
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
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork() {
  Country* node = head;
  while (node != NULL) {
    cout << "deleting: " << node->name << endl;
    delete node;
    node = node->next;
  }
  head = NULL;
  cout << "Deleted network" << endl;
}

/*
 * Purpose: Rotate the linked list i.e. move 'n' elements from
 * the back of the the linked to the front in the same order.
 * @param number elements to be moved from the end of the list to the beginning
 * @return none
 */
void CountryNetwork :: rotateNetwork(int n) {
  if (head == NULL) {
    cout << "Linked List is Empty" << endl;
  } else {
  Country* count = head;
  int counter = 1;
  while (count->next != NULL) {
    count = count->next;
    counter++;
  }
  if (n < counter) {
    for (int i = 0; i < n; i++) {
      Country* temp = head;
      Country* prev = head->next;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = head;
      head->next = NULL;
      head = prev;
    }
    cout << "Rotate Complete" << endl;
  } else {
    cout << "Rotate not possible" << endl;
  }
}
}

/*
 * Purpose: reverse the entire network
 * @param ptr head of list
 */
void CountryNetwork::reverseEntireNetwork() {
  if (head != NULL) {
  Country* count = head;
  int counter = 1;
  while (count->next != NULL) {
    count = count->next;
    counter++;
  }
  for (int i = counter; i > 1; i--) {
    Country* temp = head;
    Country* prev = NULL;
    for (int j = 1; j < i; j++) {
      prev = temp;
      temp = temp->next;
    }
    temp->next = prev;
  }
  head->next = NULL;
  head = count;
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
   if (temp == NULL) {
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
