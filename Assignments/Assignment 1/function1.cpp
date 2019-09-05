#include "function1.h"
#include <iostream>
using namespace std;
int insertIntoSortedArray(int myArray[], int numEntries, int newValue) {
  int i=0;
  int j=0;
  int temp1=0;
  bool inserted = false;
  string output = "";
  myArray[numEntries-1] = newValue;

  for (i = 0; i < numEntries; i++) {
    for (j = 0; j < numEntries; j++) {
      if (myArray[j] > myArray[i]) {
        temp1 = myArray[i];
        myArray[i] = myArray[j];
        myArray[j] = temp1;
      }
    }
  }

  for (i = 0; i < numEntries; i++) {
    if (i == 0) {
      cout << myArray[i];
    } else {
      cout << ", " << myArray[i];
    }
  }
  cout << endl;
};
