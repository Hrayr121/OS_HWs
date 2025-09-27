#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
  
    int pid = fork();
    if(pid == 0){
        printf("Child process: PID=%d exiting now.\n", getpid());
        exit(0);
    }
    else{
         printf("Parent: PID=%d created child PID=%d\n", getpid(), pid);

         int status;
         wait(&status);  // parent waits for child to finish
        if (WIFEXITED(status)) {
            printf("Child finished with exit status %d\n", WEXITSTATUS(status));
        }
        sleep(30); 
        printf("Parent: enough sleep, let's exit.\n");
    }

    return 0;

}