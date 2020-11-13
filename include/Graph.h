#ifndef GRAPH_H_
#define GRAPH_H_
#include <vector>
#include "Tree.h"
enum VertexStatus{
  Healthy,
  Sick,
  Carrier
};
class Graph{
public:
    Graph();
    Graph(std::vector<std::vector<int>> matrix);

    void infectNode(int nodeInd);

    bool isInfected(int nodeInd);

    void isolateNode(int nodeInd);

    int nearestNeighbor(int nodeInd);

    void changeStatus(int nodeInd, VertexStatus vs);

    void print();
    
    Tree& BFS(Session &sess);
    
private:
    std::vector<VertexStatus> vertex;
    std::vector<std::vector<int>> edges;
    
    
};

#endif

