#include "Graph.hpp"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  Graph g;
  g.addVertex("A");
  g.addVertex("B");
  g.addVertex("C");
  g.addVertex("D");
  g.addVertex("E");
  g.addVertex("F");
  g.addEdge("A", "B", 10);
  g.addEdge("A", "C", 30);
  g.addEdge("A", "E", 20);
  g.addEdge("A", "F", 30);
  g.addEdge("B", "C", 15);
  g.addEdge("E", "D", 30);
  g.addEdge("E", "F", 5);
  g.displayEdges();
  g.shortestpath("B", "F");
  /*
      B--15--C
      \     /
      10   30
       \  /
        A
       / \
     30  20
     /    \
    F---5--E--30--D
  */
  return 0;
}
