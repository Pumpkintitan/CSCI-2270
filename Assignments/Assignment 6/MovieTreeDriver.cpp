#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "MovieTree.cpp"
using namespace std;

int main(int argc, char const *argv[]) {
  MovieTree ML;
  ifstream ifile(argv[1]);
  string ranking, title, year, rating, ititle;
  float irating;
  int iyear;
  int choice = 0;
  while(getline(ifile, ranking, ',')) {
    getline(ifile, title, ',');
    getline(ifile, year, ',');
    getline(ifile, rating);
    ML.addMovieNode(stoi(ranking), title, stoi(year), stof(rating));
  }
  while(choice != 5) {
    cout << "======Main Menu======" << endl;
    cout << "1. Find a movie" << endl;
    cout << "2. Query movies" << endl;
    cout << "3. Print the inventory" << endl;
    cout << "4. Average Rating of movies" << endl;
    cout << "5. Quit" << endl;
    cin >> choice;
    switch(choice) {
      case 1:
        cout << "Enter title:" << endl;
        cin.ignore();
        getline(cin, ititle);
        ML.findMovie(ititle);
      break;
      case 2:
        cout << "Enter minimum rating:" << endl;
        cin >> irating;
        cout << "Enter minimum year:" << endl;
        cin >> iyear;
        ML.queryMovies(irating, iyear);
      break;
      case 3:
        ML.printMovieInventory();
      break;
      case 4:
        ML.averageRating();
      break;
      case 5:
        cout << "Goodbye!" << endl;
      break;
    }
  }
  return 0;
}
