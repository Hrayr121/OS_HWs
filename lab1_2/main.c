#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int sum_array(const int *arr, int n); //declaation

int main(){
   //int arr[4];
    int arr_size = 4;

int *arr = (int *) malloc(arr_size * sizeof(int)); 

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    // Initializing the array
    for (int i = 0; i < arr_size; i++) {
        arr[i] = (i + 1) * 10; // 10, 20, 30, 40,
    }

    printf("Here's our array\n");
    printf("----------------\n");
    for (int i =0; i<arr_size; i++){
        printf("%d\n", arr[i]);
    }
    printf("----------------\n");

    int arr_sum = sum_array(arr, arr_size);
    printf("Array's sum: %d\n", arr_sum);

    int max_element = max_array(arr, arr_size);
    int occurence_amount = count_occurrences(arr, arr_size, 20);
    printf("Array's maximum element: %d\n", max_element);
    printf("Number of occuring values: %d\n", occurence_amount);


    free(arr);
    arr =NULL;
}