#include <stdio.h>
#include <pthread.h>
//gcc -pthread counter_no_sync.c -o counter_no_sync
long long counter = 0;
int N = 4;
int M = 1000000;

void* worker(void* arg) {
    for (int i = 0; i < M; i++)
        counter++; 
    return NULL;
}

int main() {
    pthread_t t[N];

    for (int i = 0; i < N; i++)
        pthread_create(&t[i], NULL, worker, NULL);

    for (int i = 0; i < N; i++)
        pthread_join(t[i], NULL);

    printf("Expected = %lld\n", (long long)N * M);
    printf("Actual   = %lld\n", counter);
}
