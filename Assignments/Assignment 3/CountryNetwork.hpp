/****************************************************************/
/*                  CountryNetwork Definition                   */
/****************************************************************/
/* LEAVE THIS FILE AS IS! DO NOT MODIFY ANYTHING! =]            */
/****************************************************************/

#pragma once
#include <iostream>
using namespace std;

// Country: node struct that will be stored in the CountryNetwork
//   linked-list
struct Country
{
    string name;         // name of the country
    string message;      // message this country has received
    int numberMessages;       // no. of messages passed through this country
    Country *next;            // pointer to the next country
};

// class for storing and manipulating linked-list of countries
// class for storing and manipulating linked list of countries
class CountryNetwork {
    private:
        // pointer to head of linked list of cities
        Country* head;
    public:
        // See definitions at bottom of file for method descriptions.
        // You will need to complete the 7 unfinished methods.
        CountryNetwork();
        void insertCountry(Country* previous, string countryName); // TODO
        void loadDefaultSetup();                       // TODO
        Country* searchNetwork(string countryName);          // TODO
        void transmitMsg(string receiver, string msg); // TODO
        void printPath();                              // TODO
};