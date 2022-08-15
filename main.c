#include "header.h"

int main(int argc, char * argv[])  {
   char winner = ' ';
   char response = ' ';


    // Run the program until the user quits when asked.
    
    do  {
        winner = ' ';           // Reset Winner to continue without errors.
        response = ' ';         // Reset Response to continue without errors.
        resetBoard();           // Reser Board to continue without errors.
 
        // Run the game until there is a winner or there are no playable spots.

        while((winner == ' ') && (checkFreeSpot() != 0))    {
            printBoard();           // Print the board. 

            playerTurn();           // Ask player to play
            winner = checkWin();    // Check if there is a winner.
            
            // If player won break the nested while loop. 

            if(winner != ' ' || checkFreeSpot() == 0)  {
                break;
            }

            computerTurn();         // Computer plays.
            winner = checkWin();    // Check if there is a winner.
            
            // If computer won break the nested while loop.

            if(winner != ' ' || checkFreeSpot() == 0)   {
                break;
            }
        }

    // Print the final board + Winner.

    printBoard();
    printWinner(winner);

    // User asked if they will play again.

    printf("\nWould you like to play again? (Y/N): ");
    scanf("%c", &response);
    scanf("%c", &response);
    response = toupper(response);
    } while (response == 'Y');

   printf("\nThanks for playing!");

   return 0;
}

// Function used to create a empty board intially and if the user decides to play again creates an empty game board.

void resetBoard()   {

    for(int i = 0; i < 3; i++)   {
        for(int j = 0; j < 3; j++)      {
            board[i][j] = ' ';
        }
    }   
}

// Function used to create a empty board intially and if the user decides to play again creates an empty game board.

void printBoard()   {
    int i, j;

    // Print the board

    printf("\n     Col 1 Col 2 Col 3\n");

    for (i = 0; i < 3; i++) {
        printf("Row %d ", i + 1);
        for (j = 0; j < 3; j++) {

            // Case 1: Print the columns normally with a boarder util the last one.

            if (j != 2) {
                printf(" %c   |", board[i][j]);
            }

            // Case 2: Print the last columnn without a boarder.
            
            else    {
                printf(" %c ", board[i][j]);
            }
        }

        // Case 1: Create a boarder sepearating the rows. 

        if (i != 2) {
            printf("\n      -----|-----|-----\n");
        }

        // Case 2: Do not create a boarder with the last row just a newline.

        else    {
            printf("\n");
        }
    }
}

// This functions returns the number of spaces left in the game to see if there is a tie or not.

int checkFreeSpot() {
    int freeSpaces = 9;

    for(int i = 0; i < 3; i++)  {
        for(int j = 0; j < 3; j++)  {
            if(board[i][j] != ' ')  {
                freeSpaces--;
            }
        }
    }

   return freeSpaces;
}

// This function is used to conduct the players turn.

void playerTurn()   {
    int x;
    int y;

    // Run until correct input is given.

    do   {
        printf("Enter row #(1-3): ");
        scanf("%d", &x);
        x--;
        printf("Enter column #(1-3): ");
        scanf("%d", &y);
        y--;

        // Case 1: Invalid move.

        if(board[x][y] != ' ')  {
            printf("Invalid move!\n");
        }

        // Case 2: Place the players piece.

        else    {
            board[x][y] = PLAYER;
            break;
        }
} while (board[x][y] != ' ');
   
}

// This function is used to conduct the computers turn.

void computerTurn() {
    srand(time(0));     //creates a seed based on current time
    int x;
    int y;
    
    // Case 1: There is space to make the move.

    if(checkFreeSpot() > 0) {
        do  {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');
        board[x][y] = COMPUTER;
    }

    // No more space to make a move.

    else {
        printWinner(' ');
    }
}

char checkWin() {
   
    // Win seneraio 1: check rows
   
    for(int i = 0; i < 3; i++)   {
        if((board[i][0] == board[i][1]) && (board[i][0] == board[i][2]))    {
            return board[i][0];
        }
    }

    // Win seneraio 2: check columns
   
    for(int i = 0; i < 3; i++)   {
        if((board[0][i] == board[1][i]) && (board[0][i] == board[2][i]))    {
            return board[0][i];
        }
    }

    // Win seneraio 3: check diagonals
   
    if((board[0][0] == board[1][1]) && (board[0][0] == board[2][2]))    {
        return board[0][0];
    }

    if((board[0][2] == board[1][1]) && (board[0][2] == board[2][0]))    {
        return board[0][2];
    }

    return ' ';
}

// This function returns the winner.

void printWinner(char winner)   {

    // Case 1: Player wins.

    if(winner == PLAYER)    {
        printf("YOU WIN!");
    }

    // Case 2: Bot Wins.

    else if(winner == COMPUTER) {
        printf("YOU LOSE!");
    }

    // Case 3: Tie

    else    {
        printf("IT'S A TIE!");
    }
}