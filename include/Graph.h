#ifndef GRAPH_H_
#define GRAPH_H_
#include <vector>
#include "Tree.h"
#include "Session.h"

enum VertexStatus{
  Healthy,
  Sick,
  Carrier
};
class Graph{
public:
    Graph();
    Graph(std::vector<std::vector<int>> matrix);
    Graph& operator=(const Graph& other);
    Graph& operator=(const Graph&& other);
    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);
    Tree BFS(int start, Session &s);
    void print();
    
    Tree& BFS(Session &sess);
    
private:
    std::vector<VertexStatus> vertex;
    std::vector<std::vector<int>> edges;
    
    
};

#endif

