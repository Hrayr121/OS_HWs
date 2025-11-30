#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

// Mode chosen via command-line argument(one of these)
// ./bank mutex short
// ./bank mutex long
// ./bank spin short
// ./bank spin long


long long balance = 0;

// Lock objects
pthread_mutex_t mutex;
pthread_spinlock_t spin;

// Runtime mode
int use_mutex = 1;   // default
int long_cs   = 0;   // default = short critical section

// Worker parameters
int deposit_threads = 4;
int withdraw_threads = 4;
int operations_per_thread = 200000;   // can be adjusted

// Lock/unlock helpers
void lock() {
    if (use_mutex)
        pthread_mutex_lock(&mutex);
    else
        pthread_spin_lock(&spin);
}

void unlock() {
    if (use_mutex)
        pthread_mutex_unlock(&mutex);
    else
        pthread_spin_unlock(&spin);
}

// Deposit worker
void* deposit_worker(void* arg) {
    for (int i = 0; i < operations_per_thread; i++) {
        lock();

        balance++;
        if (long_cs)
            usleep(100); // long critical section

        unlock();
    }
    return NULL;
}

// Withdraw worker
void* withdraw_worker(void* arg) {
    for (int i = 0; i < operations_per_thread; i++) {
        lock();

        balance--;
        if (long_cs)
            usleep(100); // this i the long critical section

        unlock();
    }
    return NULL;
}

// Small helper for timing
double now_sec() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec / 1e9;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <mutex|spin> <short|long>\n", argv[0]);
        return 1;
    }

    // Reading the arguments from commandline
    if (strcmp(argv[1], "mutex") == 0)
        use_mutex = 1;
    else if (strcmp(argv[1], "spin") == 0)
        use_mutex = 0;
    else {
        printf("Unknown lock type: %s\n", argv[1]);
        return 1;
    }

    if (strcmp(argv[2], "long") == 0)
        long_cs = 1;
    else if (strcmp(argv[2], "short") == 0)
        long_cs = 0;
    else {
        printf("Unknown mode: %s\n", argv[2]);
        return 1;
    }

    printf("Running: lock=%s, critical_section=%s\n",
           use_mutex ? "mutex" : "spin",
           long_cs ? "long" : "short");

    // Init lock
    if (use_mutex)
        pthread_mutex_init(&mutex, NULL);
    else
        pthread_spin_init(&spin, 0);

    pthread_t threads[deposit_threads + withdraw_threads];

    double start = now_sec();

    // Create deposit threads
    for (int i = 0; i < deposit_threads; i++)
        pthread_create(&threads[i], NULL, deposit_worker, NULL);

    // Create withdraw threads
    for (int i = 0; i < withdraw_threads; i++)
        pthread_create(&threads[deposit_threads + i],
                       NULL, withdraw_worker, NULL);

    // Join all
    int total = deposit_threads + withdraw_threads;
    for (int i = 0; i < total; i++)
        pthread_join(threads[i], NULL);

    double end = now_sec();

    // Cleanup locks
    if (use_mutex)
        pthread_mutex_destroy(&mutex);
    else
        pthread_spin_destroy(&spin);

    printf("Final balance = %lld (expected 0)\n", balance);
    printf("Time taken: %.6f seconds\n", end - start);

    return 0;
}
