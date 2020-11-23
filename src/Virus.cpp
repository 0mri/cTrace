#include "Agent.h"
#include "Session.h"
#include <iostream>

Virus::Virus(int index) : Agent(), nodeInd(index) {}

void Virus::act(Session &session)
{
    cout << "Virus act" << endl;

    Graph &g1 = session.getGraph();
    if (!g1.isInfected(nodeInd)) //if this node is not infected
    {
        g1.infectNode(nodeInd);
        session.enqueueInfected(nodeInd);
    }
    int nr_nbr = g1.nearestNeighbor(nodeInd);
    if (nr_nbr != -1) //if there is neighbors
    {
        Agent *new_virus = new Virus(nr_nbr);
        session.addAgent(*new_virus);
        g1.changeStatus(nr_nbr, Carrier);

        delete new_virus;
        new_virus = nullptr;
    }
}

Virus *Virus::clone() const
{
    return new Virus(*this);
}