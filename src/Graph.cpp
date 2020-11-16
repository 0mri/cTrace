#include "Graph.h"
#include <iostream>
#include <vector>
//#include <Session.h>
#include "Tree.h"
Graph::Graph() {}

Graph::Graph(std::vector<std::vector<int>> matrix) : vertex(matrix.size()), edges(matrix)
{
    // edges = matrix;
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


// Function to perform BFS on the graph
Tree Graph::BFS(int start, Session &s)
{
    // Visited vector to so that
    // a vertex is not visited more than once
    // Initializing the vector to false as no
    // vertex is visited at the beginning
    Tree t;
    if(s.getTreeType()==Cycle)
         t = new CycleTree(start);
    if(s.getTreeType()==MaxRankTree)
        t = new MaxRankTree(start);
    if(s.getTreeType()==RootTree)
        t = new RootTree(start);
    vector<bool> visited(edges.size(), false);
    vector<int> q;
    q.push_back(start);

    // Set source as visited
    visited[start] = true;

    int vis;
    while (!q.empty()) {
        vis = q[0];

        // Print the current node
        cout << vis << " ";
        q.erase(q.begin());

        // For every adjacent vertex to the current vertex
        for (int i = 0; i < edges.size(); i++) {
            if (edges[vis][i] == 1 && (!visited[i])) {

                // Push the adjacent node to the queue
                q.push_back(i);

                // Set
                visited[i] = true;
            }
        }
    }
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