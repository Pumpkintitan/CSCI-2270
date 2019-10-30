#include "Graph.hpp"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  Graph g;
  g.addVertex("A");
  g.addVertex("B");
  g.addEdge("A", "B");
  g.addVertex("C");
  g.addEdge("C", "A");
  g.addEdge("B", "C");
  g.addVertex("D");
  g.addVertex("E");
  g.addEdge("D", "E");
  g.addVertex("F");
  g.displayEdges();
  g.breadthFirstTraverse("B");
  cout << endl << g.getConnectedComponents() << endl << g.checkBipartite();
  return 0;
}
