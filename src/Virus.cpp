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
    if (!g1.isInfected(nodeInd)) //if this node is not infected
    {
        g1.infectNode(nodeInd);
        session.enqueueInfected(nodeInd);
    }
    int nr_nbr = g1.nearestNeighbor(nodeInd);
    if (nr_nbr != -1) //if there is neighbors
    {
        g1.changeStatus(nr_nbr, Carrier);
        Agent *v1 = new Virus(nr_nbr);
        session.addAgent(*v1);
        
        delete (v1);
        v1 = nullptr;
    }
}

Virus *Virus::clone() const
{
    return new Virus(*this);
}