#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    // memory = an array of bytes within RAM
    // memory block = a single unit (byte = 8 bits) within memory, used to hold some value
    // memory address = the address of where a memory block is located

    char a;
    double b[2];
    char c[69];

    printf("a is %d bytes\n", sizeof(a));
    printf("b is %d bytes\n", sizeof(b));
    printf("c is %d bytes\n", sizeof(c));

    printf("address of a: %p\n", &a);
    printf("address of b: %p\n", &b);
    printf("address of c: %p\n", &c);

    return 0;
}