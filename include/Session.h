#ifndef SESSION_H_
#define SESSION_H_

#include <vector>
#include "Graph.h"
#include <string>
#include <queue>
class Agent;

enum TreeType
{
  Cycle,
  MaxRank,
  Root
};

class Session
{
public:
  Session(const std::string &path);
  Session();

  Session(const Session &other);
  Session &operator=(const Session &other);
  Session &operator=(Session &&other);
  Session(Session &&other);
  virtual ~Session();

  void simulate();
  void addAgent(const Agent &agent);
  void setGraph(const Graph &graph);

  void enqueueInfected(int);
  int dequeueInfected();

  TreeType getTreeType() const;

  Graph &getGraph();
  int getCurrCycle() const;

  bool isDone();
  void json_output();

private:
  Graph g;
  TreeType treeType;
  std::vector<Agent *> agents;
  std::queue<int> infected_queue;
  int currCycle;
};

#endif
