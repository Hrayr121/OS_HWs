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

//..waitpid()
//    int status;

//     // Wait for the *second* child first, even though it may finish before child1
//     pid_t finished = waitpid(child2, &status, 0);

//     if (WIFEXITED(status)) { //Did the child terminate normally (i.e., via exit() or returning from main)?
                                //If yes → then you can safely extract the exit code.
//         printf("Parent: Child 2 (PID: %d) exited with status %d\n",
//                finished, WEXITSTATUS(status)); ///extracts just the exit code (the argument passed to exit()
//     }

//     // Now wait for the remaining child (any)
//     finished = wait(&status);

//     if (WIFEXITED(status)) {
//         printf("Parent: Child 1 (PID: %d) exited with status %d\n",
//                finished, WEXITSTATUS(status));
//     }