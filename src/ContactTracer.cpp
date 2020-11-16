#include "Agent.h"
#include "Graph.h"
#include <iostream>
ContactTracer::ContactTracer() : Agent() {}

void ContactTracer::act(Session &session)
{
    cout << "ContactTracer act" << endl;
    int nodeInd = session.dequeueInfected();
    if (nodeInd != -1)
    {
        // root->BFS(session);
        // session.getGraph().BFS();
        // Tree *bfsTree = Graph::BFS(session, nodeInd);
        // int node = bfsTree->traceTree();
        // session.getGraph().isolateNode(node);
        // delete bfsTree;
        // bfsTree = nullptr;
    }
}

ContactTracer *ContactTracer::clone() const
{
    return new ContactTracer(*this);
}