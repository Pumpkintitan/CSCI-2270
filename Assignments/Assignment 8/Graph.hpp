#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>
using namespace std;

struct vertex;
struct adjVertex{
    vertex *v;
};

struct vertex{
    vertex() {
        this->visited = false;
        this->color = "";
        this->distance = 0;
    }
    string name;
    bool visited;
    string color;
    int distance;
    vector<adjVertex> adj;
};

class Graph
{
    public:
        void addEdge(string v1, string v2);
        void addVertex(string name);
        void displayEdges();
        void breadthFirstTraverse(string sourceVertex);
        int getConnectedComponents();
        bool checkBipartite();

    private:
        vector<vertex*> vertices;
};

#endif // GRAPH_H
