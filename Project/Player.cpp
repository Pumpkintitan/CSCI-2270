#include "Game.hpp"
#include "Player.hpp"
#include <vector>
#include <queue>
#include <iostream>
#include <time.h>
#include <cmath>

using namespace std;

//~~~~~~~~~~~~~~~~~~~~

void Player::printMoney() {
  cout << "Current money: $" << money << endl;
}

void Player::buyStock(stock* s, int num) {
  if (money - (s->price * num) > 0) {
    money = money - (s->price * num);
    s->owned += num;
    cout << "Bought " << num << " shares of " << s->abb << " at $" << s->price << " each for a total of $" << s->price * num << endl;
  } else {
    cout << "You don't have enough money" << endl;
  }
}

void Player::sellStock(stock* s, int num) {
  if (s->owned - num >= 0) {
    money = money + (s->price * num);
    s->owned -= num;
    cout << "Sold " << num << " shares of " << s->abb << " at $" << s->price << " each for a total of $" << s->price * num << endl;
  } else {
    cout << "You don't have that many stocks"<< endl;
  }
}

bool Player::checkWin() {
  if (money >= 1000000) {
    return true;
  }
  return false;
}
