#ifndef TREE_H_
#define TREE_H_

#include <vector>
using namespace std;
class Session;

class Tree
{
public:
    Tree(const Tree &other);
    Tree &operator=(const Tree &other);
    Tree &operator=(Tree &&other);
    Tree(Tree &&other);
    virtual ~Tree();

    Tree(int rootLabel);
    Tree(Tree &t);

    std::vector<Tree *> getChildren();
    int getNode();

    void addChild(const Tree &child);
    void addChild(Tree *child);

    
    virtual Tree *clone() const = 0;

    static Tree *createTree(const Session &session, int rootLabel);

    virtual int traceTree() = 0;

    void cloneChilds(const vector<Tree *> &childs);
    void sortChilds();

    // TEST
    void print_childs();

private:
    int node;
    std::vector<Tree *> children;
    void Clear();
};

class CycleTree : public Tree
{
public:
    CycleTree(int rootLabel, int currCycle);
    virtual int traceTree();
    virtual CycleTree *clone() const;

private:
    int currCycle;
};

class MaxRankTree : public Tree
{
public:
    MaxRankTree(int rootLabel);
    virtual int traceTree();
    virtual MaxRankTree *clone() const;
};

class RootTree : public Tree
{
public:
    RootTree(int rootLabel);
    virtual int traceTree();
    virtual RootTree *clone() const;
};

#endif