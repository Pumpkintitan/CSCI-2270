#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>

struct vertex;

struct adjVertex{
    vertex *v;
};

struct vertex{
    int key;
    bool visited = false;
    int distance = 0;
    std::vector<adjVertex> adj;
};

class Graph
{
    public:
        void addEdge(int v1, int v2);
        void addVertex(int v);
        bool isBridge(int key1, int key2);
        void removeEdge(int key1, int key2);
        void DFTraversal(vertex *n);
        void setAllVerticesUnvisited();
        void printGraph();


    private:
        std::vector<vertex*> vertices;

};

#endif
