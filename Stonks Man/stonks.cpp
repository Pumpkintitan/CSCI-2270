#include <iostream>
#include <string>
#include <vector>
#include "Game.hpp"
#include "Game.cpp"
#include "Player.cpp"

using namespace std;

void title() {
  cout << "__      __   _                    _         ___ _____ ___  _  _ _  _____   __  __   _   _  _ " << endl;
  cout << "\\ \\    / /__| |__ ___ _ __  ___  | |_ ___  / __|_   _/ _ \\| \\| | |/ / __| |  \\/  | /_\\ | \\| |" << endl;
  cout << " \\ \\/\\/ / -_) / _/ _ \\ '  \\/ -_) |  _/ _ \\ \\__ \\ | || (_) | .` | ' <\\__ \\ | |\\/| |/ _ \\| .` |" << endl;
  cout << "  \\_/\\_/\\___|_\\__\\___/_|_|_\\___|  \\__\\___/ |___/ |_| \\___/|_|\\_|_|\\_\\___/ |_|  |_/_/ \\_\\_|\\_|" << endl;
  cout << "The interactive travel and stock trading game" << endl << endl;
}

void rules() {
  cout << "~~~~~~How to Play~~~~~~" << endl;
  cout << "You are a businessman who is trying to get lucky and become a millionare by playing the stock market." << endl;
  cout << "There are 4 actions you can take:" << endl;
  cout << "  1. Travel to a different city:" << endl;
  cout << "    - This lets you travel to any city on the map but it takes time and money to travel." << endl;
  cout << "  2. View stocks:" << endl;
  cout << "    - This allows you to look at all the stocks on the market and see their prices, as well as a 5-day" << endl;
  cout << "     forecast on what the change in price could be." << endl;
  cout << "  3. Buy/Sell stocks:" << endl;
  cout << "    - Lets you sell any stock you have for the specified price, but you can only buy certain stocks in" << endl;
  cout << "      certain cities." << endl;
  cout << "  4. Wait:" << endl;
  cout << "    - The wait function lets you pass time in your current city, but you have to pay money for each day" << endl;
  cout << "The overall goal is to make $1,000,000 while starting out with a measly $10,000. Have fun!" << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void gmenu() {
  cout << "What would you like to do?" << endl;
  cout << "1. Travel to a different city" << endl;
  cout << "2. View stocks" << endl;
  cout << "3. Buy/Sell stocks" << endl;
  cout << "4. Wait" << endl;
  cout << "5. Exit Game" << endl;
}

int main(int argc, char const *argv[]) {
  int choice = 0;
  int days = 0;
  int choice2 = 0;
  int num = 0;
  string city1,city2,stock;
  bool menu = true;
  bool start = false;
  Game G;
  while (menu) {
    if (choice == 0) {
      title();
    }
    cout << "1. Start Game" << endl;
    cout << "2. How to Play" << endl;
    cout << "3. Exit Game" << endl << ">";
    cin >> choice;
    switch (choice) {
      case 1:
        G.startGame();
        start = true;
      case 3:
        menu = false;
      break;
      case 2:
        rules();
      break;
    }
  }
  while (start) {
    gmenu();
    cout << ">";
    cin >> choice;
    switch (choice) {
      case 1:
        G.displayMap();
        cout << "Which city would you like to go to?" << endl << ">";
        cin >> city2;
        if (G.searchCity(city2) != NULL) {
          cout << "How do you want to get there: cheapest(1) or quickest(2)" << endl << ">";
          cin >> choice2;
          cout << "Traveling from " << G.P.city << " to " << city2 << "..." << endl;
          city* final = NULL;
          if (choice2 == 2) {
            final = G.tDays(G.P.city, city2);
          } else {
            final = G.tMoney(G.P.city, city2);
          }
          G.passDays(final->distance, true);
          G.P.money = G.P.money - final->cost;
          cout << "It took " << final->distance << " days and $" << final->cost << " to travel to " << city2 << endl;
          G.P.printMoney();
          G.changeCity(G.P.city, city2);
        } else {
          cout << "City does not exist" << endl;
        }
      break;
      case 2:
        cout << "All stocks(1) or local stocks(2)?" << endl << ">";
        cin >> choice2;
        if (choice2 == 2) {
          G.displayMap();
          cout << "Which city would you like to view?" << endl << ">";
          cin >> city1;
          if (G.searchCity(city1) != NULL) {
            G.printStocks(city1);
          } else {
            cout << "City does not exist" << endl;
          }
        } else {
          G.allfd();
          cout << endl;
        }
      break;
      case 3:
        cout << "Do you want to buy(1) or sell(2)?" << endl << ">";
        cin >> choice2;
        cout << endl;
        if (choice2 == 1) {
          G.printStocks(G.P.city);
          cout << endl;
          G.P.printMoney();
          cout << "Which stock would you like to buy?" << endl << ">";
          cin >> stock;
          cout << "How many would you like to buy?" << endl << ">";
          cin >> num;
          if (G.searchStock(stock) != NULL && G.stockInCity(G.searchStock(stock), G.searchCity(G.P.city))) {
            G.P.buyStock(G.searchStock(stock), num);
          } else {
            cout << "Stock does not exist" << endl;
          }
        } else if (choice2 == 2) {
          if (G.P.inv.size() <= 0) {
            cout << "You have no stocks to sell" << endl;
          } else {
            G.printOwnedStocks();
            cout << endl;
            cout << "Which stock would you like to sell?" << endl << ">";
            cin >> stock;
            cout << "How many would you like to sell?" << endl << ">";
            cin >> num;
            if (G.searchStock(stock) != NULL && G.stockInInv(G.searchStock(stock))) {
              G.P.sellStock(G.searchStock(stock), num);
            } else {
              cout << "Stock does not exist" << endl;
            }
          }
        }
        G.updateOwnedStocks();
        G.P.printMoney();
      break;
      case 4:
        cout << "How many days would you like to wait?" << endl << ">";
        cin >> days;
        G.passDays(days, false);
        G.P.printMoney();
        break;
      case 5:
        start = false;
      break;
    }
    if (G.P.checkWin()) {
      cout << "Congratulations! You are a master investor!" << endl;
      cout << "It only took " << G.t() << " days..." << endl;
      start = false;
    }
  }
  cout << "Thanks for playing!" << endl;
  return 0;
}
