#include "Tree.h"
#include <iostream>

CycleTree::CycleTree(int rootLabel, int currCycle) : Tree(rootLabel), currCycle(currCycle) {}

int CycleTree::traceTree()
{
    Tree *left_most = this;
    for (uint i = 0; i < (uint)this->currCycle; i++)
        if (left_most->getChildren().size() != 0)
            left_most = (left_most->getChildren()[0]);
        else
            break;

    return left_most->getNode();
}

CycleTree *CycleTree::clone() const
{
    return new CycleTree(*this);
}
