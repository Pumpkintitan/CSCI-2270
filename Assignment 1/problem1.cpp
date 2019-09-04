#include <iostream>
#include <fstream>
#include "function1.h"
using namespace std;
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
