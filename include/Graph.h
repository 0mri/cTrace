#ifndef GRAPH_H_
#define GRAPH_H_
#include <vector>
#include "Tree.h"
#include <queue>
#include <string>
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

  vector<int> *getNeighbors(int nodeInd);

  void changeStatus(int nodeInd, VertexStatus vs);

  bool hasEdge(int i, int j);

  VertexStatus getNodeStatus(int nodeInd);

  vector<vector<int>> &getEdges();

  vector<VertexStatus> getVertexes();

  //??
  Tree &bfs(Session &session, int nodeInd);

  //!!
  std::string getStatus(int nodeInd);
  void print();

private:
  std::vector<VertexStatus> vertex;
  std::vector<std::vector<int>> edges;
};

#endif
