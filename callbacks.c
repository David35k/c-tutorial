#include <stdio.h>
#include <math.h>

// what if you wanted the same sort function to sort according to different conditions?

int absoluteComp(const int a, const int b)
{
    return abs(a) - abs(b);
}

int comp(const int a, const int b)
{
    return a - b;
}

void sort(int arr[], int length, int (*compare)(const int, const int)) // simple bubble sort
{
    int temp;

    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (compare(arr[j], arr[j + 1]) > 0)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {-10, 9, -8, 7, -6, 5, -4, 3, -2, 1};

    sort(arr, 10, absoluteComp); // now it takes a function pointer as an argument
                                 // this allows the same sort function to sort using different conditions
                                 // depending on the functuion that gets passed as the compare function

    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]); // holy shit for loops can be written in one line!!!!

    return 0;
}