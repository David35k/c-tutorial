#include <stdio.h>
#include <stdlib.h>

int main() {

    //static
    int num = 69;
    printf("num - value: %d, size: %d bytes\n", num, sizeof(num));

    //dynamic

    // calling malloc is asking for memory block of certain size
    // it returns pointer to the memory
    // returns NULL if cant allocate the memory
    int *x = malloc(sizeof(int)); //memory for one int
    int *arr = malloc(sizeof(int) * 100); //memory for 100 ints

    *x = 69420;

    arr[50] = 100;

    printf("*x - value: %d, size: %d bytes\n",*x, sizeof(*x));
    printf("arr[50] - value: %d\n", arr[50]);

    arr[500] = 69; // OUT OF BOUNDS - BAD


    // use free to tell the allocator you dont need the memory anymore
    // good practice to set the pointer to NULL to check if empty later
    free(x);
    x = NULL;
    free(arr);
    arr = NULL;

    // printf("%d\n", *x); // seg fault, cant access freed block
    // free(arr); // also trying to free a freed block is bad

    // calloc is similar to malloc
    // intended for an array of nums
    // sets all bits of each element to 0
    double *darr = calloc(sizeof(double), 100);
    // same as darr = malloc(sizeof(double) * 100);

    darr[50] = 69.69;

    printf("darr is at: %p\n", darr);
    printf("darr[50] - value: %lf, size: %d bytes\n", darr[50], sizeof(darr[50]));
    printf("this should be 0: %lf\n", darr[69]);


    // realloc lets you change the size of a block
    // THE ADDRESS OF THE NEW BLOCK COULD BE DIFFERENT!!
    // if new block cant fit it has to find new place

    darr = realloc(darr, sizeof(double)*200);

    darr[499] = 420.69;

    printf("darr is now at: %p\n", darr);
    printf("darr[50] - value: %lf, size: %d bytes\n", darr[50], sizeof(darr[50]));
    printf("darr[499] - value: %lf, size: %d bytes\n", darr[499], sizeof(darr[50]));
    printf("this should be 0: %lf\n", darr[69]);

    return 0;
}