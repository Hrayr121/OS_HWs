#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int arr_size =12;
    int *arr= (int *) malloc(arr_size * sizeof(int));

    if (arr == NULL) {
        printf("Memory was not successfully allocated!\n");
        exit(1);
    }

    for (int i = 0; i < arr_size; i++) {
        arr[i] = 10 + i;
    }

    // Printing
    printf("-----------------------\n");
    printf("This is the array:\n");
    for (int i = 0; i < arr_size; i++) {
        printf("%d\n", arr[i]);
    }
    printf("-----------------------\n");
    printf("\n");

    int child = fork();
    if(child < 0){
        printf("Fork failed: no child process was created\n");
        exit(1);
    }
    if(child ==0){
        //inside the child process
         printf("Child (PID: %d) running...\n", getpid());
         int ret = execl("./child", "child", NULL);
         if (ret == -1){
            perror("execl");
            }
            printf("Afer exec\n");
    }
    //parent
    //wait(NULL) //if we don't care about child's exit status.
    int status;
        wait(&status);  // parent waits for chil to finish

        if (WIFEXITED(status)) {
            printf("Child finished with exit status %d\n", WEXITSTATUS(status));
        } else {
            printf("Child did not exit normally\n");
        }
        printf("Parent process: PID - %d\n", getpid());


    // Freeing the allocated memory
    free(arr);
    arr = NULL;
}