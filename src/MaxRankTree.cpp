#include "Tree.h"
#include <queue>
#include <iostream>
MaxRankTree::MaxRankTree(int rootLabel) : Tree(rootLabel) {}

int MaxRankTree::traceTree()
{
    queue<Tree *> q;
    q.push(this);
    int max_nodeInd = q.front()->getNode();
    int num_of_childs = q.front()->getChildren().size();
    int curr_childs;
    int curr_index;
    while (!q.empty())
    {
        Tree *curr_sub_tree = q.front();
        std::cout << "MaxRank: " << curr_sub_tree->getNode() << " Childs: " << curr_sub_tree->getChildren().size() << std::endl;
        q.pop();
        curr_childs = curr_sub_tree->getChildren().size();
        curr_index = curr_sub_tree->getNode();

        max_nodeInd = curr_childs > num_of_childs ? curr_index : max_nodeInd;      //save the node index with the greatest num of childs
        num_of_childs = curr_childs > num_of_childs ? curr_childs : num_of_childs; //save num of childs of the urrent node

        for(const auto &child: curr_sub_tree->getChildren())
            q.push(child);
    }
    return max_nodeInd;
}

MaxRankTree *MaxRankTree::clone() const
{
    return new MaxRankTree(*this);
}