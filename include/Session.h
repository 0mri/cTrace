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
   
    Session(const Session &other);
    Session& operator=(const Session &other);
    Session& operator=(Session&& other);
    Session(Session&& other);
    virtual ~Session();



    void simulate();
    void addAgent(const Agent& agent);
    void setGraph(const Graph& graph);
    
    int enqueueInfected(int);
    int dequeueInfected();
    
    TreeType getTreeType() const;
    
    Graph& getGraph();
    bool isDone();
    void JSON_Output();

private:
    std::queue <int> infected_queue;
    std::vector<Agent*> agents;
    Graph g;
    TreeType treeType;
    int curCycle;
};

#endif
