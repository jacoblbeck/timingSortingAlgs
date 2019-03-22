//
//  main.cpp
//  sortingAlgorithms
//
//  Created by Jacob Beck on 2/26/19.
//  Copyright © 2019 Jacob Beck. All rights reserved.
//

#include "quickSort.hpp"
#include "randomizedQuicksort.hpp"
#include "binHeap.hpp"
#include <stdlib.h>
#include <sys/time.h>
#include <iostream>

using namespace std;

int main(){
    //create objects
    quickSort qs;
    randomizedQuickSort rqs;
    BinHeap heap;
    int n = 10000;
    
    struct timeval tstart, tend, tdiff;
    struct timeval ttotal;
    
    //fills arrays for sorting
    for( int i = 1; i < n; i++) {
        qs.A[i] = i;
        rqs.A[i] = i;
        heap.A[i] = i;
    }
    
    
    timerclear(&ttotal);
    gettimeofday(&tstart,0);
    qs.sort(1, n-1);
    gettimeofday(&tend,0);
    timersub(&tend,&tstart,&tdiff);
    timeradd(&ttotal, &tdiff, &ttotal);
    double avg = (ttotal.tv_sec + ttotal.tv_usec/1000000.0);
    printf("quickSort time = %f\n", avg);
    
    timerclear(&ttotal);
    gettimeofday(&tstart,0);
    rqs.sort(1,n-1);
    gettimeofday(&tend,0);
    timersub(&tend,&tstart,&tdiff);
    timeradd(&ttotal, &tdiff, &ttotal);
    avg = (ttotal.tv_sec + ttotal.tv_usec/1000000.0);
    printf("randomizedQuickSort time = %f\n", avg);
    
    timerclear(&ttotal);
    gettimeofday(&tstart,0);
    heap.minHeapSort();
    gettimeofday(&tend,0);
    timersub(&tend,&tstart,&tdiff);
    timeradd(&ttotal, &tdiff, &ttotal);
    avg = (ttotal.tv_sec + ttotal.tv_usec/1000000.0);
    printf("heapSort time = %f\n", avg);
    
    return 0;
}
