//At the start, prompt the user (via standard input) to type the source file path, then the destination file path
// Open the source for reading (O_RDONLY). Open/create the destination with O_WRONLY|O_CREAT|O_TRUNC and mode 0644.
// Repeatedly read from source and write to destination until EOF (read returns 0).
// Count and print the total number of bytes copied.
// Print an error if any system call fails.


#include <stdio.h>
#include <stdlib.h>

int main(){
    char src_path[512];
    char dest_path[512];
    printf("Enter source file path: ");
    scanf("%s", src_path);
    printf("Enter destination file path: ");
    scanf("%s", dest_path);

    int src_fd;

    src_fd = open(src_path, O_RDONLY); // mode argument is skipped here. It'll be required if O_CREAT is used
    //by default: 0644
    //the source file should already exist, otherwise open will fail
       if(src_fd == -1){
        perror("'Open' system call failed: exiting");
        exit(1);
    }

    int dest_fd = open(dest_path, O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if(dest_fd == -1){
        perror("'Open' system call for the destination file failed: exiting");
        exit(1);
    }

    int nr;
    int nw;
    char buffer[512];
    int total_written_bytes = 0;

    while((nr = read(src_fd, buffer, sizeof(buffer))) > 0){ //sizeof(buffer) tells read() the maximum number of bytes to read, but read() may read fewer bytes than that in each iteration.
        nw = write(dest_fd, buffer, nr);
        if(nw == -1){
            perror("'Write' system call failed: exiting");
            exit(1);
        }
        total_written_bytes += nw;
    }

    if(nr == -1){
        perror("'Read' system call failed: exiting");
        exit(1);
    }

    
    printf("Total bytes copied: %d\n", total_written_bytes);
    close(src_fd);
    close(dest_fd);
    return 0;
}