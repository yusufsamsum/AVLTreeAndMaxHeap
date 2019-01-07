/*
* Title : Heaps and AVL Trees
* Author : Yusuf Samsum
* Description : A simple AVL Tree and its rotation analysis
*/
#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
#include "AVLTreeNode.h"
using namespace std;
class AVLTree
{
public:
    AVLTree();
   // ~AVLTree();
    void insert( int value);  // inserts an element into the tree
    int getNumberOfRotations(); // returns number of rotations performed
protected:
    void insertionHelper( AVLTreeNode *& treeNode, int value );
    void singleRightRotation( AVLTreeNode *& treePtr);
    void singleLeftRotation( AVLTreeNode *& treePtr );
    void doubleRightLeftRotation( AVLTreeNode *& treePtr );
    void doubleLeftRightRotation( AVLTreeNode *& treePtr );
    int balanceFactorOfNode(AVLTreeNode *& treePtr);
    int heightFinder( AVLTreeNode *& treePtr );
    void balanceTree(AVLTreeNode *& treePtr, int value );
    int max(int,int);
private:
    AVLTreeNode * root;
    int numberOfRotations;
};


#endif /* AVLTREE_H */
