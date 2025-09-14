#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // fork failed
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        execl("/bin/echo", "echo", "Hello from the child process", NULL);

        // If execl fails, this runs
        perror("execl failed");
        exit(1);
    } else {
        // Parent process
        // Parent waits for child to finish
        wait(NULL);
        printf("Parent process done\n");

    }

    return 0;
}
