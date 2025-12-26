#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>

int main() {

printf("Starting program, PID: %d\n", getpid());

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

    // keep processes alive so you can inspect them with `ps` or `pstree`
    sleep(15); 

} 