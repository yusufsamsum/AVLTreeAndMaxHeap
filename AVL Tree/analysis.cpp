/*
* Title : Heaps and AVL Trees
* Author : Yusuf Samsum
* Description : A simple AVL Tree and its rotation analysis
*/
#include "AVLTree.h"
#include "AVLTreeNode.h"
#include <iostream>
#include <stdlib.h>
using namespace std;


void rotationAnalysis()
{
    AVLTree randomTest;
    AVLTree ascendingTest;
    AVLTree descendingTest;

    int ascending  = 1;
    int descending = 100000;

    cout << "Array Size" << "\t" << "Random" << "\t" <<  "    Ascending" << "\t" << "    Descending" << endl;
    for( int i = 1; i < 10001; i++ )
    {
        randomTest.insert( rand() % 100000 );
        ascendingTest.insert( ascending );
        descendingTest.insert( descending );
        ascending++;
        descending++;
        if( i % 1000 == 0 )
            cout << i << "\t" << "\t" << randomTest.getNumberOfRotations() << "\t       " <<  ascendingTest.getNumberOfRotations()
                                                    << "\t" << "\t"  << descendingTest.getNumberOfRotations() << endl;
    }
}
