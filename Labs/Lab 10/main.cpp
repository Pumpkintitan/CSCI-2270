#include <iostream>
#include <vector>
#include "Graph.hpp"

using namespace std;


int main()
{
    Graph g; // undirected and unweighted (can be connected or disconnected)
    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 6);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    // TODO SILVER: Complete the function isbridge() in Graph.cpp,
    // this function takes an edge (key1, key2) where key1 and key2 are keys of the two end points of the edge and finds if it is a bridge.
    // A bridge is an edge of a graph whose deletion increases its number of connected components.
    bool isBridge = g.isBridge(6,1);

    if (isBridge)
      cout<< "The edge connecting vertices with keys 1 and 6 is a bridge!" << endl; //Expected
    else
     cout<<"The edge connecting vertices with keys 1 and 6 is not a bridge!" << endl;


   isBridge = g.isBridge(0,2);

   if (isBridge)
     cout<< "The edge connecting vertices with keys 0 and 2 is a bridge!" << endl;
   else
    cout<<"The edge connecting vertices with keys 0 and 2 is not a bridge!" << endl; //Expected

    return 0;
}
