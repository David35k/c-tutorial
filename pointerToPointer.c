#include <stdio.h>

int main()
{
    int x = 69;         // int
    int *pX = &x;       // pointer to int
    int **pPX = &pX;    // pointer to pointer to int
    int ***pPPX = &pPX; // pointer to pointer to pointer to int

    printf("value: %d, address: %p\n", *pX, pX);
    printf("value: %p, address: %p\n", *pPX, pPX);
    printf("value: %p, address: %p\n", *pPPX, pPPX);

    printf("original value: %d\n", *(*(*pPPX)));

    ***pPPX = 420;

    printf("changed variable: %d\n", x);

    return 0;
}