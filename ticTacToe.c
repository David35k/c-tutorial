#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// number of rows and columns
#define SIZE 3

// create the board
char board[SIZE][SIZE];

// keep track of the current players turn
int currentPlayer = 1;

char winner;

void printBoard();
int checkWin();        // returns the player that won (1 or 2)
int checkFreeSpaces(); // returns amount of free spaces left
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

    printBoard();

    while (checkWin() == 0)
    {
        if (currentPlayer == 1)
        {
            playerMove();
            currentPlayer = 2;
        }
        else if (currentPlayer == 2)
        {
            computerMove();
            currentPlayer = 1;
        }

        printBoard();
    }

    return 0;
}

void printBoard()
{
    // loop through the board
    for (int i = 0; i < SIZE; i++)
    {

        for (int j = 0; j < SIZE; j++)
        {
            if (j == 0)
            {
                printf(" %c ", board[i][j]);
            }
            else
            {
                printf("| %c ", board[i][j]);
            }
        }

        if (i != SIZE - 1)
        {
            int charsNum = 4 * (SIZE - 1);
            char str[100] = "---";
            char ch = '-';

            if (strlen(str) + charsNum >= sizeof(str))
            {
                printf("bruh not enough memory eks dee");
            }
            else
            {
                int ogLength = strlen(str);
                for (int j = 0; j < charsNum; j++)
                {
                    str[ogLength + j] = ch;
                }

                str[ogLength + charsNum] = '\0';
                printf("\n%s\n", str);
            }
        }
    }

    printf("\n");
}

int checkWin()
{
    // check for win horizontally and vertically
    for (int i = 0; i < SIZE; i++)
    {
        char checkHor[SIZE];
        char checkVert[SIZE];
        bool flagHor = false;
        bool flagVert = false;
        for (int j = 0; j < SIZE; j++)
        {
            checkHor[j] = board[i][j];
            checkVert[j] = board[j][i];
        }

        for (int j = 1; j < SIZE; j++)
        {
            if (checkHor[j] != checkHor[j - 1] || checkHor[j] == ' ')
            {
                flagHor = true;
            }

            if (checkVert[j] != checkVert[j - 1] || checkVert[j] == ' ')
            {
                flagVert = true;
            }
        }

        if (!flagHor || !flagVert)
        {
            winner = !flagHor ? checkHor[0] : checkVert[0];
            printf("\nThe winner is %c!!", winner);
            return winner == 'X' ? 1 : 2;
        }
    }

    // check for win diagonally
    bool flagRight = false;
    bool flagLeft = false;

    for (int i = 1; i < SIZE; i++)
    {
        if (board[i][i] != board[i - 1][i - 1] || board[i][i] == ' ')
        {
            flagRight = true;
        }

        if (board[i][SIZE - i - 1] != board[i - 1][SIZE - i] || board[i][SIZE - i - 1] == ' ')
        {
            flagLeft = true;
        }
    }

    if (!flagRight || !flagLeft)
    {
        winner = !flagRight ? board[0][0] : board[0][SIZE - 1];
        printf("\nThe winner is %c!!\n", winner);
        return winner == 'X' ? 1 : 2;
    }

    if(checkFreeSpaces() == 0) {
        printf("\nIt's a tie! you suck lol");
        return 3;
    }

    return 0;
}

int checkFreeSpaces()
{
    int count = 0;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == ' ')
            {
                count++;
            }
        }
    }

    return count;
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

    // Makes sure to only go in empty spaces
    while (board[y][x] != ' ')
    {
        printf("can't go there!\n");
        printf("x: ");
        scanf("%d", &x);
        printf("y: ");
        scanf("%d", &y);
    }

    board[y][x] = 'X';
    printf("\n");
}

void computerMove()
{
    srand(time(0)); // set random seed to current time

    printf("\nComputer move: ");

    int x = rand() % SIZE;
    int y = rand() % SIZE;

    // Makes sure to only go in empty spaces
    while (board[y][x] != ' ')
    {
        x = rand() % SIZE;
        y = rand() % SIZE;
    }

    board[y][x] = 'O';

    printf("(%d, %d)\n", x, y);
}