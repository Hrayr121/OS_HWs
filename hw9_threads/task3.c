// Write a program that creates three threads.
// Each thread should print numbers from 1 to 5, along with its thread ID.
// Observe that the order of printing may vary between runs, showing the concurrent execution.
// Expected Output: Each thread prints numbers from 1 to 5, but in potentially varying orders.

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* thread_func(void * arg){
    int id = *(int*)arg;
    pthread_t tid = pthread_self();
    printf("Thread: %d running. Thread_ID: %lu.\n", id, (unsigned long)tid);
    for(int i = 0; i<5; i++){
        printf("%d ", i);
    }
    printf("\n");
    return NULL;
}

int main(){

    pthread_t threads[3];
    int ids[3] = {1, 2, 3};

    for (int i=0; i<3; i++){
         if (pthread_create(&threads[i], NULL, thread_func, &ids[i]) != 0) {
            perror("pthread_create");
            return 1;
        }
    }

    for(int i =0; i<3; i++){
        if(pthread_join(threads[i], NULL) != 0){
        perror("pthread_join3");
        return 1;
    }
    }

    printf("All Threads finished. \n");
    return 0;

}