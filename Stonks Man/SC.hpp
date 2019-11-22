#ifndef SC
#define SC
#include<vector>
#include<queue>

using namespace std;

struct city;

struct stock {
  stock() {
    this->price = 0.0;
    this->owned = 0;
  }
  string abb;
  float price;
  int owned;
  queue<float> next;
};


struct road{
  city *c;
  int weight;
  int cost;
};

struct city{
  city() {
    this->visited = false;
    this->pred = NULL;
    this->ends = " ";
    this->tax = 0;
  }
  string name;
  string title;
  string ends;
  bool visited;
  int distance;
  int tax;
  int cost;
  city *pred;
  vector<road> roads;
  vector<stock*> stocks;
};

#endif
