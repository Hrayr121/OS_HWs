// Task 2: File truncation

// Use the fixed filename “data.txt”.
// Open/create it with O_WRONLY|O_CREAT|O_TRUNC (0644) and write the ASCII text: ABCDEFGHIJKLMNOPQRSTUVWXYZ (26 bytes). Close.
// Reopen with O_RDWR. Print the current size (by lseek(fd, 0, SEEK_END)).
// Truncate the file to the first 10 bytes using ftruncate.
// Print the new size (again via lseek).
// Rewind (lseek to 0) and read the remaining content, then print it to stdout.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
int fd;
char filename[] = "data.txt";
const char *text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // 26 bytes. thi
ssize_t written_bytes;


fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);  // create if data.txt doesn't exist
    if (fd == -1) {
        perror("open for write");
        exit(1);
    }


written_bytes = write(fd, text, strlen(text));
if(written_bytes == -1){
    perror("Write failed.");
        exit(1);
}

close(fd);

fd = open(filename, O_RDWR);
int size = lseek(fd, 0, SEEK_END);

printf("The current size of data.txt file is: %d\n", size );

int ftr = ftruncate(fd, 10);
if(ftr == -1){
    perror("ftruncate failed");
    close(fd);
    exit(1);
}
int size_after_ftrunc = lseek(fd, 0, SEEK_END);
printf("File size after truncation: %d\n", size_after_ftrunc);



      //rewind to start of file
    if (lseek(fd, 0, SEEK_SET) == -1) {
        perror("lseek");
        close(fd);
        return 1;
    }


    // We know max 10 bytes, so one read is enough
    char buf[11];      // 10 bytes + null terminator
    ssize_t n = read(fd, buf, 10); // reads 10 bytes from fd into buf 
    if (n == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    buf[n] = '\0';     // null-terminate string

    // Print to stdout
    write(STDOUT_FILENO, buf, n);

    close(fd);


 return 0;
}

