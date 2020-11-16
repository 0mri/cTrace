#include "Tree.h"
#include "Session.h"

Tree::Tree(int rootLabel) : node(rootLabel), children() {}

Tree::Tree(Tree &t) : node(t.getNode()), children()
{
    vector<Tree *>::iterator it;
    for (it = children.begin(); it < children.end(); it++)
        children.push_back(*it);
}

std::vector<Tree *> Tree::getChildren()
{
    return this->children;
}

int Tree::getNode()
{
    return this->node;
}

void Tree::addChild(const Tree &child)
{
    // children.push_back(new Tree(child));
}


Tree *Tree::createTree(const Session &session, int rootLabel)
{
    TreeType currTreeType = session.getTreeType();

    Tree *t;
    if (currTreeType == MaxRank)
        t = new MaxRankTree(rootLabel);
    else if (currTreeType == Cycle)
        t = new CycleTree(rootLabel, 9);
    else if (currTreeType == Root)
        t = new RootTree(rootLabel);

}