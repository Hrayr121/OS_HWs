// Write a C program using pthreads and semaphores that:
// Creates 3 threads: thread_A, thread_B, thread_C.
// Each thread runs a loop from i = 0 to N - 1 and prints, for example:
// Thread A: A i
// Thread B: B i
// Thread C: C i
// The output must always follow this order: A 0 B 0 C 0 A 1 B 1 C 1 ...
// Use only semaphores to enforce ordering (no busy-wait and no sleep() for ordering):
// Example: sem_t semA, semB, semC;
// Initialize so that only A can run first.
// Each thread waits on its own semaphore and posts the next thread’s semaphore.
// You may use a mutex only to protect printf if you want cleaner output, but not for ordering.



#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5     // number of iterations

sem_t semA, semB, semC;

void* thread_A(void* arg) {
    for (int i = 0; i < N; i++) {
        sem_wait(&semA);               // Wait until it's A’s turn
        printf("Thread A: A %d\n", i);
        sem_post(&semB);               // Signal B
    }
    return NULL;
}

void* thread_B(void* arg) {
    for (int i = 0; i < N; i++) {
        sem_wait(&semB);               // Wait until it's B’s turn
        printf("Thread B: B %d\n", i);
        sem_post(&semC);               // Signal C
    }
    return NULL;
}

void* thread_C(void* arg) {
    for (int i = 0; i < N; i++) {
        sem_wait(&semC);               // Wait until it's C’s turn
        printf("Thread C: C %d\n", i);
        sem_post(&semA);               // Signal A
    }
    return NULL;
}

int main() {
    pthread_t A, B, C;

    // Initialize semaphores
    sem_init(&semA, 0, 1);   // A starts
    sem_init(&semB, 0, 0);   // B waits
    sem_init(&semC, 0, 0);   // C waits

    pthread_create(&A, NULL, thread_A, NULL);
    pthread_create(&B, NULL, thread_B, NULL);
    pthread_create(&C, NULL, thread_C, NULL);

    pthread_join(A, NULL);
    pthread_join(B, NULL);
    pthread_join(C, NULL);
    sem_destroy(&semA);
    sem_destroy(&semB);
    sem_destroy(&semC);

    return 0;
}
