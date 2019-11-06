#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>
using namespace std;

struct vertex;
struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    vertex() {
        this->visited = false;
        this->distance = 0;
        this ->pred = NULL;
    }
    string name;
    bool visited;
    int distance;
    vertex *pred;
    vector<adjVertex> adj;
};

class Graph
{
    public:
        void addEdge(string v1, string v2, int num);
        void addVertex(string name);
        void displayEdges();
        void depthFirstTraversal(string sourceVertex);
        vertex* DijkstraAlgorithm(string start, string end);
        void shortestpath(string start, string end);
        void setAllVerticesUnvisited();

    private:
        vector<vertex*> vertices;
};

#endif // GRAPH_H
