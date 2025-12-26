
#include <stdio.h>


struct TwoInts {
    char c;
    int first;
    int second;
};

void printStruct(struct TwoInts s) {
    printf("First: %d, Second: %d, Char: %c\n", s.first, s.second, s.c);
}

int main() {
    struct TwoInts example = { .first = 1, .second = 2, .c = 'a' };
    printStruct(example);
    printf("Size of struct TwoInts: %zu bytes\n", sizeof(struct TwoInts));
    return 0;
}   

//in the memory, for our struct, 4 bytes for int, 1 byte for char, and 3 bytes padding to align to 4 bytes boundary.
//So total size is 4 + 4 + 1 + 3 = 12 bytes.//But if we reorder the struct members to put char last, we can reduce padding??



