#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h> 

int main() {
    printf("Hello from VS Code + clang!\n");

    int a = 5;
    int *p = &a;

    printf("x = %d\n", a);      // prints 5
    printf("p = %p\n", p);      // prints address of a
    printf("*p = %d\n", *p);    // prints value at that address → 15

    *p = 20;  // changes the value of x via the pointer
    printf("a after change = %d\n", a);  // prints 20


    if (fork() == 0) // child process because return value zero
    printf("Hello from Child!\n");
    else // parent process because return value non-zero.
    printf("Hello from Parent!\n"); 
    return 0;
}