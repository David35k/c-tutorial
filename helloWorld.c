#include <stdio.h>

int main()
{
    char sus[] = "wassup"; // string gets stored in the space for array
    char *str = "wassup"; // string gets stored as compile time constant

    printf("%s\n", str); 
    str[2] = 'W'; // since it is a compile time constant it can't be modified at runtime
    printf("%s\n", str);

    return 0;
}   