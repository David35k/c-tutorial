#include <stdio.h>

int main()
{
    int num;
    printf("wsg gang, how big you want the array?\n");
    scanf("%d", &num);

    int arr[num]; // why no give me warning!?!?!? sus

    for (int i = 0; i < num; i++)
    {
        arr[i] = i;
    }

    for (int i = 0; i < num; i++)
    {
        printf(" %d ", arr[i]);
    }

    return 0;
}