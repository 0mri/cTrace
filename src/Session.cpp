#include <iostream>
#include <fstream>
#include <vector>
#include "json.hpp"
#include "Session.h"
#include "Agent.h"
#include "Graph.h"

using namespace std;
using json = nlohmann::json;

#define JSON_PATH "output.json"

//Constructor
Session::Session(const string &path) : g(), treeType(), agents(), infected_queue(), currCycle(0)
{
    std::ifstream i(path);
    json j_input;
    i >> j_input;

    g = Graph(j_input["graph"]);

    if (j_input["tree"] == "C")
        this->treeType = Cycle;
    else if (j_input["tree"] == "R")
        this->treeType = Root;
    else
        this->treeType = MaxRank;

    for (uint i = 0; i < j_input["agents"].size(); i++)
        if (j_input["agents"][i][0] == ("V"))
        {
            int virus_ind = j_input["agents"][i][1];
            agents.push_back(new Virus(virus_ind));
            this->g.changeStatus(virus_ind, Carrier);
        }
        else if (j_input["agents"][i][0] == ("C"))
            agents.push_back(new ContactTracer());
}

// Copy constructor
Session::Session(const Session &other) : g(other.g), treeType(other.treeType), agents(), infected_queue(other.infected_queue), currCycle(other.currCycle)
{
    for (const auto &agent : other.agents)
        this->agents.push_back(agent->clone());
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

    for (const auto &agent : other.agents)
        this->agents.push_back(agent->clone());

    return *this;
}

// Move Constructor
Session::Session(Session &&other) : g(other.g), treeType(other.treeType), agents(other.agents), infected_queue(other.infected_queue), currCycle(other.currCycle)
{
    for (auto &agent : other.agents)
        agent = nullptr;
}

// Move Assignment Operator
Session &Session::operator=(Session &&other)
{
    if (this != &other)
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
        for (const auto *agent : other.agents)
        {
            agents.push_back(agent->clone());
            agent = nullptr;
        }
    }
    return *this;
}

// Destructor
Session::~Session()
{
    for (const auto agent : agents)
        delete agent;
}

Graph &Session::getGraph()
{
    return g;
}

void Session::simulate()
{
    while (!isDone())
    {
        cout << "\033[32m"
             << "Currcycle: " << this->currCycle << "\033[0m" << endl;
        int cur_size = this->agents.size();
        for (int i = 0; i < cur_size; i++)
            agents[i]->act(*this);

        this->currCycle++;
    }

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
    for (uint i = 0; i < g.getEdges().size(); i++)
        for (uint j = 0; j < g.getEdges()[i].size(); j++)
            if (i != j && (g.hasEdge(i, j) && g.getNodeStatus(j) != g.getNodeStatus(i))) // return false if there is two different vertexes in the same tying componnent with deifferent status
                return false;

    return true;
}

int Session::getCurrCycle() const
{
    return this->currCycle;
}

//Output to JSON file
void Session::json_output()
{
    std::ofstream o(JSON_PATH);
    json j_output;

    for (size_t i = 0; i < this->getGraph().getEdges().size(); i++)
        for (size_t j = 0; j < this->getGraph().getEdges()[i].size(); j++)
            j_output["graph"][i][j] = this->getGraph().getEdges()[i][j];

    vector<VertexStatus> vs = this->getGraph().getVertexes();
    int counter = 0;
    for (size_t i = 0; i < vs.size(); i++)
        if (vs[i] == Sick)
        {
            j_output["infected"][counter] = i;
            counter++;
        }
    o << j_output << std::endl;
}