/****************************************************************/
/*                  CountryNetwork Definition                   */
/****************************************************************/
/* LEAVE THIS FILE AS IS! DO NOT MODIFY ANYTHING! =]            */
/****************************************************************/

#pragma once
#include <iostream>

// Country: node struct that will be stored in the CountryNetwork
//   linked-list
struct Country
{
    std::string name;         // name of the country
    std::string message;      // message this country has received
    int numberMessages;       // no. of messages passed through this country
    Country *next;            // pointer to the next country
};

// class for storing and manipulating linked-list of countries
class CountryNetwork {
    private:
        // pointer to head of linked-list of countries
        Country* head;
    public:
        // See writeup for method descriptions
        CountryNetwork();
        bool isEmpty();
        void insertCountry(Country* previous, std::string countryName);
        void deleteCountry(std::string countryName);
        void loadDefaultSetup();
        Country* searchNetwork(std::string countryName);
        void deleteEntireNetwork();
        void reverseEntireNetwork();
        void rotateNetwork(int n);
        //void transmitMsg(std::string receiver, std::string msg);
        void printPath();
};
