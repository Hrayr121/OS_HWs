#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> 

int main(){

    int child = fork();
    if(child == 0){
        printf("We're inside the child process. Child PID - %d\n", getpid());
        exit(0);
    }
    else{
        printf("Parent process: PID - %d\n", getpid());
    }


}