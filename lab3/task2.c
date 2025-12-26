#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <pthread.h>


#define N 1000000
#define NUM_THREADS 4
int data[N];
int hist[10] = {0};
//INCOMPLETE
void * thread_function(void* arg){ //thread functions must accept a single void* argument (can cast it inside), and must return void
    int id = *(int*)arg;
    printf("Thread %d is running.... \n", id);
    return NULL;
}

int main(){

	
for (int i = 0; i < N; i++) {
    data[i] = i % 10;
}
    pthread_t threads[NUM_THREADS];
 
    for (int i=0; i<NUM_THREADS; i++){
         if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0) {
            perror("pthread_create");
            return 1;
        }
    }



    for(int i =0; i<NUM_THREADS; i++){
        if(pthread_join(threads[i], NULL) != 0){
        perror("pthread_join3");
        return 1;
    }
    }

return 0;
}



