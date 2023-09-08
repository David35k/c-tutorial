#include <stdio.h>
#include <string.h>

int main()
{
    char swears[][6] = {"fuck", "shit", "faggot"};
    char sentence[50];
    char words[25][50];
    int wordCount = 0;

    printf("Your sentence (max 50 characters): ");
    scanf("%s", &sentence);

    // check if swear word

    // printf("%d", sizeof(sentence));
    for (int i = 0; i < sizeof(sentence); i++)
    {
        // printf("%d", i);
        // printf("%c", sentence[i]);
        if(sentence[i] == ' ' && sentence[i+1] == ' ') {
            break;
        } else if (sentence[i] == ' ') {
            
        }
    }

    return 0;
}