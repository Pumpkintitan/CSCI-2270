#include <iostream>
#include <fstream>
using namespace std;

struct Park {
  string parkname;
  string state;
  int area;
};

void addPark(Park parks[], string parkname, string state, int area, int length) {
  parks[length].parkname = parkname;
  parks[length].state = state;
  parks[length].area = area;
}

void printList(const Park parks[], int length) {
  for (size_t i = 0; i < length; i++) {
    cout << parks[i].parkname <<" [" << parks[i].state << "] area: "<< parks[i].area << endl;
  }
}

int main(int argc, char const *argv[]) {
  int len = 0;
  Park parks[100];
  ifstream ifile("park.csv");
  string line;
  string pname = "";
  string pstate = "";
  string parea = "";
  while (!ifile.eof()) {
    int i = 0;
    int j = 0;
    getline(ifile, line);
    for (i = 0; i < line.length(); i++) {
      if (line[i] == ',' && i == j) {
        for (j = 0; j < i; j++) {
          pname = pname + line[j];
        }
        i++;
        for (j = i; j < i+2; j++) {
          pstate = pstate + line[j];
        }
        i++;
        for (j = i+2; j < line.length(); j++) {
          parea = parea + line[j];
        }
        i = line.length();
      }
      j++;
    }
    if (parea != "") {
      addPark(parks, pname, pstate, stoi(parea), len);
    }
    len++;
    pname = "";
    pstate = "";
    parea = "";
  }
  printList(parks, len-1);
  ifile.close();
  ofstream ofile("output.csv");
  for (int i = 0; i < len-1; i++) {
    if (parks[i].area > stoi(argv[1])) {
      ofile << parks[i].parkname << "," << parks[i].state << "," << parks[i].area << endl;
    }
  }
  ofile.close();

  return 0;
}
