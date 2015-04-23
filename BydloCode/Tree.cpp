#include "Tree.h"
#include <iostream>

Node::Node() {
    data = 0;
    right = NULL;
    left = NULL;
    parent = NULL;
}

Node::Node(int value) {
    data = value;
    right = NULL;
    left = NULL;
    parent = NULL;
}

Node::~Node() {}

Tree::Tree() {
    root = NULL;
}

Tree::~Tree() {
    Destroy(root);
}

PNode Tree::Insert(int value) {
    PNode current = root, curr_parent = NULL;
    PNode insert_node = new Node(value);

    if (!root) {
        root = insert_node;
        return insert_node;
    }

    while (current) {
        curr_parent = current;

        if (value < current->data)
            current = current->left;
        else
            current = current->right;
    }

    insert_node->parent = curr_parent;

    if (value < curr_parent->data)
        curr_parent->left = insert_node;
    else
        curr_parent->right = insert_node;

    return insert_node;
}

PNode Tree::Search(int value) {
    PNode current = root;

    while (current && current->data != value) {
        if (value < current->data)
            current = current->left;
        else
            current = current->right;
    }

    return current;
}

PNode Tree::Maximum(PNode root) {
    PNode current = root;

    if (root == NULL)
        return root;

    while (current->right)
        current = current->right;

    return current;
}

PNode Tree::Minimum(PNode root) {
    PNode current = root;

    if (root == NULL)
        return root;

    while (current->left)
        current = current->left;

    return current;
}

int Tree::maxDepth(PNode node)
    {
        if(node == NULL || (node->left == NULL && node->right == NULL))
                return 0;

        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);

        return leftDepth > rightDepth ?
                    leftDepth + 1 : rightDepth + 1;
    }

int Tree::minDepth(PNode node)
    {
        if(node == NULL || (node->left == NULL && node->right == NULL))
                return 0;

        int leftDepth = minDepth(node->left);
        int rightDepth = minDepth(node->right);

        return leftDepth < rightDepth ?
                    leftDepth + 1 : rightDepth + 1;
    }

PNode Tree::Successor(PNode node) {
    PNode successor_parent = NULL, current = node;

    if (node == NULL)
        return node;

    if (node->right)
        return Minimum(node->right);

    successor_parent = node->parent;
    while (successor_parent != NULL && current == successor_parent->right) {
        current = successor_parent;
        successor_parent = successor_parent->parent;
    }

    return successor_parent;
}

PNode Tree::Predecessor(PNode node) {
    PNode successor_parent = NULL, current = node;

    if (node == NULL)
        return node;

    if (node->left)
        return Maximum(node->left);

    successor_parent = node->parent;
    while (successor_parent != NULL && current == successor_parent->left) {
        current = successor_parent;
        successor_parent = successor_parent->parent;
    }

    return successor_parent;
}

void Tree::MoveNode(PNode destination, PNode source) {
    if (destination->parent == NULL)
        root = source;
    else if (destination == destination->parent->right)
        destination->parent->right = source;
    else
        destination->parent->left = source;

    if (source != NULL)
        source->parent = destination->parent;
}

void Tree::Delete(PNode node) {
    if (node == NULL)
        return;

    if (node->right == NULL)
        MoveNode(node, node->left);
    else if (node->left == NULL)
        MoveNode(node, node->right);
    else {
        PNode min = Minimum(node->right);

        if (min != node->right) {
            MoveNode(min, min->right);
            min->right = node->right;
            min->right->parent = min;
        }

        MoveNode(node, min);
        min->left = node->left;
        min->left->parent = min;
    }

    delete node;
}

void Tree::Display(PNode node){

    if(node == NULL) return;

    Display(node->left);
    std::cout << node->data << " ";
    Display(node->right);
}

int Tree::treeSize(PNode node){

    if(node == NULL) return 0;
            else
                return treeSize(node->left) + 1 + treeSize(node->right);
}

bool Tree::isBalanced(PNode node){

    if(maxDepth(node)-minDepth(node) <= 1)
                return true;
            else
                return false;
}

void Tree::Destroy(PNode node) {
    if (node) {
        Destroy(node->right);
        Destroy(node->left);
        delete node;
    }
}

void Tree::Delete(int key) {
    Delete(Search(key));
}
