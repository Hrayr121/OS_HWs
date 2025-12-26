#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printArray(int *pointer, int size );
int main(){
    printf("Heyy! I'm the child process.\n");
    int n =7;
    sleep(2); // Simulate some work
        printf("Child process: PID = %d, PPID = %d\n", getpid(), getppid());
        printf("--------------\n");

    //Allocate an integer array of size 7 using calloc.
    int *arr = (int*) calloc(n, sizeof(int));

    printArray(arr, n);
     
    // for(int i = 0; i<n; i++){
    //     scanf("%d", &arr[i]);
    // }
    //     return 0

    //arr = realloc(arr, 10*sizeof(int)); can do this, but if realloc fails, it returns NULL and assigns it to our
    //*arr pointer => our pointer will be lost.
    //safer way

    n = 10;
    int *temp = realloc(arr, n * sizeof(int));
    if (temp == NULL) {
        perror("realloc failed");
        free(arr);
        exit(1);
    }
    arr = temp;

    //Set the new elements (from index 5 to 9) to values 101 to 105.
    for(int i=5; i<=9; i++){
        arr[i] = 96+i;
    }
    printf("Here's our expanded array.\n");
    printArray(arr, n);

    //shrink to 4
    n =4;
    int *temp1 = realloc(arr, n * sizeof(int));
     if (temp1 == NULL) {
        perror("realloc failed");
        free(arr);
        exit(1);
    }
    arr = temp1;
    printf("Shrinked arrray:\n");
    printArray(arr, n);
    free(arr);
    arr =NULL;
    //we don't need to free temp and temp1 pointers, because we used realloc, which will eihter make the 
    //temp pointer point to the same arr, or create a new memory block, copy arr's contents, point arr to it, and free the previous memory block.
     

}

void printArray(int *pointer, int size ){
    for(int i =0; i<size; i++){
        printf("%d\n", pointer[i]);
    }
    printf("-----------------\n");
}