#include <iostream>
#include <vector>
#include "Graph.hpp"

using namespace std;


int main()
{
    Graph g; // undirected and unweighted
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(1, 4);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(3, 4);
    g.addEdge(5, 6);

    // TODO Silver: Find the length of the shortest path between the source and destination vertex (complete the findShortestPath function)
    int length = g.findShortestPath(1, 6); // Expected: 2

    if(length!=-1)
    {
      cout << "Shortest path length = "<< length<< endl;

      // TODO Gold: Give the shortest path: modify the findShortestPath function, then complete the printPath function and print the path inside this function
      g.printPath(1,6) ; // Expected: 1 4 6

      cout<< endl;
    }

    else
    {
      cout<< "source and destination are not connected" << endl;
    }

    return 0;
}
