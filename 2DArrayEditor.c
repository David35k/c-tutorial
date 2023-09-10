#include <stdio.h>

int main()
{
    int arr[3][3] = {{1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9}}; // 2d array

    int rows = sizeof(arr) / sizeof(arr[0]);
    int cols = sizeof(arr[0]) / sizeof(arr[0][0]);

    int x;
    int y;

    do
    {
        int num;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }

        printf("Input coordinates(x,y): \n");
        scanf("%d,%d", &x, &y);
        printf("Input new number: ");
        scanf("%d", &num);

        arr[y][x] = num;

    } while (x != 69 && y != 69);

    return 0;
}