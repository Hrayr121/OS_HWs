//Create an array of integers (e.g., [1, 2, 3, 4, 5]).
// For each number in the array, create a thread that calculates its square and prints the result (e.g., "Square of 2 is 4").
// Wait for all threads to finish before the main program exits.
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


void* thread_square_function(void * arg){
    int number = *(int*)arg;
    pthread_t tid = pthread_self();
    printf("Thread: %lu running.\n", (unsigned long)tid);
    int squared = number * number;
    printf("The square of %d is : %d. \n", number, squared);
    return NULL;
}

int main(){
    int arr[]={1,2,3,5,8,11};
    int length = sizeof(arr) / sizeof(arr[0]); 
    printf("The array's length is: %d\n", length);
    pthread_t threads[length];

    for(int i =0; i<length; i++){
        if(pthread_create(&threads[i], NULL,thread_square_function, &arr[i] ) !=0){
            perror("pthread_create");
            exit(1);
        }
    }

    for(int i=0; i<length; i++){
        if(pthread_join(threads[i], NULL) != 0){
            perror("pthread_join");
            exit(1);
        }
    }

    printf("All threads started successfully. Exiting the main program\n");
    return 0;



}