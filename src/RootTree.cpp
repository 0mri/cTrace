#include "Tree.h"


RootTree::RootTree(int rootLabel): Tree(rootLabel) {}

int RootTree::traceTree(){
    return this->getNode();
}
