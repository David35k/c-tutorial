#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{

    // bitwise operators = special operators used in bit level programming

    // & = AND
    // | = OR
    // ^ = XOR - exclusive or
    // << = LEFT SHIFT
    // >> = RIGHT SHIFT

    int x = 6;  //  6 = 00000110
    int y = 12; // 12 = 00001100
    int z = 0;  //  0 = 00000000

    z = x & y;
    printf("x & y = %d\n", z);
    
    z = x | y;
    printf("x | y = %d\n", z);
    
    z = x ^ y;
    printf("x ^ y = %d\n", z);
    
    z = x << 1;
    printf("x << 1 = %d\n", z);
    
    z = x << 3;
    printf("x << 3 = %d\n", z);
    
    z = x >> 1;
    printf("x >> 1 = %d\n", z);
    
    z = x >> 3;
    printf("x >> 3 = %d\n", z);


    return 0;
}