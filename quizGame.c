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

    // loop through the questions
    for (int i = 0; i < numOfQuestions; i++)
    {
        printf("%s\n", questions[i]);

        //print all of the answer choices
        for (int j = 0; j < 4; j++)
        {
            printf("%s | ", options[j + 4 * i]);
        }

        // get user input
        printf("\nyour guess: ");
        scanf(" %c", &guess);

        guess = toupper(guess);
        
        if(guess == answers[i]) {
            //if correct answer increase score
            score++;
            printf("CORRECT\n");
        } else {
            printf("WRONG\n");
        }

        printf("\n");
    }

    printf("Your score is %d/%d", score, sizeof(questions) / sizeof(questions[0]));
}