#include "Graph.h"
#include <iostream>
#include <vector>
#include "Tree.h"
#include "queue"

Graph::Graph() : vertex(), edges() {}

Graph::Graph(std::vector<std::vector<int>> matrix) : vertex(matrix.size(), Healthy), edges(matrix)
{
}

bool Graph::isInfected(int nodeInd)
{
    return this->vertex[nodeInd] == Sick;
}

void Graph::infectNode(int nodeInd)
{
    this->vertex[nodeInd] = Sick;
}

void Graph::isolateNode(int nodeInd)
{
    for (uint i = 0; i < this->edges.size(); i++)
        if (this->edges[nodeInd][i] == 1)
        {
            this->edges[nodeInd][i] = 0;
            this->edges[i][nodeInd] = 0;
        }
}

void Graph::changeStatus(int nodeInd, VertexStatus vs)
{
    this->vertex[nodeInd] = vs;
}

int Graph::nearestNeighbor(int nodeInd)
{
    for (uint i = 0; i < this->edges.size(); i++)
        if (this->edges[nodeInd][i] == 1 && this->getNodeStatus(i) == Healthy)
            return i;

    return -1;
}

VertexStatus Graph::getNodeStatus(int nodeInd)
{
    return this->vertex[nodeInd];
}

bool Graph::hasEdge(int i, int j)
{
    return this->getEdges()[i][j] == 1;
}
vector<vector<int>> &Graph::getEdges()
{
    return this->edges;
}

vector<int> *Graph::getNeighbors(int nodeInd)
{
    vector<int> *neighbors = new vector<int>();
    for (uint i = 0; i < edges.size(); i++)
        if (hasEdge(i, nodeInd))
            neighbors->push_back(i);

    return neighbors;
}

vector<VertexStatus> Graph::getVertexes()
{
    return this->vertex;
}

Tree &Graph::bfs(Session &session, int nodeInd)
{
    vector<bool> v(this->vertex.size(), false);
    queue<Tree *> q;
    Tree *root = Tree::createTree(session, nodeInd);
    q.push(root);
    while (!q.empty())
    {
        Tree *parent = q.front();
        q.pop();
        vector<int> *neighbors = this->getNeighbors(parent->getNode());
        for (const auto neighbor : *neighbors)
            if (!v[neighbor])
            {
                Tree *t = Tree::createTree(session, neighbor);
                parent->addChild(t);
                int nextChildIndex = parent->getChildren().size() - 1;
                Tree *nextChild = parent->getChildren()[nextChildIndex];
                q.push(nextChild);
                v[neighbor] = true;
                delete t;
            }

        delete neighbors;
    }
    return *root;
}

//!!
void Graph::print()
{
    for (uint i = 0; i < edges.size(); i++)
    {
        std::string s = this->getStatus(i);
        cout << i << "-> " << s << " -> ";
        for (uint j = 0; j < edges[i].size(); j++)
        {
            std::cout << edges[i][j] << " ";
        }
        std::cout << "" << std::endl;
    }
}

//!!
std::string Graph::getStatus(int nodeInd)
{
    if (this->vertex[nodeInd] == Healthy)
        return "\033[32mH\033[0m";
    else if (this->vertex[nodeInd] == Sick)
        return "\033[31mS\033[0m";
    else if (this->vertex[nodeInd] == Carrier)
        return "\033[33mC\033[0m";
    return "N";
}
