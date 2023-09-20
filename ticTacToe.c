#include <stdio.h>
#include <time.h>

// number of rows and columns
#define SIZE 3

typedef char boardType[SIZE][SIZE];

void printBoard(boardType *);
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

    // create the board
    boardType board;
    boardType *pBoard = NULL;


    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = '.';
        }
    }

    pBoard = &board;

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
            char string[9];

            for (int i = 0; i < 9; i++)
            {
                string[i] = '-';
            }

            printf("\n%s\n", string);
        }
    }

    printf("\n\n");

    // printBoard(pBoard);

    // keep track of the current players turn
    int currentPlayer = 1;

    // while (checkWin(board) == 0)
    // {
    //     if (currentPlayer == 1)
    //     {
    //         playerMove(pBoard);
    //     }
    //     else
    //     {
    //         computerMove();
    //     }

    //     printBoard(board);
    // }

    return 0;
}

void printBoard(boardType *pBoard)
{
    // loop through the board
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (j == 0)
            {
                printf("%c", *pBoard[i][j]);
            }
            else
            {
                printf(" | %c", *pBoard[i][j]);
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
    // return 0 if no one won, 1 if player won, 2 for computer and 3 for tie
    return 0;
}

int checkFreeSpaces(char board[SIZE][SIZE])
{
}

void playerMove(char *pBoard)
{
    int x;
    int y;

    printf("\nx: ");
    scanf("%d", &x);
    printf("\ny: ");
    scanf("%d", &y);

    // *pBoard[y][x] = 'X';
}

void computerMove()
{
}