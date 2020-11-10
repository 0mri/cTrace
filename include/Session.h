#ifndef SESSION_H_
#define SESSION_H_

#include <vector>
#include "Graph.h"
#include <string>
#include <queue>  
class Agent;

enum TreeType{
  Cycle,
  MaxRank,
  Root
};

class Session{
public:
    Session(const std::string& path);
    
    void simulate();
    void addAgent(const Agent& agent);
    void setGraph(const Graph& graph);
    
    int enqueueInfected(int);
    int dequeueInfected();
    TreeType getTreeType() const;
    
private:
    queue <Agent> agent_queue;
    Graph g;
    TreeType treeType;
    std::vector<Agent*> agents;
};

#endif
