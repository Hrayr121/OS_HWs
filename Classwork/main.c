#include <stdio.h>
#define GREETING "Hello World!"
//#include "math_operations.h"
#include "math_lib.h"

int def_global_var = 42;
int undef_global_var;
int undef_global_var_2;

int main() {
    int local_var = 10;
   // undef_global_var_2 = add(4,5);
   int addition_result = add(10,7);
    printf("%s\n", GREETING);
    printf("%d\n", addition_result);
    return 0;
}