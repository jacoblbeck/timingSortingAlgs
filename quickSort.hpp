//
//  quickSort.hpp
//  sortingAlgorithms
//
//  Created by Jacob Beck on 2/26/19.
//  Copyright © 2019 Jacob Beck. All rights reserved.
//

#ifndef quickSort_hpp
#define quickSort_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

typedef int KeyType;
class quickSort {
    // Utility routines that need to access data members
    
    
public:
    // Class member variables
    KeyType* A;      // Only needs to be public for heap-sort
    void sort(int p, int r);
    int partition(int p, int r);
    void exchange(int a, int b);
    // Constructors, Destructor
    quickSort();
    ~quickSort();
};
#endif /* quickSort_hpp */
