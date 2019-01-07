/*
* Title : Heaps and AVL Trees
* Author : Yusuf Samsum
* Description : A simple AVL Tree and its rotation analysis
*/
#include "AVLTree.h"
#include "AVLTreeNode.h"
#include <iostream>
using namespace std;

AVLTree::AVLTree()
{
    root = NULL;
    //root ->left  = NULL;
    //root ->right = NULL;
    numberOfRotations = 0;
}

int AVLTree::getNumberOfRotations()
{
    return numberOfRotations;
}

void AVLTree::insert( int value )
{
    insertionHelper( root, value );
}

int AVLTree::heightFinder( AVLTreeNode *& treePtr)
{
    if( treePtr == NULL )
        return 0;
    else
        return 1 + max( heightFinder(treePtr ->left) , heightFinder( treePtr -> right ) );
}

// height diff of a node
int AVLTree::balanceFactorOfNode( AVLTreeNode *& treePtr )
{
    return heightFinder( treePtr -> left ) - heightFinder( treePtr -> right );
}

void AVLTree::insertionHelper( AVLTreeNode *& treeNode, int value )
{
    if( treeNode == NULL )
    {
        treeNode = new AVLTreeNode(value, NULL, NULL);
    }
    else if( treeNode ->item > value )
            insertionHelper( treeNode->left, value );
    else
        insertionHelper( treeNode->right, value );
    treeNode->height = 1 + heightFinder( treeNode );
    balanceTree( treeNode , value);
}

void AVLTree::balanceTree( AVLTreeNode *& treePtr, int value )
{
    int balance = balanceFactorOfNode( treePtr) ;
    //cout << "balance factor: " << balance << endl;
    // there are 4 cases
    // case 1: left subtree of left child
    if( balance > 1 && value < treePtr ->left->item )
    {
        singleRightRotation( treePtr );
        return;
    }

    // case 2: right subtree right child
    if( balance < -1 && value > treePtr ->right->item )
    {
        singleLeftRotation(treePtr);
        return;
    }

    // case 3: left subtree of right child
    if( balance > 1 && value > treePtr ->left->item ){
        doubleLeftRightRotation( treePtr );
        return;
    }

    // case 4: right subtree of left child
    if( balance < -1 && value < treePtr ->right->item ){
        doubleRightLeftRotation( treePtr );
        return;
    }

}

void AVLTree::singleLeftRotation( AVLTreeNode *& treePtr )
{
    AVLTreeNode * rightChild = treePtr -> right;
    treePtr ->right = rightChild -> left;
    rightChild ->left = treePtr;
    treePtr ->height = heightFinder( treePtr ); // updating height
    rightChild->height = heightFinder( rightChild ); // updating height
    numberOfRotations++;
}

void AVLTree::singleRightRotation( AVLTreeNode *& treePtr )
{
    AVLTreeNode * leftChild = treePtr ->left;
    treePtr ->left = leftChild ->right;
    leftChild ->left = treePtr;
    treePtr ->height = heightFinder( treePtr ); // updating height
    leftChild->height = heightFinder( leftChild ); // updating height
    numberOfRotations++;
}

void AVLTree::doubleLeftRightRotation( AVLTreeNode *& treePtr )
{
    AVLTreeNode * k1 = treePtr ->left;
    AVLTreeNode * k2 = k1 ->right;
    k1 ->right = k2 ->left;
    k2 ->left = k1;
    treePtr ->left = k2 ->right;
    k2 ->right = treePtr;
    treePtr ->height = heightFinder( treePtr ); // updating height
    k2 ->height = heightFinder( k2 ); // updating height
    k1 ->height = heightFinder( k1 ); // updating height
    numberOfRotations = numberOfRotations + 2;
}

void AVLTree::doubleRightLeftRotation( AVLTreeNode *& treePtr )
{
    AVLTreeNode * k3 = treePtr ->right;
    AVLTreeNode * k2 = k3 ->left;
    k3 ->left = k2 ->right;
    k2 ->right = k3;
    treePtr ->right = k2 ->left;
    k2 ->left = treePtr;
    treePtr ->height = heightFinder( treePtr ); // updating height
    k2 ->height = heightFinder( k2 ); // updating height
    k3 ->height = heightFinder( k3 ); // updating height
    numberOfRotations = numberOfRotations + 2;
}


int AVLTree::max( int first, int second)
{
    if( first > second )
        return first;
    return second;
}
