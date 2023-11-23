#include <stdio.h>
#include <stdlib.h>

void helloWorld()
{
    printf("wassup\n");
}

int *Add(int *a, int *b)
{
    int c = (*a) + (*b);
    printf("c = %d\n", c);
    return &c;
}

int main()
{
    int a = 1, b = 69;
    int *ptr = Add(&a, &b);
    helloWorld();
    printf("sum is %d\n", *ptr);

    // this doesn't work because c in Add is local to Add
    // therefore, when Add is finished executing and returns the address of c the memory on the stack is freed
    // this means it can be used by other functions such as helloWorld() which might overwrite that address
}