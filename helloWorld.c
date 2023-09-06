#include <stdio.h>
#include <string.h>

int main()
{
    // user input!!!!!!

    int age;
    char name[25]; // bytes

    printf("\nWhats good homie, whats your name?");
    // scanf("%s", &name);         //scanf reads until whitespace
    fgets(name, 25, stdin);        // can read the whitespace
    name[strlen(name) - 1] = '\0'; // gets rid of the newline character

    printf("How old are you %s?", name);
    scanf("%d", &age);

    printf("%s, you are %d years old\n", name, age);

    return 0;
}