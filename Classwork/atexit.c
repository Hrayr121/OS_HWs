#include <stdlib.h>
#include <stdio.h>

void cleanup();

int main(void){. // void means that main takes no parameters
    atexit(cleanup);
    printf("Doing some work inside main\n");
    
    return 0;
}
void cleanup(){
    printf("Triggered from atexit()\n");
}