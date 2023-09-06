#include <stdio.h>
#include <stdbool.h>

int main()
{

    // math operations!!!

    // when dividing by an int you will lose the decimal point
    // you can either change the divisor variable to a float or
    // converting it by preseeding the type

    int x = 5;
    int y = 2;

    float z = x / (float)y; // 2 becomes 2.0

    int a = x % y; // modulus same as other languages, gives remainder of division

    printf("%f\n", z);
    printf("%d\n", a);

    // incrementing same as other languages, ++ --

    return 0;
}