#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> 
#include <sys/wait.h>

int main(){

    int num = 17;
    int *p = &num;

    printf("Pointer's address: %p\n", p);      // prints pointer's address
    printf("Pointer value: Y. %d\n", *p);    // prints value at that address 
    printf("value stored at the address pointed by the pointer is:  %d\n", num); 
    printf("Int value: Z. %d\n", num);
    
    
    int child = fork();

    if(child < 0){
      perror("Fork failed");
      exit(1);

    } 
    if(child == 0){
      printf("Executing child program.\n");

      //It is manadatory to build the child_memory.c into an executable called "child_memory", otherwise
      //execl won't find that file as given in the below argument, and won't load anything.
        execl("./child_memory", "child_memory", NULL);

        // usually, execl() does not return. On error, however, execl() returns −1
        //execl won't continue from this point onward, because it has a new process image. If it reaches "perror"
        //line, that means that execl failed, returned -1.
        //execl's args -> 1st one is the path to the program, 2nd: the command that will be exected. NULL: to end the list of args.
        ///We can also pass multiple executable args like this: 
        //execl("path/to/progam", "ls","-la", NULL); -> this way, it'll run "ls -la" in the given path
        // If exec returns, it failed
        perror("execl failed");
        exit(1);
    }
    else{
     printf("This is the parent process again\n");
     printf("Parent PID: %d\n", getpid());

     int exit_status;
    
     wait(&exit_status);

     if (WIFEXITED(exit_status)) {
            printf("Child finished with the following exit status %d\n", WEXITSTATUS(exit_status));
            *p = 37;
            printf("num's new value: %d\n", num);
            }
            else
            {      
             printf("Something went wrong with child.\n"); 
            }
    return 0;
}

}
