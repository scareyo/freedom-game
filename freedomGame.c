/* Violet Pfeiffer, Adam Capar, Samuel Carey
 * Project 3
 * 25 November 2015
 * Freedom Game. An "n-in-a-row" board game.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freedomMoves.h"
#include "freedomScoring.h"

#define MAX_BUF 1024
#define MIN_SIZE 10
#define MAX_SIZE 26

void clearBoard(char **board, int size);
void printBoard(char **board, int size);
char** allocateBoard(int size);
void freeBoard(char **board, int size);
int getSize();

int main() {
    char **board;
    int size = getSize();
    int coordinates[cBUFFER]; /*holds converted coordinates (row, column) of playerMove*/
    int turn = 0; /*what turn game is currently at*/
	int valid = 0; /*if move is valid*/
	int player = 1; /*which player*/
	
    board = allocateBoard(size);
    clearBoard(board, size);
    printBoard(board, size);
    
    //player 1 enter move
    printf("Welcome to Freedom! White goes first! Please choose a space.\n");
    getPlayerMove(playerMove);
    
    /*call convertPlayerMove*/
    //Check validity of move
    /*call isValid*/
    //Make move
    /*call implementPlayerMove*/
    //switch player
    while(1){
        //next player enter move
        //Check validity of move
        //Make move
        if(/*moves == size*size*/){
            //Calculate score
            //End game
        }else{
            //switch player
        }
    }
    return 0;
}

//Gets board size from user
int getSize(){
    char buffer[MAX_BUF];
    int size = 0;
    printf("Please enter the size of the board:\n");
    while(1){
        fgets(buffer, MAX_BUF-1, stdin);
        buffer[strlen(buffer)-1] = '\0';
        size = atoi(buffer);
        if(size < MIN_SIZE || size > MAX_SIZE){
            printf("\"%s\" is not a valid board size, try again:\n", buffer);
            continue;
        }
        return size;
    }
}

char **allocateBoard(int size){
    int i;
    char **board = NULL;
    board = malloc(sizeof(char*)*size);
    if(board == NULL){
        fprintf(stderr, "Could not allocate %d bytes:", sizeof(char*)*size);
        perror("");
        exit(EXIT_FAILURE);
    }
    for(i = 0; i < size; i++){
        *(board+i) = malloc(sizeof(char));
        if(*(board+i) == NULL){
            fprintf(stderr, "Could not allocate %d bytes:", sizeof(char)*size);
            perror("");
            exit(EXIT_FAILURE);
        }
    }
    return board;
}

void freeBoard(char **board, int size){
    int i;
    for(i = 0; i < size; i++)
        free(*(board+i));
    free(board);
}

void clearBoard(char **board, int size) {
    int i = 0;
    int j = 0;
    
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            board[i][j] = ' ';
}

// Function prints the board.
void printBoard(char **board, int size) {
    int i, j;
    int digits = 0;
    int spaces = 1;
    int n;
    
    n = size;
    while(n != 0){
        n/=10;
        spaces++;
    }
    //Print first line
    printf("%*s", spaces, " ");
    for(i = 0; i < size; i++)
        printf("%c ", 'A'+i);
    printf("\n");
    //Print rows
    for(i = size-1; i >= 0; i--){
        n = i;
        digits = 0;
        if(n == 0)
            digits = 1;
        else
            while(n != 0){
                n/=10;
                digits++;
            }
        printf("%d%*s", i, spaces-digits, " ");
        for(j = 0; j < size; j++){
            printf("%c ", board[j][i]);
        }
        printf("\n");
    }
}
