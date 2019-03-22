//
//  quickSort.cpp
//  sortingAlgorithms
//
//  Created by Jacob Beck on 2/26/19.
//  Copyright © 2019 Jacob Beck. All rights reserved.
//

#include "quickSort.hpp"
#include <iostream>
#include <iomanip>

quickSort :: quickSort(){
    A = new KeyType[10000];
}

quickSort :: ~quickSort(){
    delete[] A;
}

void quickSort :: sort(int p, int r){
    if( p < r ) {
        int q = partition(p,r);
        sort(p,q-1);
        sort(q+1,r);
    }
    
}

int quickSort :: partition(int p,int r) {
    int x = A[r];
    int i = p - 1;
    for( int j = p; j < r-1; j++) {
        if(A[j] <= x) {
            i++;
            exchange(i,j);
        }
    }
    exchange(i+1,r);
    return i + 1;
}

void quickSort:: exchange(int a, int b){
    int temp = a;
    A[a] = A[b];
    A[b] = temp;
}
