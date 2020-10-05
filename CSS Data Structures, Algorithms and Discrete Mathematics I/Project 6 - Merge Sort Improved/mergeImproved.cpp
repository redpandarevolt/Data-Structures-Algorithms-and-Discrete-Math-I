//
//  main.cpp
//  mergeImproved
//
//  Created by Marcela on 11/14/18.
//  Copyright © 2018 Marcela. All rights reserved.
//
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

//template class that sorts any element in an array
//mergeImproved merges a[left1....left2] and temp[right1 to right2]
template <class Comparable>
void mergesortImproved(vector<Comparable> &a, vector<Comparable> &temp, int first, int mid, int last){
    
    //initiates the first and last index of the left and right side subarrays that are to be merged.
    int left1 = first;
    int right1 = mid;
    int left2 = mid + 1;
    int right2 = last;
    
    for (int index = left1; index < right2 ; index++){
        
        // if the left side is smaller than the right add the left to the temp array and increase to the next index.
        if (left1 < right1 && (right1 >= right2 || a[left1] <= a[right1])){
            temp[index] = a[left1];
            left1++;
        // if the right side is larger then add the right to the temp and increase the index.
        } else {
            temp[index] = a[right1];
            right1++;
        }
    }
    /*for( ;left1 < right1; ++left1, ++index){
        temp[index] = a[left1];
    }
    for( ;left2 < right2; ++left2, ++index){
        temp[index] = a[left2];
    }
    for( index = first; index < last; index++){
        a[index] = temp[index];
    }*/
}


//template takes randomly generated array of numbers and sorts them form the base compenent of array length on and increases each time by length of 2, 4, 8, 10.

template <class Comparable>
void mergeImproved(vector<Comparable> &a) {
    int size = a.size();
    vector<Comparable> temp(size);
    
    //loop starts with the array sizes of one and increases
    // size = 1;
    // size = 2
    // size = 4, 8, 10 etc. 
    for(int length = 1; length < size; length = length * 2){
        
        for(int leftIndex = 0; leftIndex < size; leftIndex = leftIndex + 2 * length) {
            int rightIndex = min(leftIndex + length, size);
            int last = min(leftIndex + 2 * (length), size );
            mergesortImproved(a, temp, leftIndex, rightIndex, last);
        }
        a = temp;
    }
}

