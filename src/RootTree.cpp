#include "Tree.h"

RootTree::RootTree(int rootLabel) : Tree(rootLabel) {}

int RootTree::traceTree()
{
    return this->getNode();
}

RootTree *RootTree::clone() const
{
    return new RootTree(*this);
}