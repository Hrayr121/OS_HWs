#include <stdio.h> 
#include <stdlib.h>

int addition();

int main(){
  int result  = addition(5,6);
  printf("The result is: %d\n", result);
  return 0;
}

int addition(int a, int b){
    return a + b;
}