#include <iostream>
#include <fstream>
#include <vector>
#include "json.hpp"
#include "Session.h"
#include "Agent.h"
#include "Graph.h"

using namespace std;
using json = nlohmann::json;
//Constructor
Session::Session(const string &path) : g(), treeType(), agents(), infected_queue(), currCycle(0)
{
    std::ifstream i(path);
    json j_input;
    i >> j_input;

    Graph *g1 = new Graph(j_input["graph"]);
    this->g = *g1;
    // g = Graph(j_input["graph"]);
    if (j_input["tree"] == "C")
        this->treeType = Cycle;
    else if (j_input["tree"] == "R")
        this->treeType = Root;
    else if (j_input["tree"] == "M")
        this->treeType = MaxRank;

    for (uint i = 0; i < j_input["agents"].size(); i++)
        if (j_input["agents"][i][0] == ("V"))
            agents.push_back(new Virus(j_input["agents"][i][1]));
        else if (j_input["agents"][i][0] == ("C"))
            agents.push_back(new ContactTracer());
}

// Copy constructor
Session::Session(const Session &other) : infected_queue(other.infected_queue), agents(), g(other.g), treeType(other.treeType), currCycle(other.currCycle)
{
    for (uint i = 0; i <= other.agents.size(); i++)
        this->agents.push_back(other.agents[i]->clone());
}

// Copy Assignment Operator
Session &Session::operator=(const Session &other)
{
    this->infected_queue = other.infected_queue;
    this->g = other.g;
    this->treeType = other.treeType;
    this->currCycle = other.currCycle;

    while (agents.size() != 0)
    {
        delete agents[0];
        agents.erase(agents.begin());
    }

    for (uint i = 0; i < other.agents.size(); ++i)
        this->agents.push_back(other.agents[i]->clone());

    return *this;
}

// Move Constructor
Session::Session(Session &&other) : infected_queue(other.infected_queue), agents(other.agents), g(other.g), treeType(other.treeType), currCycle(other.currCycle)
{
    for (size_t i = 0; i < other.agents.size(); i++)
        other.agents[i] = nullptr;
}

// Move Assignment Operator
Session &Session::operator=(Session &&other)
{
    this->infected_queue = other.infected_queue;
    this->g = other.g;
    this->treeType = other.treeType;
    this->currCycle = other.currCycle;
    for (size_t i = 0; i < agents.size(); i++)
        delete agents[i];

    for (size_t i = 0; i < other.agents.size(); i++)
    {
        agents.push_back(other.agents[i]);
        other.agents[i] = nullptr;
    }
    return *this;
}

// Destructor
Session::~Session()
{
    vector<Agent *>::iterator it;
    for (it = agents.begin(); it != agents.end(); ++it)
        delete *it;
}

Graph &Session::getGraph()
{
    return g;
}

void Session::simulate()
{
    // vector<Agent *>::iterator agent;
    // for (agent = agents.begin(); agent < agents.end(); agent++)
    //     (*agent)->act(*this);
    // this->g.print();
    while (!isDone())
    {
        // cout << this->currCycle << endl;
        // for (agent = agents.begin(); agent < agents.end(); agent++)
        //     (*agent).act(*this);
        int cur_size = agents.size();
        cout << "cur_sizes" << cur_size << endl;
        for (int i = 0; i < cur_size; i++)
        {
            cout << "agent act " << endl;
            agents[i]->act(*this);
        }

        this->currCycle++;
    }
    cout << "Done!" << endl;

    this->g.print();
    this->json_output();
}

void Session::setGraph(const Graph &graph)
{
    this->g = graph;
}

void Session::enqueueInfected(int nodeInd)
{
    this->infected_queue.push(nodeInd);
}
int Session::dequeueInfected()
{

    if (infected_queue.empty())
        return -1;

    int temp = infected_queue.front();
    infected_queue.pop();
    return temp;
}

void Session::addAgent(const Agent &agent)
{
    agents.push_back(agent.clone());
}

TreeType Session::getTreeType() const
{
    return treeType;
}

bool Session::isDone()
{
    // return false;
    for (uint i = 0; i < g.getEdges().size(); i++)
    {
        VertexStatus curStatus = g.getNodeStatus(i);
        for (uint j = 0; j < g.getEdges()[i].size(); j++)
        {

            cout << i << "," << j << ", Has Edge: " << g.hasEdge(i, j) << " same status " << (g.getNodeStatus(j) == curStatus) << endl;
            if (i != j && (g.hasEdge(i, j) && g.getNodeStatus(j) != curStatus)) // return false if there is two different vertexes in the same tying componnent with deifferent status
            {
                cout << "False" << endl;
                return false;
            }
        }
    }
    return true;
}

int Session::getCurrCycle()
{
    return this->currCycle;
}

//Output to JSON file
void Session::json_output()
{
    std::ofstream o("output.json");
    json j_output;

    j_output["infected"] = {1, 2, 3, 4};

    for (size_t i = 0; i < this->getGraph().getEdges().size(); i++)
        for (size_t j = 0; j < this->getGraph().getEdges()[i].size(); j++)
        {
            j_output["graph"][i][j] = this->getGraph().getEdges()[i][j];
        }

    // j_output["graph"] = this->getGraph();
    // j_output["Array"] = this->g;
    o << j_output << std::endl;
}