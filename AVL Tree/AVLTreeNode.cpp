/*
* Title : Heaps and AVL Trees
* Author : Yusuf Samsum
* Description : A simple AVL Tree and its rotation analysis
*/
#include "AVLTree.h"
#include "AVLTreeNode.h"
using namespace std;


AVLTreeNode::AVLTreeNode( int treeItem, AVLTreeNode * leftChild, AVLTreeNode * rightChild )
{
    item = treeItem;
    left = leftChild;
    right = rightChild;
}
