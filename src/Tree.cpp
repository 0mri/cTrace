#include "Tree.h"
#include "Session.h"

Tree::Tree(int rootLabel) : node(rootLabel), children() {}

//Copy Constructor
Tree::Tree(Tree &t) : node(t.getNode()), children()
{
    vector<Tree *>::iterator iter;
    for (iter = children.begin(); iter < children.end(); iter++)
        children.push_back(*iter.clone());
}


//Move Constractor
Tree::Tree(Tree &&otherTree):node(otherTree.node), children(){
    for (uint i=0; i<otherTree.children.size(); ++i){
        this->children[i] = otherTree.children[i];
        otherTree.children[i] = nullptr;
    }
}



//Move Assignment Operator
Tree& Tree::operator=(Tree &&otherTree) {
    if(this != &otherTree){
        this->node = otherTree.node;
        clear();
        for (uint i=0; i<otherTree.children.size(); ++i){
            this->children[i] = otherTree.children[i];
            otherTree.children[i] = nullptr;
        }
    }
    return *this;
}

//Copy Assignment Operator
Tree & Tree::operator=(const Tree &otherTree){
    if(this != &otherTree){
        this->node = otherTree.node;
        copyChildren(otherTree);
    }
    return *this;
}


void Tree::clear() {
    while (!children.empty()){
        delete(children[0]);
        children[0]= nullptr;
        children.erase(children.cbegin());
    }
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
    //TreeType = this.
    children.push_back(child.clone());
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

Tree::~Tree(){
    clear();
}