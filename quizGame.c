#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char questions[][100] = {"1. What is the capital of Australia?",
                             "2. What is the capital of Turkey?",
                             "3. What is the capital of Japan?"};

    char options[][100] = {"A. Melbourne", "B. Sydney", "C. Canberra", "D. Perth",
                           "A. Istanbul", "B. Ankara", "C. Mersin", "D. Bursa",
                           "A. Toyko", "B. Kyoto", "C. Osaka", "D. Sendai"};

    char answers[3] = {'C', 'B', 'A'};
    int numOfQuestions = sizeof(questions) / sizeof(questions[0]);
    char guess;
    int score = 0;

    printf("CAPITAL CITIES QUIZ\n");

    for (int i = 0; i < numOfQuestions; i++)
    {
        printf("%s\n", questions[i]);

        for (int j = 0; j < 4; j++)
        {
            printf("%s | ", options[j + 4 * i]);
        }

        printf("\n\n");

        printf("guess :");
        scanf("%c", &guess);
        scanf("%c"); // clear \n character from input buffer
        // strcpy(guess, "\0");

        // guess = toupper(guess);

        if (guess == answers[i])
        {
            printf("correct!\n");
            score++;
        }
        else
        {
            printf("%c , %c", answers[i], guess);
            printf("wrong!\n");
        }
    }

    printf("Your score is %d/%d", score, sizeof(questions) / sizeof(questions[0]));
}