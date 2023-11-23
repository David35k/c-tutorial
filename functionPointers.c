#include <stdio.h>
#include <stdbool.h>

int add(int a, int b)
{
    return a + b;
}

int main()
{
    // return_type (*name)(parameter_types)
    // this is a pointer to a function with parameters of type (int, int) and a return type of int
    int (*p)(int, int);
    // int *p(int, int);   <--  This is a decleration of a function that returns a pointer to int, not what we want in this case

    p = &add;
    // p = add;  <--  This is the same as above, & is optional

    int c;
    c = (*p)(6, 9); // dereferencing a function pointer exectues the function it points to
    // c = p(6, 9);  <--  This is the same as the statement above, this one is more common i think
    printf("c = %d", c);

    return 0;
}