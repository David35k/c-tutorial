#include <stdio.h>
#include <time.h>
#include <stdbool.h>

// number of rows and columns
#define SIZE 3

// create the board
char board[SIZE][SIZE];

// keep track of the current players turn
int currentPlayer = 1;

char winner;

void printBoard(char[SIZE][SIZE]);
int checkWin(char[SIZE][SIZE]);        // returns the player that won (1 or 2)
int checkFreeSpaces(char[SIZE][SIZE]); // returns amount of free spaces left
void playerMove();
void computerMove();

int main()
{
    if (SIZE < 2)
    {
        printf("dude, size cant be less than 2");
        return 1;
    }

    // assign starting values to the board
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }

    printf("\n######## TIC-TAC-TOE ########\n");
    printf("\n");

    printBoard(board);

    while (checkWin(board) == 0)
    {
        if (currentPlayer == 1)
        {
            playerMove();
        }
        else if (currentPlayer == 2)
        {
        }

        printBoard(board);
    }

    return 0;
}

void printBoard(char board[SIZE][SIZE])
{
    // loop through the board
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (j == 0)
            {
                printf("%c", board[i][j]);
            }
            else
            {
                printf(" | %c", board[i][j]);
            }
        }

        if (i != SIZE - 1)
        {
            char string[SIZE * 3];

            for (int i = 0; i < SIZE * 3; i++)
            {
                string[i] = '-';
            }

            printf("\n%s\n", string);
        }
    }
}

int checkWin(char board[SIZE][SIZE])
{

    // check for win horzontally and vertically
    for (int i = 0; i < SIZE; i++)
    {
        char checkHor[SIZE];
        char checkVert[SIZE];
        bool flag = false;
        for (int j = 0; j < SIZE; j++)
        {
            checkHor[j] = board[i][j];
            checkVert[j] = board[j][i];
        }

        for (int j = 1; j < SIZE; j++)
        {
            if (checkHor[j] != checkHor[j - 1] || checkHor[j] == ' ' || checkVert[j] != checkVert[j - 1])
            {
                flag = true;
            }
        }

        if (!flag)
        {
            winner = checkHor[0];
            printf("\nwinner is %c", winner);
            return winner == 'X' ? 1 : 2;
        }
    }

    return 0;
}

int checkFreeSpaces(char board[SIZE][SIZE])
{
}

void playerMove()
{
    printf("\nPlayer move: \n");

    int x;
    int y;

    printf("x: ");
    scanf("%d", &x);
    printf("y: ");
    scanf("%d", &y);

    board[y][x] = 'X';
    printf("\n");
}

void computerMove()
{
}