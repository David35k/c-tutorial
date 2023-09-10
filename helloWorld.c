#include <stdio.h>
#include <string.h>

int main()
{
    // made them the same size because if strcpy(x, y) and y<x (length) you get weird stuff
    char x[15] = "king";
    char y[15] = "sus";
    char temp[15];

    printf("x = %s\n", x);
    printf("y = %s\n", y);

    strcpy(temp, x);
    strcpy(x, y);
    strcpy(y, temp);

    printf("new x = %s\n", x);
    printf("new y = %s\n", y);

    return 0;
}