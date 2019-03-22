//
//  randomizedQuicksort.cpp
//  sortingAlgorithms
//
//  Created by Jacob Beck on 2/26/19.
//  Copyright © 2019 Jacob Beck. All rights reserved.
//

#include "randomizedQuicksort.hpp"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>

randomizedQuickSort :: randomizedQuickSort(){
    A = new KeyType[10000];
}

randomizedQuickSort :: ~randomizedQuickSort(){
    delete[] A;
}

int randomizedQuickSort:: randomizedPartition(int p, int r){
    int i = p + rand() % (r - p + 1);
    exchange(r, i);
    return partition(p,r);
}


void randomizedQuickSort :: sort(int p, int r){
    if(p < r) {
        int q = randomizedPartition(p,r);
        sort(p,q-1);
        sort(q+1,r);
    }
}

int randomizedQuickSort :: partition(int p,int r) {
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

void randomizedQuickSort ::  exchange(int a, int b){
    int temp = a;
    A[a] = A[b];
    A[b] = temp;
}
