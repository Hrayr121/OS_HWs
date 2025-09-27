#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t child1, child2;

    child1 = fork();

    if (child1 == 0) {
        printf("Child 1 (PID: %d) running...\n", getpid());
        sleep(2);  // simulate work
        exit(11);  // exit code 11
    }

    // Second child
    //Because we exited from child1, child2 will be created only by the parent process
    child2 = fork();

    if (child2 == 0) {
        printf("Child 2 (PID: %d) running...\n", getpid());
        sleep(1);  // simulate work 
        exit(22); 
    }

    // Parent process
    printf("Parent (PID: %d) waiting...\n", getpid());

    int status; 

    // Wait for the *second* child first, even though it may finish before child1
    pid_t finished = waitpid(child2, &status, 0); //waitpid returns the PID of the finished child.
    //status gets passed as an argument as a pointer, and then the function writes the encoded return info into it.
    //After that, we can use status variable to get the exit status code, get if it exited normally, etc...
    if (WIFEXITED(status)) {
        printf("Parent: Child 2 (PID: %d) exited with status %d\n",
                finished, WEXITSTATUS(status)); //WEXITSTATUS -> gets only the exit status from the encoded info in the status var.
    }

    // Now wait for the remaining child (any)
    finished = wait(&status);

    if (WIFEXITED(status)) {
        printf("Parent: Child 1 (PID: %d) exited with status %d\n",
               finished, WEXITSTATUS(status));
    }

    printf("Parent: All children finished.\n");

    return 0;
}