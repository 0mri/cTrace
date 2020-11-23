#include <iostream>
#include <fstream>
#include "Tree.h"
#include "json.hpp"
#include <queue>
#include "Graph.h"
#define JSON_PATH "output_test.json"

using namespace std;

int tree_exp1()
{
    // MaxRankTree t(1);
    // MaxRankTree t2(2);
    // t2.addChild(MaxRankTree(3));
    // t2.addChild(MaxRankTree(4));
    // t2.addChild(MaxRankTree(5));
    // t.addChild(t2);
    // t.addChild(MaxRankTree(6));

    vector<vector<int>> a = {{0, 1, 0, 0, 1, 0, 0, 0, 0},
                             {1, 0, 1, 1, 0, 1, 1, 0, 0},
                             {0, 1, 0, 1, 0, 1, 0, 0, 0},
                             {0, 1, 1, 0, 0, 1, 0, 0, 0},
                             {1, 0, 0, 0, 0, 1, 0, 0, 0},
                             {0, 1, 1, 1, 1, 0, 0, 1, 0},
                             {0, 1, 0, 0, 0, 0, 0, 1, 1},
                             {0, 0, 0, 0, 0, 1, 1, 0, 0},
                             {0, 0, 0, 0, 0, 0, 1, 0, 0}};

    Graph g(a);
    Tree *root = new MaxRankTree(0);
    // root->bfs(g, &root);

    // Tree *left_child = new MaxRankTree(1);

    // Tree *right_child = new MaxRankTree(4);

    // left_child->addChild(new MaxRankTree(6));
    // left_child->addChild(new MaxRankTree(2));
    // root->getChildren()[3]->addChild(new MaxRankTree(7));
    // root->getChildren()[0]->addChild(new MaxRankTree(8));
    root->addChild(new MaxRankTree(3));
    root->addChild(new MaxRankTree(5));
    root->addChild(new MaxRankTree(1));
    root->addChild(new MaxRankTree(10));
    root->addChild(new MaxRankTree(7));
    root->addChild(new MaxRankTree(19));
    root->addChild(new MaxRankTree(15));
    root->addChild(new MaxRankTree(2));
    root->print_childs();
    // root->addChild(*left_child);
    // root->addChild(*right_child);

    // // t2.print_childs();
    // cout << "num of childs of " << root->getNode() << ": " << root->getChildren().size() << endl;
    // cout << "num of grandchilds of " << root->getNode() << ": " << root->getChildren()[0]->getChildren().size() << endl;

    int b = root->traceTree();

    return b;
}

int main(int argc, char **argv)
{
    nlohmann::json j;
    j["tree1"] = tree_exp1();
    std::ofstream o(JSON_PATH);
    o << j << endl;
    return 0;
}