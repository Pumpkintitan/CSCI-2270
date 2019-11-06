#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void DFTraversal(vertex *n) {
  n->visited = true;
  for(size_t x = 0; x < n->adj.size(); x++) {
    if (!n->adj[x].v->visited) {
      cout << n->adj[x].v->name << " --> ";
      DFTraversal(n->adj[x].v);
    }
  }
}

//----------------------

void Graph::addEdge(string v1, string v2, int num) {
  for(int i = 0; i < vertices.size(); i++) {
    if(vertices[i]->name == v1) {
      for(int j = 0; j < vertices.size(); j++) {
        if(vertices[j]->name == v2 && i != j) {
          adjVertex av;
          av.v = vertices[j];
          av.weight = num;
          vertices[i]->adj.push_back(av);
          adjVertex av2;
          av2.v = vertices[i];
          av2.weight = num;
          vertices[j]->adj.push_back(av2);
        }
      }
    }
  }
}

void Graph::addVertex(string name) {
  bool found = false;
  for(int i = 0; i < vertices.size(); i++){
    if(vertices[i]->name == name) {
      found = true;
    }
  }
  if(found == false) {
    vertex * v = new vertex;
    v->name = name;
    vertices.push_back(v);
  }
}


void Graph::displayEdges() {
  for(size_t i = 0; i < vertices.size(); i++) {
    cout << vertices[i]->name << " --> ";
    for(size_t j = 0; j < vertices[i]->adj.size(); j++) {
      cout << vertices[i]->adj[j].v->name << "(" << vertices[i]->adj[j].weight << ") ";
    }
    cout << endl;
  }
}


void Graph::depthFirstTraversal(string sourceVertex) {
  for (size_t i = 0; i < vertices.size(); i++) {
    if (vertices[i]->name == sourceVertex) {
      cout << vertices[i]->name << " --> ";
      DFTraversal(vertices[i]);
      cout << "Done" << endl;
    }
  }
}

vertex* Graph::DijkstraAlgorithm(string start, string end) {
  setAllVerticesUnvisited();
  vector<vertex*> solved;
  vertex* sv;
  vertex* ev;
  for (size_t i = 0; i < vertices.size(); i++) {
    if (vertices[i]->name == start) {
      sv = vertices[i];
      sv->visited = true;
      solved.push_back(sv);
    }
    if (vertices[i]->name == end) {
      ev = vertices[i];
    }
  }
  vertex* n = NULL;
  while (!ev->visited) {
    int minDist = 9999999;
    n = NULL;
    for (size_t i = 0; i < solved.size(); i++) {
      for (size_t j = 0; j < solved[i]->adj.size(); j++) {
        if (!solved[i]->adj[j].v->visited) {
          int dist = solved[i]->distance + solved[i]->adj[j].weight;
          if (dist < minDist) {
            n = solved[i]->adj[j].v;
            minDist = dist;
            solved[i]->adj[j].v->pred = solved[i];
            n->pred = solved[i];
          }
        }
      }
    }
    n->distance = minDist;
    n->visited = true;
    solved.push_back(n);
  }
  ev->distance = n->distance;
  cout << "Dijkstra's Shortest distance from " << start << " to " << end << ": " << ev->distance << endl;
  return ev;
}

void Graph::shortestpath(string start, string end) {
  vector<string> path;
  vertex* endv = NULL;
  for (size_t i = 0; i < vertices.size(); i++) {
    if (vertices[i]->name == end) {
      endv = vertices[i];
    }
  }
  path.push_back(endv->name);
  while (endv->name != start) {
    path.push_back(endv->pred->name);
    endv = endv->pred;
  }
  for (size_t i = path.size(); i > 0; i--) {
    cout << path[i-1] << " ";
  }
  cout << endl;
}

void Graph::setAllVerticesUnvisited() {
  int i;
  for(i=0; i<vertices.size(); i++) {
    vertices[i]->visited = false;
  }
}
