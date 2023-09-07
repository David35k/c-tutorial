#include <stdio.h>
#include <string.h>

int main()
{
    double prices[] = {5.0, 7.5, 3.99, 74.99, 14.99};

    size_t size = sizeof(prices) / sizeof(prices[0]);

    printf("%d elements in the array\n", size);

    for (int i = 0; i < size; i++)
    {
        printf("$%.2lf\n", prices[i]);
    }

    return 0;
}