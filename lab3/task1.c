
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){

    char src_path[512];
    char taget_path[512];


    printf("Enter source file path: ");
    scanf("%s", src_path);
    printf("Enter target file path: ");
    scanf("%s", target_path);
    int src_fd;
    int num_words =0;
    char buff[15];
    int fd_w;
	
    src_fd = open(src_path, O_RDONLY|O_WRONLY|O_CREAT, 0644);

        if(src_fd == -1){
        perror("'Open' system call failed: exiting");
        exit(1);}
    
    //ask for input 5 times and write in the file
    while(num_words<5){
    printf("Enter a string value to write in the file:");
    scanf("%s", buff);
   
    int n_written;
    n_written = write(src_fd, buff, strlen(buff));
        if(n_written == -1){
            perror("'Write' system call failed: exiting");
            exit(1);
        }

    num_words++;
    }
    

    //not reversing
    
    char buffer[11];
    int nw;

   int target_fd = open(target_path, O_RDONLY|O_WRONLY|O_CREAT, 0644);
        
   if(target_fd == -1){
        perror("'Open' system call failed: exiting");
        exit(1); }

    while((nr = read(src_fd, buffer, sizeof(buffer))) > 0){ //sizeof(buffer) tells read() the maximum number of bytes to read
        // reads from src_fd into buffer
        nw = write(target_fd, buffer, nr);
        if(nw == -1){
            perror("'Write' system call failed: exiting");
            exit(1);
        }

    }


    close(src_fd);
    close(target_fd);
return 0;
}
