//basic bubble sort of array of integers

#include <stdio.h>

void sort(int[], int);

int main()
{
    int array[] = {9, 5, 3, 6, 10, 69, 2, 1, 4, 8, 7};
    int size = sizeof(array) / sizeof(array[0]);

    printf("size: %d\n", size);

    sort(array, size);

    return 0;
}

void sort(int array[], int size)
{
    int temp;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }

            for (int i = 0; i < size; i++)
            {
                printf("%d ", array[i]);
            }
            printf("\n");
        }
    }
}