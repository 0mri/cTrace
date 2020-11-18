#include "Tree.h"
#include <iostream>

CycleTree::CycleTree(int rootLabel, int currCycle) : Tree(rootLabel), currCycle(currCycle) {}

int CycleTree::traceTree()
{
    bool stop = false;
    Tree *LeftMost = this;

    for (uint i = 0; i < (uint)this->currCycle && !stop; ++i)
    {
        if (LeftMost->getChildren().size() != 0)
            LeftMost = (LeftMost->getChildren()[0]);
        else
            stop = true;
    }
    return LeftMost->getNode();
    ;
}

CycleTree *CycleTree::clone() const
{
    return new CycleTree(*this);
}
