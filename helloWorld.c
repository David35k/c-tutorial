#include <stdio.h>
#include <string.h>

struct Player
{
    char name[12];
    int score;
};

int main()
{
    // structs

    struct Player player1;
    struct Player player2;

    // using strcpy cos strings

    strcpy(player1.name, "david");
    player1.score = 69;
    
    strcpy(player2.name, "bro");
    player2.score = 1;

    printf("name: %s, score: %d\n", player1.name, player1.score);
    printf("name: %s, score: %d\n", player2.name, player2.score);

    return 0;
}