#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
// Write a C program that creates three threads.
// Each thread should print a message, including its thread ID, to indicate it is running (e.g., "Thread X is running").
// Ensure the main thread waits for each of the threads to complete using pthread_join.
// Expected Output: Each thread prints a message, and the program exits only after all threads are complete.


void * thread_function(void* arg){ //thread functions must accept a single void* argument (can cast it inside), and must return void
    int id = *(int*)arg;
    printf("Thread %d is running.... \n", id);
    return NULL;
}

int main(){
    pthread_t thread1;  //thread object
    pthread_t thread2;
    pthread_t thread3;
    int tid1 =1;
    int tid2 =2;
    int tid3 = 3;
    // Not sure why, but I didn't use for loops to create the threads and wait/join for them. Just did one by one.
    if(pthread_create(&thread1, NULL, thread_function, &tid1 ) != 0){
        perror("Thread1 creation failed");
        return 1;
    }
    if(pthread_create(&thread2, NULL, thread_function, &tid2 ) != 0){
        perror("Thread2 creation faile");
        return 1;
    }
    if(pthread_create(&thread3, NULL, thread_function, &tid3 ) != 0){
        perror("Thread3 creation failed");
        return 1;
    }

    printf("All 3 Threads are creataed. \n");
   
    if(pthread_join(thread1, NULL) != 0){
        perror("pthread_join1");
        return 1;
    }

    if(pthread_join(thread2, NULL) != 0){
        perror("pthread_join2");
        return 1;
    }

    if(pthread_join(thread3, NULL) != 0){
        perror("pthread_join3");
        return 1;
    }


    printf("Thread finished. \n");
    return 0;
}