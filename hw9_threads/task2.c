// Create an array of integers with a few values.
// Write a function that calculates the sum of part of this array.
// Use two threads: assign each half of the array to a different thread.
// Each thread should calculate the sum of its half and print it.
// Expected Output: Two separate partial sums printed by each thread.
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int arr[] = {5, 8, 12, 3, 9, 15};
int size;

void* sum_part(void* arg) {
    int part = *(int*)arg;   //using part1,part2 variables to determine which half 
    // of the array the thread should take: 0 = first half, 1 = second half
    int sum = 0;

    int start, end;

    if (part == 0) { // take the first half of the arrayy
        start = 0;
        end = size / 2;
    } else { // take 2nd part of the array
        start = size / 2;
        end = size;
    }

    for (int i = start; i < end; i++) {
        sum += arr[i];
    }

    printf("Thread %d: partial sum = %d\n", part, sum);

    return NULL;
}

int main() {
    pthread_t t1, t2;
    int part1 = 0;
    int part2 = 1;

    size = sizeof(arr) / sizeof(arr[0]); //sizeof(arr) is the number of bytes in the whole arr: 6*4 = 24 bytes.
   
    pthread_create(&t1, NULL, sum_part, &part1);
    pthread_create(&t2, NULL, sum_part, &part2);

  
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
