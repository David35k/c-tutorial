#include <stdio.h>

int sumElements(int arr[], int size)
{
    // the array here is being passed by reference
    // this means that it isn't being copied over but instead a pointer to the original is created
    // this is why sizeof(arr) returns 8
    // this also means that you can edit elements in the original array
    // however, you have no way of getting the size of the array so size needs to be an argument too
    printf("sum elements - size of arr: %d, size of arr[0]: %d\n", sizeof(arr), sizeof(arr[0]));

    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}

void doubleElements(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] *= 2;
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("main - size of arr: %d, size of arr[0]: %d\n", sizeof(arr), sizeof(arr[0]));
    printf("sum: %d\n", sumElements(arr, size));
    doubleElements(arr, size);
    printf("doubled: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}