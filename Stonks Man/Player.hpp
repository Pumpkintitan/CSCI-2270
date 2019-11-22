#ifndef PLAYER_H
#define PLAYER_H
#include<vector>
#include<queue>
#include<iostream>
#include "SC.hpp"
#include "Game.hpp"
using namespace std;

class Player {
  public:
    void printMoney();
    void buyStock(stock* s, int num);
    void sellStock(stock* s, int num);
    bool checkWin();
    string city;
    vector<stock*> inv;
    float money = 10000;
};

#endif
