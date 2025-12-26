#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


void * thread_function(void* arg){
    printf("Hello from thread: \n");
    return NULL;
}

int main(){
    pthread_t thread;  //thread object

    if(pthread_create(&thread, NULL, thread_function, NULL ) != 0){
        perror("pthread_create");
        return 1;
    }

    printf("Thread cretaed. \n");

    if(pthread_join(thread, NULL) != 0){
        perror("pthread_join");
        return 1;
    }


    printf("Thread finished. \n");
    return 0;
}