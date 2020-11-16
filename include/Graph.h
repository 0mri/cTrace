#ifndef GRAPH_H_
#define GRAPH_H_
#include <vector>
#include "Tree.h"
enum VertexStatus
{
  Healthy,
  Sick,
  Carrier
};
class Graph
{
public:
  Graph();
  Graph(std::vector<std::vector<int>> matrix);

  void infectNode(int nodeInd);

  bool isInfected(int nodeInd);

  void isolateNode(int nodeInd);

  int nearestNeighbor(int nodeInd);

  void changeStatus(int nodeInd, VertexStatus vs);

  bool hasEdge(int i, int j);

  VertexStatus getNodeStatus(int nodeInd);

  char getStatus(int nodeInd);

  vector<vector<int>> getGraph();

  void print();

  Tree &BFS(const Session &sess, int nodeInd);

private:
  std::vector<VertexStatus> vertex;
  std::vector<std::vector<int>> edges;
};

#endif
