#ifndef GAME_H
#define GAME_H
#include<vector>
#include<queue>
#include<iostream>
#include "SC.hpp"
#include "Player.hpp"
using namespace std;

class Game {
  public:
    void addCity(string name, vector<int> si, int tax);
    void addRoad(string v1, string v2, int weight, int cost);
    void addStock(string abb, float price);
    void printStocks(string name);
    city* searchCity(string name);
    stock* searchStock(string name);
    void updateForecast(stock* s);
    void fiveDay(stock* s);
    void allfd();
    void passDays(int days, bool travel);
    void startGame();
    void changeCity(string prev, string newc);
    void displayMap();
    void printOwnedStocks();
    void updateOwnedStocks();
    bool stockInCity(stock* s, city* c);
    bool stockInInv(stock* s);
    city* tDays(string start, string end);
    city* tMoney(string start, string end);
    void setAllCitiesUnvisited();
    int t();
    Player P;
  private:
    int trip = 0;
    vector<city*> cities;
    vector<stock*> stocks;
};

#endif
