/***************************
Author: Govind Shukla
Purpose: Tic - Toc - Toe Game
Date: 16-08-2021
**************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>  /// For Color Window

/// Global variables
char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int choice, player;

/// Function Declarations
int checkForWin();
void displayBoard();
void markBoard(char mark);


///<===================Driver Code=========================>
int main()
{
    // For Background terminal color change
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);

    // For Foreground(text) color change in terminal
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);

    int gameStatus;

    char mark;

    player = 1;

    do
    {
        displayBoard();

        /// Change turns
        player = (player % 2) ? 1 : 2;

        /// Get Input
        printf("\t\nPlayer %d, Enter a number: ", player);
        scanf("%d", &choice);

        /// Set the correct player based on player turn
        mark = (player == 1) ? 'x' : 'Y';

        /// Set board based on user choice or invalid move
        markBoard(mark);

        gameStatus = checkForWin();

        player++;

    }while(gameStatus == -1);

    if(gameStatus == 1)
        printf("==> Player %d, won..!!\n", --player);

    else
        printf("==> Game draw..!!\n\n");

    return 0;
}


/*********************************
Function to return to game status
1 For game is over with result
-1 For game is still in progress
0 For game is over and no result
************************************/

int checkForWin()
{
    int returnValue;

    if (square[1] == square[2] && square[2] == square[3])
        returnValue = 1;

    else if(square[4] == square[5] && square[5] == square[6])
        returnValue = 1;

    else if(square[7] == square[8] && square[8] == square[9])
        returnValue = 1;

    else if(square[1] == square[4] && square[4] == square[7])
        returnValue = 1;

    else if(square[2] == square[5] && square[5] == square[8])
        returnValue = 1;

    else if(square[3] == square[6] && square[6] == square[9])
        returnValue = 1;

    else if(square[1] == square[5] && square[5] == square[9])
        returnValue = 1;

    else if(square[3] == square[5] && square[5] == square[7])
        returnValue = 1;

    else if(square[1] != '1' && square[2] != '2' && square[3] != '3' &&
            square[4] != '4' && square[5] != '5' && square[6] != '6' &&
            square[7] != '7' && square[8] != '8' && square[9] != '9' )
        returnValue = 0;

    else
        returnValue = -1;

    return returnValue;
}

/****************************************
Function to draw board of Tic - Toc - Toe
*****************************************/
void displayBoard()
{
    system("cls");

    /// Code for text color change in Terminal
    //HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // h is variable

    // For foreground(text)
    //SetConsoleTextAttribute(h, FOREGROUND_GREEN);

    // For background
    //SetConsoleTextAttribute(h, BACKGROUND_INTENSITY);


    /// Actual Code start
    printf("\n\n\t Tic - Tac - Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (Y)\n\n\n");


    printf("\t     |     |     \n");
    printf("\t  %c  |   %c |  %c \n", square[1], square[2], square[3]);

    printf("\t_____|_____|______\n");
    printf("\t     |     |      \n");

    printf("\t  %c  |   %c |  %c \n", square[4], square[5], square[6]);

    printf("\t_____|_____|______\n");
    printf("\t     |     |      \n");

    printf("\t  %c  |   %c |  %c \n", square[7], square[8], square[9]);

    printf("\t     |     |     \n");
}

/****************************************
Set the board with the correct character
x or o on the correct spot in the array
****************************************/

void markBoard(char mark)
{

    if (choice == 1 && square[1] == '1')
        square[1] = mark;

    else if(choice == 2 && square[2] == '2')
        square[2] = mark;

    else if(choice == 3 && square[3] == '3')
        square[3] = mark;

    else if(choice == 4 && square[4] == '4')
        square[4] = mark;

    else if(choice == 5 && square[5] == '5')
        square[5] = mark;

    else if(choice == 6 && square[6] == '6')
        square[6] = mark;

    else if(choice == 7 && square[7] == '7')
        square[7] = mark;

    else if(choice == 8 && square[8] == '8')
        square[8] = mark;

    else if(choice == 9 && square[9] == '9')
        square[9] = mark;

    else
    {
        printf("\tInvalid Move..");

        player--;

        getch();
    }


}

