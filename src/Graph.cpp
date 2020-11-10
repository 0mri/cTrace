#include "Graph.h"
#include <iostream>
#include <vector>
Graph::Graph() {}
Graph::Graph(std::vector<std::vector<int>> matrix)
{
    edges = matrix;
    // for (int i = 0; i < matrix.size(); i++)
    // {
    //     for (int j = 0; j < matrix[0].size(); j++)
    //     {
    // edges.pushc_back(matrix[i][j])
    //     }
    // }
}

Graph &Graph::operator=(const Graph &other)
{
    std::cout << "MOVE ASSIGNMENT" << std::endl;
    // std::cout << &other << std::endl;
    // std::cout << this << std::endl;
    // std::cout << &edges << std::endl;

    // if (this != &other)
    // {
    //     // Free the existing resource.
    // for (int i = 0; i < edges.size(); i++)
    // {
    //     delete[] & edges[i];
    //     /* code */
    // }
    // delete[] &edges;

    // std::cout << &edges << std::endl;
    this->edges = other.edges;
    // std::cout << &edges << std::endl;

    //     // std::copy(other._data, other._data + _length, _data);
    // }
    return *this;
}
Graph &Graph::operator=(const Graph &&other)
{
    if (this != &other)
    {
        // delete[] &edges;      // Delete the string's original data.
        // this->data_ = other.data_; // Copy the other string's data into this string.
        // other.data_ = nullptr;     // Finally, reset the other string's data pointer.
    }
    return *this;
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