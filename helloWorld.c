#include <stdio.h>

int findMax(int x, int y)
{
    return (x > y) ? x : y;
}

int main()
{
    // ternary operator is shortcut for if statement when assigning or returning a value
    // (condition) ? value if true : value if false

    int max = findMax(10, 4);

    printf("%d", max);

    return 0;
}