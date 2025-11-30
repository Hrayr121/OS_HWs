#include <stdio.h>
#include <pthread.h>

long long counter = 0;
pthread_mutex_t mutex;
int N = 4;
int M = 1000000;

void* worker(void* arg) {
    for (int i = 0; i < M; i++) {
        pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t t[N];
    
    pthread_mutex_init(&mutex, NULL); // we need to initializ mutex only once, and it's available for all threads

    for (int i = 0; i < N; i++)
        pthread_create(&t[i], NULL, worker, NULL);

    for (int i = 0; i < N; i++)
        pthread_join(t[i], NULL);

    pthread_mutex_destroy(&mutex);
    printf("Expected = %lld\n", (long long)N * M);
    printf("Actual   = %lld\n", counter);
}
