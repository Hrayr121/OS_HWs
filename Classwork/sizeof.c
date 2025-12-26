#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = malloc(5 * sizeof(int));
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of array: %zu bytes\n", sizeof(arr));
    free(arr);

//%zu → the correct format specifier for size_t (which is the type returned by sizeof).
// Note: sizeof(arr) returns the size of the pointer, not the allocated memory.
// On a 64-bit system, this will typically print 8 bytes for the pointer size.
// On a 32-bit system, it will typically print 4 bytes for the pointer size.
// To get the size of the allocated memory, we would need to keep track of it separately.
// The sizeof operator in C returns the size in bytes of a type or a variable.

int a = 10;
char c = 'A';

printf("Size of the int is: %zu bytes\n" , sizeof(a)); // Outputs size of int
printf("Size of the char is: %zu bytes\n" , sizeof(c)); // Outputs size of char
printf("Memory address of a: %p\n", (void*)&a); // &a returns the address of variable a, (void*) casts it to a void pointer, which is a generic pointer type in C.
printf("Memory address of c: %p\n", (void*)&c);


return 0;

}
