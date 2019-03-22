//
//  randomizedQuicksort.hpp
//  sortingAlgorithms
//
//  Created by Jacob Beck on 2/26/19.
//  Copyright © 2019 Jacob Beck. All rights reserved.
//

#ifndef randomizedQuicksort_hpp
#define randomizedQuicksort_hpp

#include <stdio.h>


#include <iostream>

using namespace std;

typedef int KeyType;
class randomizedQuickSort {
    // Utility routines that need to access data members
    
    
public:
    // Class member variables
    KeyType* A;      // Only needs to be public for heap-sort
    void sort(int p, int r);
    int randomizedPartition(int p, int r);
    int partition(int p, int r);
    void exchange(int a, int b);
    // Constructors, Destructor
    randomizedQuickSort();
    ~randomizedQuickSort();
};


#endif /* randomizedQuicksort_hpp */
