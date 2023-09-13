#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    // set the random seed to be current time
    srand(time(0));
    
    const int MIN = 1;
    const int MAX = 100;

    int guess;
    int guessCount = 0;
    int number = rand() % MAX + MIN;

    printf("i have come up with a number between 1 and 100, try guess it\n");

    do
    {
        printf("\nguess: ");
        scanf("%d", &guess);

        guessCount++;

        if (guess < number)
        {
            printf("\ntoo low");
        }
        else if (guess > number)
        {
            printf("\ntoo high");
        }
        else
        {
            printf("\ncorrect!");
        }
    } while (guess != number);

    printf("\nthe number was %d", number);
    printf("\nGuesses: %d", guessCount);

    return 0;
}