#include "util.h"

int sum_array(const int *arr, int n){
    double sum =0;
    for(int i =0; i <n; i++){
        sum+= arr[i];
    }
    return sum;
}

int max_array(const int *arr, int n){
    int max_elem;
    if(n>0){
        for(int i =0; i<n; i++){
            if(arr[i] > max_elem){
                max_elem = arr[i];
            }
        }
        return max_elem;
    }
    else{
        return -9999;
    }
}

int count_occurrences(const int *arr, int n, int value){
    int count = 0; //init to 0
    for(int i =0; i<n; i++){
        if(arr[i] == value){
            count++;
        }
    }
    return count;
}
