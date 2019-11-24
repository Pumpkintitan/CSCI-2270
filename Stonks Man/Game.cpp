#include "Game.hpp"
#include "Player.hpp"
#include <vector>
#include <queue>
#include <iostream>
#include <time.h>
#include <cmath>

using namespace std;

//~~~~~~~~~~~~~~~~~~~~

city* Game::searchCity(string name) {
  for (size_t i = 0; i < cities.size(); i++) {
    if (cities[i]->name == name) {
      return cities[i];
    }
  }
  return NULL;
}

stock* Game::searchStock(string name) {
  for (size_t i = 0; i < stocks.size(); i++) {
    if (stocks[i]->abb == name) {
      return stocks[i];
    }
  }
  return NULL;
}

bool Game::stockInCity(stock* s, city* c) {
  for (size_t i = 0; i < c->stocks.size(); i++) {
    if (c->stocks[i]->abb == s->abb) {
      return true;
    }
  }
  return false;
}

bool Game::stockInInv(stock* s) {
  for (size_t i = 0; i < P.inv.size(); i++) {
    if (P.inv[i]->abb == s->abb) {
      return true;
    }
  }
  return false;
}

void Game::addCity(string name, vector<int> si, int tax) {
  city* c = new city;
  c->name = name;
  c->tax = tax;
  c->title = c->ends+c->name+c->ends;
  for (size_t i = 0; i < si.size(); i++) {
    stock* s = new stock;
    s = stocks[si[i]];
    c->stocks.push_back(s);
  }
  cities.push_back(c);
}

void Game::addRoad(string v1, string v2, int weight, int cost) {
  city* c1 = searchCity(v1);
  city* c2 = searchCity(v2);
  road rv;
  rv.c = c2;
  rv.weight = weight;
  rv.cost = cost;
  c1->roads.push_back(rv);
  road rv2;
  rv2.c = c1;
  rv2.weight = weight;
  rv2.cost = cost;
  c2->roads.push_back(rv2);
}

void Game::addStock(string abb, float price) {
  stock* s = new stock;
  s->abb = abb;
  s->price = price;
  for (size_t i = 0; i < 5; i++) {
    float n;
    double r = (rand()%4000)/10000.0 + 0.8;
    if (i != 0) {
      n = ceil((r*s->next.back())*100)/100;
    } else {
      n = ceil((r*s->price)*100)/100;
    }
    s->next.push(n);
  }
  stocks.push_back(s);
}

void Game::printStocks(string name) {
  city* c = searchCity(name);
  cout << endl;
  int space = (15-c->name.size())/2;
  for (size_t i = 0; i < space; i++) {
    cout << " ";
  }
  cout << c->name << endl;
  cout << "-------------" << endl;
  for (size_t i = 0; i < c->stocks.size(); i++) {
    fiveDay(c->stocks[i]);
  }
}

void Game::fiveDay(stock* s) {
  cout << s->abb << " " << s->owned << " @ $" << s->price << "  Next 5 days: ";
  for (size_t i = 0; i < 5; i++) {
    float temp = s->next.front();
    if (temp > s->price) {
      cout << "+";
    } else {
      cout << "-";
    }
    cout << " ";
    s->next.pop();
    s->next.push(temp);
  }
  cout << endl;
}

void Game::updateForecast(stock* s) {
  double r = (rand()%4000)/10000.0 + 0.8;
  s->price = s->next.front();
  s->next.pop();
  float n = ceil((r*s->next.back())*100)/100;
  s->next.push(n);
}

void Game::allfd() {
  cout << "  All Stocks " << endl;
  cout << "-------------" << endl;
  for (size_t i = 0; i < stocks.size(); i++) {
    fiveDay(stocks[i]);
  }
}

void Game::passDays(int days, bool travel) {
  if (!travel) {
    if (P.money < days*(searchCity(P.city))->tax) {
      cout << "You do not have the funds to wait for " << days << " days in " << P.city << endl;
    } else {
      cout << "Waiting " << days << " days..." << endl;
      for (size_t i = 0; i < days; i++) {
        for (size_t j = 0; j < stocks.size(); j++) {
          updateForecast(stocks[j]);
        }
        trip++;
      }
      P.money = P.money - days*(searchCity(P.city))->tax;
      cout << "Spent $" << days*(searchCity(P.city))->tax << " waiting in " << P.city << endl;
    }
  } else {
    for (size_t i = 0; i < days; i++) {
      for (size_t j = 0; j < stocks.size(); j++) {
        updateForecast(stocks[j]);
      }
      trip++;
    }
  }
}

void Game::startGame() {
  srand (time(0));
  //Stocks
  addStock("GGPI", 30.99); //0
  addStock("POUP", 4.6); //1
  addStock("PEPC", 65.7); //2
  addStock("CUMB", 14.8); //3
  addStock("PEAD", 23.0); //4
  addStock("YEZY", 300.5); //5
  addStock("MCST", 150.4); //6
  addStock("XBOX", 222.2); //7
  addStock("PAJP", 55.2); //8
  addStock("APYR", 43.7); //9
  addStock("PYTN", 3.4); //10
  addStock("CCCP", 78.0); //11
  addStock("UCBD", 1.1); //12
  addStock("BSTI", 249.6); //13
  addStock("USSR", 66.7); //14
  //Cities
  addCity("Atlantis", vector<int> {5,7,13}, 50); //0
  addCity("Cheyenne", vector<int> {1,2,8,10}, 15); //1
  addCity("Robloxia", vector<int> {0,2,4,6,10}, 20); //2
  addCity("Smolensk", vector<int> {9,11,14}, 15); //3
  addCity("Coruscant", vector<int> {3,4,10,12}, 10); //4
  addCity("Lincoln", vector<int> {0,3,6,9}, 10); //5
  addCity("Boulder", vector<int> {0,1,4,12}, 20); //6
  addCity("Montgomery", vector<int> {1,3,8,11,12}, 25); //7
  changeCity("", "Robloxia");
  //Roads
  addRoad(cities[0]->name, cities[1]->name, 1, 500); //0-1
  addRoad(cities[1]->name, cities[2]->name, 2, 300); //1-2
  addRoad(cities[1]->name, cities[4]->name, 3, 100); //1-4
  addRoad(cities[2]->name, cities[3]->name, 3, 100); //2-3
  addRoad(cities[2]->name, cities[6]->name, 2, 300); //2-6
  addRoad(cities[2]->name, cities[7]->name, 3, 100); //2-7
  addRoad(cities[3]->name, cities[6]->name, 2, 300); //3-6
  addRoad(cities[4]->name, cities[5]->name, 4, 25); //4-5
  addRoad(cities[4]->name, cities[7]->name, 3, 100); //4-7
  addRoad(cities[5]->name, cities[6]->name, 4, 25); //5-6
  //Map
  displayMap();
}

