#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> 
#include <sys/wait.h>

void function1();
void function2();

int main(){
 atexit(function1);
 printf("We're inside the main function.\n");

 if (atexit(function2) != 0) {
        perror("Failed to register function2");
        return 1;
    }

 printf("Functions were registered with atexit().\n");
 sleep(2);
 return 0;
}

void function1(){
    printf("Main is calling.\n");
    printf("This is the 1st function.\n");
}

void function2(){
    printf("This is the 2nd function.\n");
}