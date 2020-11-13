#include "Agent.h"
#include <iostream>
ContactTracer::ContactTracer() : Agent() {}

void ContactTracer::act(Session &session)
{
    int nodeInd = session.dequeueInfected();
    if (nodeInd != -1)
    {

        Tree *root = Tree::createTree(session, nodeInd);
        // root->BFS(session);
        int toIsolate = root->traceTree();
        session.getGraph().isolateNode(toIsolate);
        delete (root);
        root = nullptr;
    }
}

ContactTracer *ContactTracer::clone() const
{
    return new ContactTracer(*this);
}