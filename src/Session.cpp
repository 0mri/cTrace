#include <iostream>
#include <fstream>
#include <vector>
#include "json.hpp"

#include "Session.h"
#include "Agent.h"

// #include "Graph.h"

using namespace std;
using json = nlohmann::json;

Session::Session(const string &path) : g(), treeType(), agents()
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
    for (int i = 0; i < j_input["agents"].size(); i++)
    {
        if (j_input["agents"][i][0] == ("V"))
            agents.push_back(new Virus(j_input["agents"][i][1]));
        else if (j_input["agents"][i][0] == ("C"))
            agents.push_back(new ContactTracer());
    }
}

void Session::simulate()
{
    cout << this << endl;
    cout << "simulate" << endl;

    cout << "agents[0]" << agents.size() << endl;

    vector<Agent*>::iterator ptr; 
    for (ptr = agents.begin(); ptr < agents.end(); ptr++)
        agent_queue.push(*ptr);


    vector<Agent*>::iterator ptr2; 
    for (ptr2 = agents.begin(); ptr2 < agents.end(); ptr2++)
        (*ptr2)->act(*this);
        
    cout << "adress of agents queue" << this->agent_queue.size() << endl;

    this->g.print();
    // t
    // this->g.print();
    // TreeType a = this->getTreeType();
    // cout << a << endl;



    //### output to JSON ####
    std::ofstream o("output.json");
    json j_output;


    vector <int> a = {1,2,3,4};
    // j_output["Array"] = this->g;
    o  << j_output << std::endl;
}

void Session::setGraph(const Graph &graph)
{
    this->g = graph;
}

TreeType Session::getTreeType() const
{
    return treeType;
}