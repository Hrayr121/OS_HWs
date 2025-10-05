#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i;
    int numStrings = 3;
    int strLength = 50;

    // Allocate memory for 3 string pointers
    char **arr = (char **) malloc(numStrings * sizeof(char *));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    //Allocate memory for each string
    for (i = 0; i < numStrings; i++) {
        arr[i] = (char *) malloc(strLength * sizeof(char));

        if (arr[i] == NULL) {
            printf("Memory allocation failed for string %d!\n", i);
            return 1;
        }
    }

    printf("Enter %d strings (up to %d characters each):\n", numStrings, strLength);
    for (i = 0; i < numStrings; i++) {
        printf("String %d: ", i + 1);
        fgets(arr[i], strLength + 1, stdin);
        // Remove trailing newline if present
        arr[i][strcspn(arr[i], "\n")] = '\0';
    }

    // Print the 3 strings
    printf("\nYou entered:\n");
    for (i = 0; i < numStrings; i++) {
        printf("%s\n", arr[i]);
    }

    // Resizing array usin realloc to hold 5 strings
    numStrings = 5;
    arr = (char **) realloc(arr, numStrings * sizeof(char *));
    if (arr == NULL) {
        printf("Reallocation failed!\n");
        return 1;
    }

    // Allocate memory for the new 2 strings
    for (i = 3; i < numStrings; i++) {
        arr[i] = (char *) malloc((strLength + 1) * sizeof(char));
        if (arr[i] == NULL) {
            printf("Memory allocation failed for string %d!\n", i);
            return 1;
        }
    }

    // Input 2 additional strings
    printf("\nEnter 2 more strings:\n");
    for (i = 3; i < numStrings; i++) {
        printf("String %d: ", i + 1);
        fgets(arr[i], strLength + 1, stdin);
        arr[i][strcspn(arr[i], "\n")] = '\0'; // Remove newline
    }

    printf("\nAll strings:\n");
    for (i = 0; i < numStrings; i++) {
        printf("%s\n", arr[i]);
    }

    for (i = 0; i < numStrings; i++) {
        free(arr[i]);
    }
    free(arr);
    arr = NULL;

    return 0;
}
