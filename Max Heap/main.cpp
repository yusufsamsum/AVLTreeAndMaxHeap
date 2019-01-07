/*
* Title : Heaps and AVL Trees
* Author : Yusuf Samsum
* Description : A simple Max Heap and its analysis by using permutations and number of swaps.
*/
#include "MaxHeap.h"
#include <ios>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    Heap h;
    int size = 0;
    ifstream myfile( "input.txt", ios::in );
    myfile >> size;
    int * elements  = new int[ size ];
    // taking elements
    for ( int i = 0 ;  i < size; i++){
        myfile >> elements[i];
        //cout << elements[i] << endl;;
    }
    // inserting elements
    for( int i = 0 ;  i<  size; i++ )
        h.heapInsert( elements[i] );

    h.permutation(  );
    /*for( int i = 0 ;  i<  size; i++ ){
        int temp = 5656;
        h.heapDelete(temp);
        cout << temp << "  i  : " << i <<endl;
    }*/
    myfile.close();
    return 0;

}
