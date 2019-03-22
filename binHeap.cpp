//
//  binHeap.cpp
//  sortingAlgorithms
//
//  Created by Jacob Beck on 2/26/19.
//  Copyright © 2019 Jacob Beck. All rights reserved.
//

#include "binHeap.hpp"
// binheap.cpp implementation file for binary heaps

#include <iostream>
#include <iomanip>


// Utility routines used to implement binary heaps and heapSort

int parent ( int i ) {
    return i/2;
}

int left ( int i ) {
    return 2*i;
}

int right ( int i ) {
    return 2*i + 1;
}

void BinHeap :: minHeapify ( int i )
{
    int l, r, smallestloc;
    KeyType temp;
    
    l = left( i );
    r = right( i );
    int smallest;
    // You write the rest of this - remember this is a _min_ heap
    if( l <= heapSize && A[l] < A[i]) {
        smallest = l;
    }
    else {
        smallest = i;
    }
    if( r <= heapSize && A[r] < A[smallest]) {
        smallest = r;
    }
    if( i != smallest) {
        temp = A[i];
        A[i] = A[smallest];
        A[smallest] = A[i];
        minHeapify(smallest);
    }
}

void BinHeap :: buildMinHeap( )
{
    // You implement this for heapSort in Assignment #
    heapSize = length;
    for( int i = (length/2); i > 0; i--) {
        minHeapify(i);
    }
}


// Constructors, Destructor

BinHeap :: BinHeap() {
    heapSize = 0; length = 10000; A = new KeyType[10000];
}
BinHeap :: BinHeap( int arrayLength ) {
    heapSize = 0; length = arrayLength; A = new KeyType[arrayLength+1];
}
BinHeap :: ~BinHeap() {
    delete[] A;
}


// Min-heap, min priority queue operations

void BinHeap :: insert( KeyType key )
{
    heapSize++;
    A[heapSize] = key; // <-- This seems to work.
    decreaseKey( heapSize, key );
}

KeyType BinHeap :: minimum( )
{
    return A[1]; // Assumes heap is not empty!
}

KeyType BinHeap :: extractMin( )
{
    KeyType min;
    
    if ( heapSize < 1 ) {
        cout << "\nHeap underflow in extractMin()\n\n"; return 0;
    }
    
    min = A[1];
    
    // You write the rest of this - remember this is a _min_ heap
    A[1] = A[heapSize];
    heapSize--;
    minHeapify(1);
    
    return min;
}

void BinHeap :: decreaseKey( int i, KeyType key )
{
    KeyType temp;
    
    if ( key > A[i] ) {
        cout << "\nKey larger than A[i] in decreaseKey()\n\n"; return;
    }
    
    A[i] = key;
    while (i > 1 && A[parent(i)] > A[i]) {
        temp = A[i];
        A[i] = A[parent(i)];
        A[parent(i)] = temp;
        i = parent(i);
    }
    
    
}


// Auxiliary operations

// Shows the structure of the binary heap
void BinHeap :: ShowHeap( int i, int depth )
{
    if ( i <= heapSize ) {
        ShowHeap( right(i), depth+1 );
        cout << setw( depth*6 +4 ) << A[i] << endl;
        ShowHeap( left(i), depth+1 );
    }
}

// Just prints A[] as a horizontal array; may be used for debugging
void BinHeap :: PrintHeap()
{
    cout << "Heap elements in the array:\n";
    for ( int i = 1; i <= heapSize; i++ )
        cout << A[i] << " ";
    cout << endl;
}

// A routine that is useful for testing decreaseKey()
int BinHeap :: search( KeyType key )
{
    for ( int i = 1; i <= heapSize; i++ )
        if ( A[i] == key ) return i;
    return 0;
}


// For Assignment # 5
void BinHeap :: minHeapSort( )
{
    KeyType temp; // Used for swapping
    
    //You implement this for Assignment # 5
    buildMinHeap();
    for( int i = length; i > 1; i--) {
        temp = A[1];
        A[1] = A[i];
        A[i] = temp;
        heapSize =-1;
        minHeapify(1);
    }
}
