#include "Tree.h"
#include <queue>

MaxRankTree::MaxRankTree(int rootLabel) : Tree(rootLabel) {}

int RootTree::traceTree()
{
    queue<Tree *> tree_q;
    tree_q.push(this);
    int max_nodeInd = tree_q.front()->getNode();
    int num_of_childs = tree_q.front()->getChildren().size();
    int curr_childs, curr_index;
    while (!tree_q.empty())
    {
        Tree *curr_sub_tree = tree_q.front();
        tree_q.pop();
        curr_childs = curr_sub_tree->getChildren().size();
        curr_index = curr_sub_tree->getNode();

        max_nodeInd = (curr_childs > num_of_childs) ? curr_index : max_nodeInd;
        num_of_childs = (curr_childs > num_of_childs) ? curr_childs : num_of_childs;

        for (int i = 0; i < curr_childs; i++)
            tree_q.push(curr_sub_tree->getChildren()[i]);
    }
    return max_nodeInd;
}

MaxRankTree *MaxRankTree::clone() const
{
    return new MaxRankTree(*this);
}