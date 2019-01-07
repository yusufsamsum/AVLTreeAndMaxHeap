/*
* Title : Heaps and AVL Trees
* Author : Yusuf Samsum
* Description : A simple Max Heap and its analysis by using permutations and number of swaps.
*/
#include <iostream>
using namespace std;
#include "MaxHeap.h"

Heap::Heap()
{
    size = 0;
    numberOfSwaps = 0;
}

bool Heap::heapIsEmpty()
{
    return size <= 0;
}

bool Heap::heapInsert( int newItem )
{
    if( size >= MAX_HEAP ){
        return false;
    }

    items[size] = newItem;

    int place = size;
    int parent = (place - 1) / 2;
    while( ( place > 0 ) && ( items[place] > items[parent] ) )
    {
        int temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;
        place = parent;
        parent = ( place - 1 ) / 2;
    }
    size++;
    return true;
}

void Heap::heapDelete( int & rootItem )
{
    if( heapIsEmpty() )
        return;
    else
    {
        rootItem = items[0];
        size--;
        items[0] = items[size];
        heapRebuild( 0 , items, size );
    }
}


void Heap::heapRebuild( int root, int array[], int numberOfElementInArray )
{
    if( root != numberOfElementInArray - 1 )
    {
        int child = 2 * root + 1;
        if( child < numberOfElementInArray )
        {
            //root is not a leaf so that it has a left child
            int rightChild = child + 1; //index of a right child

            //if root has right child, find larger child
            if ( ( child < numberOfElementInArray ) && ( items[rightChild] > items[ child ] ) )
                child = rightChild;

            if( items[root] < items[child] )
            {
                int temp = items[ root ];
                items[ root ] = items[ child ];
                items[ child ] = temp;
                numberOfSwaps++;

                //transform the new subtree intro a heap
                heapRebuild( child, array, numberOfElementInArray );
            }
        }
    }
}


int Heap::heightFinder( int numberOfElementInTheArray )
{
    if( numberOfElementInTheArray == 1 )
        return 1;
    else if ( numberOfElementInTheArray > 1 )
        return 1 + heightFinder( (numberOfElementInTheArray - 1 ) / 2 );
    else
        return 0;
}

/*
    leftMostLeaf is the most left leaf in the heap and numberOfElementInTheArray is the size of the array,
    memoryLeftMostLeaf is the leftMostLeaf but when we find a version of permutation the original heap should be kept  .
    However, numberOfSwaps should also be got , so, by copying the original array numberOfSwaps is got. At the same time,
    heapRebuild should be applied all elements apart from leaves, to do that, memoryLeftMostLeaf has kept so that
    heap elements can be copied without its leaves by using this constant variable.
*/
void Heap::heapPermutationHelper( int numberOfElementInTheArray, int leftMostLeaf, int memoryLeftMostLeaf)
{
    if( leftMostLeaf == numberOfElementInTheArray )
    {
        Heap temp;
        for( int i  = 0; i < numberOfElementInTheArray; i++) // get a version of permutation
            temp.items[i] = items[i];
        for(int i = 0; i < memoryLeftMostLeaf; i++) // copying without leaves
            temp.heapRebuild( i, temp.items, numberOfElementInTheArray );
        numberOfSwaps = numberOfSwaps + temp.getNumberOfSwaps(); // no of swap
    }
    else{
        for( int i = leftMostLeaf; i<numberOfElementInTheArray; i++)
        {
            swap( items[leftMostLeaf], items[i] ); // getting permutations
            heapPermutationHelper( numberOfElementInTheArray, leftMostLeaf + 1,memoryLeftMostLeaf );
            swap( items[leftMostLeaf], items[i] ); // backward
        }
    }
}

void Heap::swap( int & first, int & second )
{
    int temp = first;
    first = second;
    second = temp;
}

int Heap::getNumberOfSwaps()
{
    return numberOfSwaps;
}

void Heap::permutation()
{
    int height = heightFinder( size );
    int leftMostLeaf = 1;
    for ( int i = 0; i < height - 1; i++) /* to find leftMostLeaf, height is found then, 2^(x-1) rule is applied to find it.  */
        leftMostLeaf *= 2;
    leftMostLeaf--; // indicating real index, it starts from zero( 2^(height -1 ) = leftMostLeaf )
    heapPermutationHelper( size , leftMostLeaf, leftMostLeaf );
    cout << "Total number of swaps: " << numberOfSwaps << endl;
    int totalPermutation = 1;
    for( int i = 2; i <= size - leftMostLeaf; i++ )
        totalPermutation = totalPermutation * i;
    double totalMoneyFromSwaps = (double)numberOfSwaps/(double)totalPermutation;
    cout << "Average number of swaps per permutation is: " << totalMoneyFromSwaps  << endl;
    totalMoneyFromSwaps = totalMoneyFromSwaps * 10;

    if( totalMoneyFromSwaps > 20 )
        cout << "10 TL per swap is a better option" << endl;
    else
        cout << "20 TL is a better option" << endl;
}



