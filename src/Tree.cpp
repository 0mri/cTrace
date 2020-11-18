#include "Tree.h"
#include "Session.h"

std::vector<Tree *> Tree::getChildren()
{
    return this->children;
}

int Tree::getNode()
{
    return this->node;
}

void Tree::addChild(const Tree &child) //NOT SURE
{
    children.push_back(child.clone());
    int child_index = child.node;
    int i = children.size() - 2;
    while (children[i]->getNode() > child_index && i >= 0)
    {
        Tree *temp = children[i];
        children[i] = children[i + 1];
        children[i + 1] = temp;
        i--;
    }
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

    return t;
}

Tree::~Tree()
{
    clear();
}

Tree::Tree(int rootLabel) : node(rootLabel), children() {}

//Copy Constructor
Tree::Tree(const Tree &t) : node(t.node), children()
{
    vector<Tree *>::iterator iter;
    for (iter = children.begin(); iter < children.end(); iter++)
        children.push_back((*iter)->clone());
}

//Move Constractor
Tree::Tree(Tree &&other) : node(other.node), children()
{
    for (uint i = 0; i < other.children.size(); ++i)
    {
        this->children[i] = other.children[i];
        other.children[i] = nullptr;
    }
}

//Move Assignment Operator
Tree &Tree::operator=(Tree &&other)
{
    if (this != &other)
    {
        this->node = other.node;
        clear();
        for (uint i = 0; i < other.children.size(); ++i)
        {
            this->children[i] = other.children[i];
            other.children[i] = nullptr;
        }
    }
    return *this;
}

//Copy Assignment Operator
Tree &Tree::operator=(const Tree &other)
{
    if (this != &other)
    {
        this->node = other.node;
        for (uint i = 0; i < other.children.size(); i++)
            this->children.push_back(other.children[i]->clone());
    }
    return *this;
}

void Tree::clear()
{
    while (!children.empty())
    {
        delete (children[0]);
        children[0] = nullptr;
        children.erase(children.cbegin());
    }
}