#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> 
#include <sys/wait.h>

int main() {
    int status;

    // First child
    int child1 = fork();
    if (child1 < 0) {
        perror("fork");
        exit(1);
    }

    if (child1 == 0) {
        printf("We're inside child1. PID = %d\n", getpid());
        sleep(2);
        exit(0);  // if we don't exit, the child process will try to  execute whatever else is written afterwards, but actually not intended fir him
    } else {
        wait(&status);
        if (WIFEXITED(status)) {
            printf("Parent: Child1 exited with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Parent: Child1 did not exit normally\n");
        }
        printf("Parent process: PID = %d\n", getpid());
    }

    // Only the parent creates child2
    //Although we've exited from child1, this if is like another checkpoint to make sure that only the parent
    //can create the second child process, because child1's pid is >0 only for the parent.
    if (child1 > 0) {
        int status2;
        int child2 = fork();
        if (child2 < 0) {
            perror("fork");
            exit(1);
        }

        if (child2 == 0) {
            printf("We're inside child2. PID = %d\n", getpid());
            sleep(2);
            exit(0);
        } else {
            int finished_pid = waitpid(child2, &status2, 0);
            if (WIFEXITED(status2)) {
                printf("Parent: Child2 (PID %d) exited with status %d\n",
                       finished_pid, WEXITSTATUS(status2));
            }
        }
    }

    return 0;
}

