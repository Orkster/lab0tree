#ifndef TREE_H
#define TREE_H



#include <stdio.h>

struct Node {
    Node(int);
    Node();
    ~Node();

    int data;
    Node *left, *right, *parent;
};

typedef Node* PNode;

class Tree {
public:
    Tree();
    ~Tree();

    PNode Insert(int);
    PNode Search(int);
    PNode Maximum(PNode);
    PNode Minimum(PNode);
    PNode Successor(PNode);
    PNode Predecessor(PNode);


    void MoveNode(PNode, PNode);
    void Display(PNode);
    void Destroy(PNode);
    void Delete(PNode);
    void Delete(int);
    void treeToVine(PNode, int&);
    void vineToTree(PNode, int);
    int fullSize(int);
    void compresion(PNode, int);
    void DSW(PNode);
    bool isBalanced(PNode);
    int treeSize(PNode);
    int maxDepth(PNode);
    int minDepth(PNode);

    PNode root, pseudoroot;
    int size = 0;
};

#endif // TREE_H
