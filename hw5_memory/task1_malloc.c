#include <stdio.h>
#include <stdlib.h> 

int main() {
    int n, i, sum = 0;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    int *arr = (int *) malloc(n * sizeof(int));
    //malloc(n * sizeof(int)); returns a void pointer. 
    // We typecast it to int pointer with (int *) and assign it to our arr* pointer, which points to the 
    // first byte of the memory block allocated in the heap by malloc .
    
    // Checking if memory allocation was successfu
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Get input from the user
    printf("Yo, user! enter your %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        sum += arr[i];
    }

    printf("The sum of the integers is: %d\n", sum);

    free(arr);
    arr = NULL;

    return 0;
}
