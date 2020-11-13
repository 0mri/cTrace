#include "Agent.h"
#include "Session.h"
#include <iostream>
//Constructor
//Copy Constructor
//distructor

Virus::Virus(int index) : Agent(), nodeInd(index) {}


void Virus::act(Session &session)
{
    Graph &g1 = session.getGraph();
    if (!g1.isInfected(nodeInd))
    {
        g1.infectNode(nodeInd);
        session.enqueueInfected(nodeInd);
    }
    int neighbor = g1.nearestNeighbor(nodeInd);
    if (neighbor != -1)
    {
        g1.changeStatus(neighbor, Carrier);
        Agent *v1 = new Virus(neighbor);
        session.addAgent(*v1);
        delete (v1);
        v1 = nullptr;
    }
}

Virus *Virus::clone() const
{
    return new Virus(*this);
}