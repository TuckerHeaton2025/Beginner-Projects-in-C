#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

char board[3][3];

// I challenge you to modify this file so that the user can choose wether they are X or O
const char PLAYER = 'X';
const char COMP = 'O';
//COMP = Computer

void clear_board();
void display_board();
int check_empty_spaces();
void players_turn();
void comps_turn();
char check_winner();
void display_winner(char winner);


int main()
{
    //Tic Tac toe program!  

    printf("Tic Tac Toe in C!\n");

    char play_again = '\0';
    int games = 0;
    int player_score = 0;
    int computer_score = 0;

    do{
        
        char winner = ' ';
        int turns = 0; 
        clear_board();

        while(true)
        {
            // The player always goes first. Could you make it random?
            display_board();
            players_turn();
            turns ++;
            // Not possible to win in under 5 turns no point in checking
            if(turns >= 5)
            {
                winner = check_winner();
            }
            if(winner != ' ' || check_empty_spaces() == 0)
            {
                break;
            }
            
            //Computers turn 👇
            comps_turn();
            turns ++;
            if(turns >= 5)
            {
                winner = check_winner();
            }
            if(winner != ' ' || check_empty_spaces() == 0)
            {
                break;
            }
        
        }

        display_board();
        display_winner(winner);

        printf("Would you like to play again (Y/N): "); scanf(" %c", &play_again);

        switch(winner)
        {
            case 'X':
                player_score++;
                break;
            case 'O':
                computer_score++;
        }

        games += 1;

    }while(tolower(play_again) != 'n');

     printf("\nThank you for playing!\n\n");
    
    if(games > 1)
    {
        printf("Games played: %d\n", games);
        printf("Your score: %d\n", player_score);
        printf("Computer's score: %d\n", computer_score);
    }
    
    return 0;
}


void clear_board()
{
    // Change all spots in the grid to ' '
    for(int row = 0; row < 3; row++)
    {
        for(int column = 0; column < 3; column++)
        {
            board[row][column] = ' ';
        }
    }
}

void display_board()
{
    printf("\n%c | %c | %c", board[0][0], board[0][1], board[0][2]);
    printf("\n--|---|--\n");
    printf("%c | %c | %c", board[1][0], board[1][1], board[1][2]);
    printf("\n--|---|--\n");
    printf("%c | %c | %c\n\n", board[2][0], board[2][1], board[2][2]);
}

int check_empty_spaces()
{
    int free_spaces = 0;
    for(int row = 0; row < 3; row++)
    {
        for(int column = 0; column < 3; column++)
        {
            /* 
            * increment free_spaces based on the number 
            * of ' ' (blank spaces) found 👇
            */
            if(board[row][column] == ' ')
            {
                free_spaces++;
            }

        }
    }

    return free_spaces;
}
    
void players_turn()
{
    int row = 0;
    int col = 0;

    // Its easier to understand 1-3 than 0-2
    printf("Enter a row (1-3): "); scanf("%d", &row);
    printf("Enter a column (1-3): "); scanf("%d", &col);
    
    while(true)
    {    
        if(row < 1 || col < 1 || row > 3 || col > 3)
        {
            printf("\nPick a number 1-3\n");
        }
        else if(board[row-1][col-1] != ' ')
        {
            printf("\nSpot Taken\n");
        }
        else
        {
            break;
        }
        printf("Enter a row (1-3): "); scanf("%d", &row);
        printf("Enter a column (1-3): "); scanf("%d", &col);
    }
    
    board[row-1][col-1] = PLAYER;
}

void comps_turn()
{
    int row = 0;
    int col = 0;
    srand(time(0));

    do{ 
        // The modulus operator limits the rand 
        // (random) output from going over 3
        row = rand() % 3;
        col = rand() % 3;
    }
    while(board[row][col] != ' ');
    // We check to make sure the space is empty
    
    board[row][col] = COMP;
    
}

char check_winner()
{

    /* 
    * We have to make sure were not returning a blank char ' ' 
    * until the endas returning one before the end could stop 
    * us from finding a possible winner. (return statements stop a function)
    */

    for(int row = 0; row < 3; row ++)
    {
        if(board[row][0] != ' ' && board[row][0] == board[row][1] && board[row][0] == board[row][2])
        {
            return board[row][0]; 
        }
    }
    
    for(int col = 0; col < 3; col ++)
    {
        if(board[0][col] != ' ' && board[0][col] == board[1][col] && board[0][col] == board[2][col])
        { 
            return board[0][col];
        }
    }

    /*
    * After iterating through both 
    * loops if there still isn't 
    * a winner keep checking more conditions
    */

    // Check diagonals 👇
    
    if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    else if(board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }

    // As possible conditons have been checked return ' '

    return ' ';
}

void display_winner(char winner)
{
    switch(winner)
    {
        case ' ':
            printf("TIE GAME!\n");
            break;
        case 'O':
            printf("COMPUTER WON!\n");
            break;
        case 'X':
            printf("YOU WON\n");
            break;
        default:
            printf("display_winner ERROR\n");

    }

}
