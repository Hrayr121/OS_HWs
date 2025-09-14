#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>

int main() {

printf("Starting teh process, PID: %d\n", getpid());

    if (fork() < 0) { 
        perror("fork failed"); 
        exit(1); }
    if (fork() < 0) { 
        perror("fork failed"); 
        exit(1); }
    if (fork() < 0) { 
        perror("fork failed"); 
        exit(1); }

    printf("Process PID: %d, Parent PID: %d\n", getpid(), getppid());

    // keep processes alive to inspect them with pstree
    sleep(10); 

} 

