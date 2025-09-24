#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> 

int main(){

    int child = fork();
    if(child == 0){
        printf("We're inside the child process. Child PID - %d\n", getpid());
    }
    else{
        //wait(NULL) //if we don't care about child's exit status.
         int status;
        wait(&status);  // parent waits for child to finish

        if (WIFEXITED(status)) {
            printf("Child finished with exit status %d\n", WEXITSTATUS(status));
        } else {
            printf("Child did not exit normally\n");
        }
        printf("Parent process: PID - %d\n", getpid());
    }


}