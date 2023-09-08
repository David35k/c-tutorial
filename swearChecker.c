#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checkSwear(char[], char[], int);

int main()
{
    char swears[9][10] = {"fuck", "shit", "dick", "bullshit", "ass", "bitch", "asshole", "cock", "cunt"};
    char sentence[100];
    int swearCount = 0;

    printf("Your sentence (max 100 characters): ");
    fgets(sentence, 100, stdin);

    // check for swear words
    for (int i = 0; i < sizeof(sentence); i++)
    {
        // loop through all the swears
        for (int j = 0; j < sizeof(swears) / sizeof(swears[0]); j++)
        {
            // if the letter match it could be a swear
            if (sentence[i] == swears[j][0])
            {
                if (checkSwear(sentence, swears[j], i))
                {
                    swearCount++;
                }
            }
        }
    }

    switch (swearCount)
    {
    case 0:
        printf("\nNice dude! You didn't swear in your sentence! - swear count: %d", swearCount);
        break;
    case 1:
        printf("\nEveryone lets a swear slip out now and then! - swear count: %d", swearCount);
        break;
    case 2:
        printf("\nEveryone lets a swear slip out now and then! - swear count: %d", swearCount);
        break;
    case 3:
        printf("\nHey man, keep it family friendly - swear count: %d", swearCount);
        break;
    case 4:
        printf("\nAlright dude, not cool, dont swear - swear count: %d", swearCount);
        break;
    default:
        printf("\nThat's wild dude, your sweared %d times", swearCount);
        break;
    }

    return 0;
}

bool checkSwear(char sentence[], char swear[], int index)
{

    int count = 0;

    for (int i = 0; i < strlen(swear); i++)
    {
        // if the letters dont match break out of the loop
        if (sentence[index + i] != swear[i])
        {
            break;
        }
        else if (sentence[index + i] == swear[i])
        {
            count++;
        }

        if (count == strlen(swear))
        {
            return true;
        }
    }

    return false;
}