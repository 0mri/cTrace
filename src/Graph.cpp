#include "Graph.h"
#include <iostream>
#include <vector>


Graph::Graph() {}

Graph::Graph(std::vector<std::vector<int>> matrix) : vertex(matrix.size(), Healthy), edges(matrix) {}

// Graph &Graph::operator=(const Graph &other)
// {
//     std::cout << "MOVE ASSIGNMENT" << std::endl;
//     // std::cout << &edges << std::endl;
//     this->edges = other.edges;
//     // std::cout << &edges << std::endl;

//     //     // std::copy(other._data, other._data + _length, _data);
//     // }
//     return *this;
// }
// Graph &Graph::operator=(const Graph &&other)
// {
//     if (this != &other)
//     {
//         // delete[] &edges;      // Delete the string's original dindata.
//         // this->data_ = other.data_; // Copy the other string's data into this string.
//         // other.data_ = nullptr;     // Finally, reset the other string's data pointer.
//     }
//     return *this;
// }

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

    for (int i = 0; i < edges.size(); i++)
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
    for (int i = 0; i < edges.size(); i++)
        if (edges[nodeInd][i] == 1)
            return i;

    return -1;
}

void Graph::print()
{
    for (int i = 0; i < edges.size(); i++)
    {
        for (int j = 0; j < edges[0].size(); j++)
        {
            std::cout << edges[i][j] << " ";
        }
        std::cout << "" << std::endl;
    }
}