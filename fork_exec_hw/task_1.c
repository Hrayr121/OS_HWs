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
        printf("Child process running ls...\n");
        execl("/bin/ls", "ls", "-l", (char *)NULL);

        // If execl fails we only get here
        perror("execl failed");
        exit(1);
    } else {
        // Parent process
        printf("Parent process done\n");
    }

    return 0;
}
