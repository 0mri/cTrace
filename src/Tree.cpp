#include "Tree.h"
#include "Session.h"


Tree::Tree(int rootLabel) : node(rootLabel), children(){}

Tree::Tree(Tree& t) : node(t.getNode()), children() {
    vector<Tree*>::iterator it; 
    for (it = children.begin(); it < children.end(); it++)
        children.push_back(*it);

}
// Tree::Tree(Tree& t) : node(t.getNode()) {}

std::vector <Tree*> Tree::getChildren(){
    return this->children;
}

int Tree::getNode(){
    return this->node;
}

void Tree::addChild(const Tree& child) {
    // children.push_back(new Tree(child));
}





Tree* Tree::createTree(const Session& session, int rootLabel){
    // for(Iterator it = vector<Tree*>::Iterator; it)
}