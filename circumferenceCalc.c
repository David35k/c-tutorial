#include <stdio.h>
#include <math.h>

int main()
{
    // C = 2πr

    const double PI = 3.14159;
    double radius;
    double circumference;
    double area;

    printf("\nI will find the circumference and area of a circle. What is the radius?");
    scanf("%lf", &radius);

    circumference = 2 * PI * radius;
    area = PI * pow(radius, 2);

    printf("\nThe circumference is %lf units and the area is %lf units", circumference, area);

    return 0;
}