#include <stdio.h>

void triple(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        *(arr + i) = *(arr + i) * 3; 
    }
}

int main() {
    int arr[100]; 

    for (int i = 0; i < 100; i++) {
        *(arr + i) = i;
    }

    triple(arr, 100);

   printf("First 5 elements:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
    printf("\n");
    printf("\n");

    printf("Last 5 elements:\n");
    for (int i = 95; i < 100; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

   
   
    return 0;
}
