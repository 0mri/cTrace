#include "Graph.h"
#include <iostream>
#include <vector>
#include "Tree.h"
#include "queue"

Graph::Graph() : vertex(), edges() {}

Graph::Graph(std::vector<std::vector<int>> matrix) : vertex(matrix.size(), Healthy), edges(matrix) {
    
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

    for (uint i = 0; i < edges.size(); i++)
    {
        if (this->edges[nodeInd][i] == 1)
        {
            edges[nodeInd][i] = 0;
            edges[i][nodeInd] = 0;
        }
    }

    // vector<vector<int>>::iterator it;
    // for (it = edges.begin(); it != edges.end(); it++)
    //     cout << it << endl;
    //     // if (edges[nodeInd][it] == 1)
    //     // {
    //     //     edges[nodeInd][it] = 0;
    //     //     edges[it][nodeInd] = 0;
    //     // }
}

void Graph::changeStatus(int nodeInd, VertexStatus vs)
{
    this->vertex[nodeInd] = vs;
}

int Graph::nearestNeighbor(int nodeInd)
{
    for (uint i = 0; i < edges.size(); i++)
        if (edges[nodeInd][i] == 1)
            return i;

    return -1;
}

char Graph::getStatus(int nodeInd)
{
    if (this->vertex[nodeInd] == Healthy)
        return 'H';
    else if (this->vertex[nodeInd] == Sick)
        return 'S';
    else if (this->vertex[nodeInd] == Carrier)
        return 'C';
    return 's';
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
void Graph::print()
{
    for (uint i = 0; i < edges.size(); i++)
    {
        cout << i << "." << this->getStatus(i) << " - ";
        for (uint j = 0; j < edges[i].size(); j++)
            std::cout << edges[i][j] << " ";
        std::cout << "" << std::endl;
    }
}

vector<int> &Graph::getNeighbors(int nodeInd)
{
    vector<int> *neighbors = new vector<int>();
    for (uint i = 0; i < edges.size(); i++)
        if (hasEdge(i, nodeInd))
            neighbors->push_back(i);

    return *neighbors;
}

Tree *Graph::bfs(Session &session, int nodeInd)
{
    Tree *bfs_tree = Tree::createTree(session, nodeInd);
    vector<bool> *visited = new vector<bool>(6, 0);
    queue<Tree *> tree_q;
    tree_q.push(bfs_tree);
    while (!tree_q.empty())
    {
        Tree *curr_tree = tree_q.front();
        tree_q.pop();
        if (!(*visited)[curr_tree->getNode()])
        {
            vector<int> neighbors = this->getNeighbors(curr_tree->getNode());
            for (uint i = 0; i < neighbors.size(); ++i)
                if ((*visited)[(neighbors)[i]])
                {
                    Tree *temp_tree = Tree::createTree(session, neighbors[i]);
                    curr_tree->addChild(*temp_tree);
                    tree_q.push(curr_tree->getChildren()[curr_tree->getChildren().size() - 1]);
                    (*visited)[(neighbors)[i]] = true;
                    delete temp_tree;
                    temp_tree = nullptr;
                }
            // (*visited)[curr_tree->getNode()] = 2;
            delete &neighbors;
        }
    }
    return bfs_tree;
}
