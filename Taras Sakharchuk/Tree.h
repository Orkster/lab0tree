#ifndef BINARY_TREE
#define BINARY_TREE

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
	void Destroy(PNode);
	void Delete(PNode);
	void Delete(int);

private:
	PNode root;
};

#endif