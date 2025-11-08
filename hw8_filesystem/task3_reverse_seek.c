// Reverse file reader

// Objective: Print a file’s bytes in reverse order using lseek to move backward.

// Requirements:

// Prompt the user to enter a path to an existing text file.
// Open it read-only. Determine file size with lseek(fd, 0, SEEK_END).
// Starting from the last byte, repeatedly: lseek to the target position, read 1 byte, write that byte to standard output.
// After finishing, write a newline.
// Handle empty files (print just a newline).

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){

    char file_path[512];
    
    printf("Enter the path to an existing text file: ");
    scanf("%s", file_path);

    int fd = open(file_path, O_RDONLY);

    int file_size = lseek(fd, 0, SEEK_END);
    if(file_size == -1){
        perror("lseek failed!");
        close(fd);
        exit(1);
    }

    if(file_size == 0){
        printf("The file is empty. \n");
        close(fd);
        return 0;
    }

    char a;
    file_size -=1;
    while(file_size >= 0){ // the text is indexed from 0 to (file_size-1)

        if(lseek(fd, file_size, SEEK_SET) == -1){
            perror("lseek failed!");
            close(fd);
            exit(1);
        } 
        
        if (read(fd, &a, 1) != 1) {
            perror("read");
            close(fd);
            return 1;
        }

        write(STDOUT_FILENO, &a, 1);
        file_size -=1;
    }
    printf("\n");


    close(fd);
    return 0;
}














