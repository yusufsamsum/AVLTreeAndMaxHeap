/*
* Title : Heaps and AVL Trees
* Author : Yusuf Samsum
* Description : A simple AVL Tree and its rotation analysis
*/
#ifndef AVLTREENODE_H
#define AVLTREENODE_H
#include "AVLTree.h"
#include <iostream>
using namespace std;


class AVLTreeNode
{
private:
    AVLTreeNode();
    AVLTreeNode( int treeItem, AVLTreeNode * leftChild = NULL, AVLTreeNode * rightChild = NULL );
    int item;
    AVLTreeNode * right;
    AVLTreeNode * left;
    int height;
    friend class AVLTree;
};
#endif /* AVLTREENODE_H */
