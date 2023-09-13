#include <stdio.h>
#include <ctype.h>

int main()
{
    char questions[][100] = { "1. What is the capital of Australia?",
                              "2. What is the capital of Turkey?",
                              "3. What is the capital of Japan?" };

    char options[][100] = {"A. Melbourne", "B. Sydney", "C. Canberra", "D. Perth",
                           "A. Istanbul", "B. Ankara", "C. Mersin", "D. Bursa",
                           "A. Toyko", "B. Kyoto", "C. Osaka", "D. Sendai"};

    
    char answers[3] = {'C', 'B', 'A'};
    int numOfQuestions = sizeof(questions)/sizeof(questions[0]);
    char guess;
    int score;

    printf("CAPITAL CITIES QUIZ\n");
    
    for (int i = 0; i < numOfQuestions; i++)
    {
        printf("%s\n", questions[i]);

        
        
    }
    

}