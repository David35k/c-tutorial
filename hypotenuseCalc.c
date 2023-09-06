// Finds the hypotenuse of a triangle
// a^2 + b^2 = c^2

#include <stdio.h>
#include <math.h>

int main()
{
    // Main variables
    double a;
    double b;
    double c;

    printf("\nSide a: ");
    scanf("%lf", &a);
    printf("Side b: ");
    scanf("%lf", &b);

    c = sqrt(pow(a, 2) + pow(b, 2));

    printf("Side c3: %lf", c);

    return 0;
}