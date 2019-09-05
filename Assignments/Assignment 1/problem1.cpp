#include <iostream>
#include <fstream>
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

int main(int argc, char const *argv[]) {
  int mainArray[100];
  int i = 0;
  cout << argv[1] << endl;
  ifstream ifile(argv[1]);
  string temp;
  while (!ifile.eof()) {
    getline(ifile, temp);
    i++;
    insertIntoSortedArray(mainArray, i, stoi(temp));
  }
  return 0;
}
