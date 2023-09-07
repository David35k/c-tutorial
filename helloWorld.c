#include <stdio.h>
#include <string.h>

int main()
{
    // contrinue = skips rest of code and forces the next iteration fo the loop
    // break = exits a loop/switch

    //count to 20 but skip 13
    for (int i = 1; i <= 20; i++)
    {
        if(i == 13) {
            continue;
        }
        printf("%d\n", i);
    }
    return 0;
}