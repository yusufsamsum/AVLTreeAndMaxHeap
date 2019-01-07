/*
* Title : Heaps and AVL Trees
* Author : Yusuf Samsum
* Description : A simple Max Heap and its analysis by using permutations and number of swaps.
*/
#ifndef MAXHEAP_H
#define MAXHEAP_H
const int MAX_HEAP = 10000;
class Heap
{
public:
    Heap();

    bool heapIsEmpty();
    bool heapInsert( int newItem );
    void heapDelete( int & rootItem );
    int getNumberOfSwaps();
    void heapRebuild( int root, int array[], int numberOfElementInArray );
    void permutation();
protected:
    int heightFinder( int numberOfElementInTheArray );
    void heapPermutationHelper( int numberOfElementInTheArray, int leftMostLeaf, int memoryLeftMostLeaf); // permute all leaves and calculate no of swap to rebuild it
    void swap( int & first, int & second );

private:
    int items[MAX_HEAP];
    int size;
    int numberOfSwaps;
};


#endif /* MAXHEAP_H */
