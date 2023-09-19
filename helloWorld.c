#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char sus;

    printf("wassup g: ");
    scanf("%c", &sus);

    sus = toupper(sus);

    printf("\nthis what you said: %c", sus);

    return 0;
}