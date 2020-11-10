#include <iostream>
#include <fstream>
#include <vector>
#include "json.hpp"

#include "Session.h"
#include "Agent.h"


// #include "Graph.h"

using namespace std;
using json = nlohmann::json;


Session::Session(const string &path)
{
    std::ifstream i(path);
    json j_input;
    i >> j_input;

    Graph *g1 = new Graph(j_input["graph"]);
    g = *g1;

    if (j_input["tree"] == "C")
        this->treeType = Cycle;
    else if (j_input["tree"] == "R")
        this->treeType = Root;
    else if (j_input["tree"] == "M")
        this->treeType = MaxRank;

    // vector <int> *input_agents = &j_input["agents"];
    cout << j_input["agents"] << endl;
    for (int i = 0; i < j_input["agents"].size(); i++)
    {
        if (j_input["agents"][i][0] == ("V"))
            Agent *a = new Virus(j_input["agents"][i][1]);
        else if (j_input["agents"][i][0] == ("C"))
            Agent *c = new ContactTracer();
    }
}

void Session::simulate()
{
    cout << this << endl;
    cout << "simulate" << endl;

    // t
    // this->g.print();
    // TreeType a = this->getTreeType();
    // cout << a << endl;
}

void Session::setGraph(const Graph &graph)
{
    this->g = graph;
}

TreeType Session::getTreeType() const
{
    return treeType;
}