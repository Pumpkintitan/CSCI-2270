#include "MovieTree.cpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
  MovieTree MT;
  ifstream ifile(argv[1]);
  string ranking, title, year, rating, ititle;
  while(getline(ifile, ranking, ',')) {
    getline(ifile, title, ',');
    getline(ifile, year, ',');
    getline(ifile, rating);
    MT.addMovie(stoi(ranking), title, stoi(year), stof(rating));
  }
  int choice = 0;
  while (choice != 3) {
    cout << "======Main Menu======" << endl;
    cout << "1. Print the inventory" << endl;
    cout << "2. Delete a movie" << endl;
    cout << "3. Quit" << endl;
    cin >> choice;
    switch(choice) {
      case 1:
      MT.printMovieInventory();
      break;
      case 2:
      cout << "Enter a movie title:" << endl;
      cin.ignore();
      getline(cin, ititle);
      MT.deleteMovie(ititle);
      break;
      case 3:
      cout << "Goodbye!" << endl;
      break;
    }
  }
  return 0;
}
