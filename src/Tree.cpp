#include "Tree.h"
#include "Session.h"
#include <iostream>
#include <algorithm>
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

    this->children.push_back(child.clone());
    if (this->children.size() >= 2)
    {
        int i = children.size() - 2;
        while (i >= 0 && (children[i]->getNode()) > (children[i + 1]->getNode()))
        {
            Tree *c = children[i];
            children[i] = children[i + 1];
            children[i + 1] = c;
            i--;
        }
    }
}

void Tree::addChild(Tree *child)
{
    this->children.push_back(child->clone());
    if (this->children.size() >= 2)
    {
        int i = children.size() - 2;
        while (i >= 0 && (children[i]->getNode()) > (children[i + 1]->getNode()))
        {
            Tree *c = children[i];
            children[i] = children[i + 1];
            children[i + 1] = c;
            i--;
        }
    }
}

Tree *Tree::createTree(const Session &session, int rootLabel)
{
    TreeType curr_tree_type = session.getTreeType();
    Tree *t;
    if (curr_tree_type == MaxRank)
        t = new MaxRankTree(rootLabel);
    else if (curr_tree_type == Cycle)
        t = new CycleTree(rootLabel, session.getCurrCycle());
    else
        t = new RootTree(rootLabel);

    return t;
}

Tree::~Tree()
{
    Clear();
}

Tree::Tree(int rootLabel) : node(rootLabel), children() {}

//Copy Constructor
Tree::Tree(const Tree &other) : node(other.node), children()
{
    cloneChilds(other.children);
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
        Clear();
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
        for (const auto &child : children)
            this->children.push_back(child->clone());
    }
    return *this;
}

void Tree::Clear()
{
    while (!children.empty())
    {
        delete (children[0]);
        children[0] = nullptr;
        children.erase(children.cbegin());
    }
}

void Tree::cloneChilds(const vector<Tree *> &children)
{
    for (const auto &child : children)
        this->children.push_back(child->clone());
}


//!!
void Tree::print_childs()
{
    for (const auto *child : this->children)
        cout << child->node << ", ";

    cout << endl;
}