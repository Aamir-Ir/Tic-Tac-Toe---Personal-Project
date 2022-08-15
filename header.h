#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard();

void printBoard();

int checkFreeSpot();

void playerTurn();

void computerTurn();

char checkWin();

void printWinner(char winner);