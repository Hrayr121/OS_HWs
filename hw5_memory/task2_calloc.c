#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    
    double sum = 0.0, average;

    printf("Hi! Enter the number of integers: ");
    scanf("%d", &n);

    int *arr = (int *) calloc(n, sizeof(int)); 

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // exit with error code
    }

    // Printing the initial values: Unlike malloc, calloc initilizes the values to 0 by default
    printf("\nInitial values (all zeroes):\n");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }

    // Get input from user
    printf("\n\nHellowu! Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    //sum and average
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    average = sum / n;

    // Print updated array
    printf("\nUpdated array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Print average
    printf("\n\nThe average of the integers is : %.2f\n", average);
   // %.2f =>floating-point number (f) with 2 digits after the decimal point.
   
    // Free the allocated memory
    free(arr);
    arr = NULL;
    return 0;
}
