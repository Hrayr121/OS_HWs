#include <stdio.h>
#include <pthread.h>

long long counter = 0;
pthread_spinlock_t spin;
int N = 4;
int M = 1000000;

void* worker(void* arg) {
    for (int i = 0; i < M; i++) {
        pthread_spin_lock(&spin);
        counter++;
        pthread_spin_unlock(&spin);
    }
    return NULL;
}

int main() {
    pthread_t t[N];
    pthread_spin_init(&spin, 0);

    for (int i = 0; i < N; i++)
        pthread_create(&t[i], NULL, worker, NULL);

    for (int i = 0; i < N; i++)
        pthread_join(t[i], NULL);

    pthread_spin_destroy(&spin);

    printf("Expected = %lld\n", (long long)N * M);
    printf("Actual   = %lld\n", counter);
}
