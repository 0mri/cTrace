#ifndef GRAPH_H_
#define GRAPH_H_
#include <vector>

class Graph{
public:
    Graph();
    Graph(std::vector<std::vector<int>> matrix);
    Graph& operator=(const Graph& other);
    Graph& operator=(const Graph&& other);
    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);
    void print();
    
private:

    std::vector<std::vector<int>> edges;
    
    
};

#endif

