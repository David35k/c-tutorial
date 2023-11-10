#include <stdio.h>

int main()
{
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("&arr[0] = %p\n", &arr[0]);
    printf("&arr[1] = %p\n", &arr[1]); // this one is 12 bytes after arr[0], 12 bytes is 3 integers (3 x 4 bytes)

    printf("*arr = %p\n", *arr);
    printf("*(arr + 1) = %p\n", *(arr + 1));
    printf("**(arr + 1) = %d\n", **(arr + 1)); // this address is first element in arr[1] so it 4 when dereferenced

    printf("arr[1][2] = %d\n", arr[1][2]);
    printf("*(*(arr + 1) + 2) = %d\n", *(*(arr + 1) + 2)); // for 2D arrays: arr[i][j] = *(*(arr + i) + j)

    return 0;
}