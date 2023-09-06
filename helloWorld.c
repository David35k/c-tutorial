#include <stdio.h>
#include <stdbool.h>

int main()
{

    // const bool doILoveMen = true;

    // doILoveMen = false; // ha that gives an error you will forever love men

    float itemPrices[] = {5.75, 49.99, 99.99};
    char sussy[][100] = {"Bugatti", "Food XD", "Air (per cubic centimetre)"};

    size_t size = sizeof(itemPrices) / sizeof(itemPrices[0]);

    for (int i = 0; i < size; i++)
    {
        printf("%s: $%8.2f\n", sussy[i], itemPrices[i]);
    }

    // GRAHH TAX!!!! NO!!!!
    printf("NO TAX!!!! >:(\n");

    for (int i = 0; i < size; i++)
    {
        itemPrices[i] *= 5;
        printf("%s: $%8.2f\n", sussy[i], itemPrices[i]);
    }

    return 0;
}