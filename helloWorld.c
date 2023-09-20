#include <stdio.h>
#include <string.h>
#include <ctype.h>

void printAge(int *pAge)
{
    printf("you are %d years old", *pAge); // dereference
}

int main()
{
    // POINTERS!!! = a "variable-like" that holds a memory address to another variable, array etc.
    // some tasks are performed more easily with pointers
    // * = indirection operator (value at address)

    int age = 16;
    int *pAge = NULL; // good practice to assign NULL if declaring pointer
    pAge = &age;

    printAge(pAge);

    // printf("address of age: %p\n", &age);
    // printf("value of pAge : %p\n", pAge);

    // printf("size of age: %d bytes\n", sizeof(age));
    // printf("size of pAge : %d bytes\n", sizeof(pAge));

    // printf("value of age: %d\n", age);
    // printf("value at stored address: %d\n", *pAge); // dereferencing

    return 0;
}