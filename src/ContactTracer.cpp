#include "Agent.h"
#include "Graph.h"
#include "Tree.h"
ContactTracer::ContactTracer() : Agent() {}

void ContactTracer::act(Session &session)
{
    int nodeInd = session.dequeueInfected();
    if (nodeInd != -1)
    {
        Tree &bfs = session.getGraph().bfs(session, nodeInd);
        int node = bfs.traceTree();

        session.getGraph().isolateNode(node);

        delete &bfs;
    }
}

ContactTracer *ContactTracer::clone() const
{
    return new ContactTracer(*this);
}