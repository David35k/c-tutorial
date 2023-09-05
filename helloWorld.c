#include <stdio.h>
#include <stdbool.h>

int main()
{
    float itemPrices[] = {5.75, 49.99, 99.99};

    size_t size = sizeof(itemPrices) / sizeof(itemPrices[0]);

    for (int i = 0; i < size; i++)
    {
        printf("Item %d: %8.2f\n", i + 1, itemPrices[i]);
    }

    return 0;
}