void Game::changeCity(string prev, string newc) {
  if (prev != "") {
    city* p = searchCity(prev);
    p->ends = " ";
    p->title = p->ends + p->name + p->ends;
  }
  city* n = searchCity(newc);
  n->ends = "*";
  n->title = n->ends + n->name + n->ends;
  P.city = n->name;
}

void Game::displayMap() {
  cout << "                                                --" << cities[3]->title << endl;
  cout << "                                            ---/      \\" << endl;
  cout << "                               -" << cities[2]->title << "-/           \\" << endl;
  cout << "                             -/     |     \\-           |" << endl;
  cout << "                           -/       |       \\--        \\" << endl;
  cout << "                         -/         |          \\-       \\" << endl;
  cout << cities[0]->title << "---" << cities[1]->title << "-/           |            \\--     \\" << endl;
  cout << "                   \\                |               \\-" << cities[6]->title << endl;
  cout << "                    |               |                     |" << endl;
  cout << "                    \\               |                     |" << endl;
  cout << "                     |      " << cities[7]->title << "                  /" << endl;
  cout << "                     \\           |                       |" << endl;
  cout << "                      |         /                        /" << endl;
  cout << "                      \\        /                        /" << endl;
  cout << "                       |      /                        |" << endl;
  cout << "                       \\     /                         /" << endl;
  cout << "                        |   |                         |" << endl;
  cout << "                   " << cities[4]->title << "--------------------" << cities[5]->title << endl << endl;
}

void Game::printOwnedStocks() {
  for (size_t i = 0; i < P.inv.size(); i++) {
    fiveDay(P.inv[i]);
  }
}

void Game::updateOwnedStocks() {
  vector<stock*> temp;
  for (size_t i = 0; i < stocks.size(); i++) {
    if (stocks[i]->owned > 0) {
      temp.push_back(stocks[i]);
    }
  }
  P.inv = temp;
}

void Game::setAllCitiesUnvisited() {
  for (size_t i = 0; i < cities.size(); i++) {
    cities[i]->visited = false;
    cities[i]->cost = 0;
    cities[i]->distance = 0;
  }
}

city* Game::tMoney(string start, string end) {
  setAllCitiesUnvisited();
  vector<city*> solved;
  city* sc;
  city* ec;
  for (size_t i = 0; i < cities.size(); i++) {
    if (cities[i]->name == start) {
      sc = cities[i];
      sc->visited = true;
      solved.push_back(sc);
    }
    if (cities[i]->name == end) {
      ec = cities[i];
    }
  }
  city* c = NULL;
  while (!ec->visited) {
    int minMoney = 9999999;
    int days = 0;
    c = NULL;
    for (size_t i = 0; i < solved.size(); i++) {
      for (size_t j = 0; j < solved[i]->roads.size(); j++) {
        if (!solved[i]->roads[j].c->visited) {
          int money = solved[i]->cost + solved[i]->roads[j].cost;
          if (money < minMoney) {
            days = solved[i]->distance + solved[i]->roads[j].weight;
            c = solved[i]->roads[j].c;
            minMoney = money;
            solved[i]->roads[j].c->pred = solved[i];
            c->pred = solved[i];
          }
        }
      }
    }
    c->distance = days;
    c->cost = minMoney;
    c->visited = true;
    solved.push_back(c);
  }
  ec->cost = c->cost;
  ec->distance = c->distance;
  return ec;
}

city* Game::tDays(string start, string end) {
  setAllCitiesUnvisited();
  vector<city*> solved;
  city* sc;
  city* ec;
  for (size_t i = 0; i < cities.size(); i++) {
    if (cities[i]->name == start) {
      sc = cities[i];
      sc->visited = true;
      solved.push_back(sc);
    }
    if (cities[i]->name == end) {
      ec = cities[i];
    }
  }
  city* c = NULL;
  while (!ec->visited) {
    int minDays = 9999999;
    int money = 0;
    c = NULL;
    for (size_t i = 0; i < solved.size(); i++) {
      for (size_t j = 0; j < solved[i]->roads.size(); j++) {
        if (!solved[i]->roads[j].c->visited) {
          int days = solved[i]->distance + solved[i]->roads[j].weight;
          if (days < minDays) {
            money = solved[i]->cost + solved[i]->roads[j].cost;
            c = solved[i]->roads[j].c;
            minDays = days;
            solved[i]->roads[j].c->pred = solved[i];
            c->pred = solved[i];
          }
        }
      }
    }
    c->cost = money;
    c->distance = minDays;
    c->visited = true;
    solved.push_back(c);
  }
  ec->cost = c->cost;
  ec->distance = c->distance;
  return ec;
}

int Game::t() {
  return trip;
}
