#include <stdio.h>

void hello(char[], int); // <-- function prototype

int main()
{
    // function prototype

    // functiond ecleration, without a body, before main()
    // ensures that calls to a function are made with the correct arguments

    // important notes
    // many C compilers do not check for parameter checking
    // missing arguments will result in unexpected behaviour
    // a function prototype causes the compiler to flag an error if arguments are missing

    // advantages
    // 1. easier to navigate a program with main() at the top
    // 2. helps with debugging
    // 3. commonly used in header files

    char name[] = "david";
    int age = 16;

    hello(name, age);

    return 0;
}

void hello(char name[], int age)
{
    printf("hello %s, you are %d years old", name, age);
}