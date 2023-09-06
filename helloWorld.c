#include <stdio.h>
#include <math.h>

int main()
{
    char grade;

    printf("gimme letter grade ninja!");
    scanf("%c", &grade);

    switch(grade) {
        case 'A':
            printf("Nice ninja good grade!!");
            break;
    }

    return 0;
}