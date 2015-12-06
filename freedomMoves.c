/* Violet Pfeiffer, Adam Capar, Samuel Carey
 * Project 3
 * 25 November 2015
 * 
 */
#include "freedomMoves.h"
#include <ctype.h>
#include <string.h>

/*******************Functions********************/
/*Retrieves and returns the player's input*/
void getPlayerMove(char playerMove[]){

	/*Get user input*/
	fgets(playerMove, pmBUFFER, stdin);
	//printf("%c %c %c %c\n", playerMove[0], playerMove[1], playerMove[2],playerMove[3]);
	
	return;
}

/*convert user input to tile position*/
void convertPlayerMove(char playerMove[], int size, int *rowCoordinate, int *columnCoordinate){ //FIX ME: make more general
	long row; /*holds row converted to long*/
	char *ptr; /*useless null pointer. (for strtol())*/
	char str1[3]; /*for strtol()*/
	char str2[2]; /*for strtol()*/
	
	/*clear str1, str2*/
	memset(str1, '\0', 3);
	memset(str2, '\0', 2);
	
	/*column*/
	/*check if column is lowercase*/
	if(playerMove[0] >= 'a' && playerMove[0] <= 'z'){
		/*convert column to upper case*/
		playerMove[0] = toupper(playerMove[0]);
	}
	/*convert column from capital char to int*/
	if(playerMove[0] >= 'A' && playerMove[0] <= 'Z'){
		*columnCoordinate = playerMove[0] - 'A'; //<--offset necesary to convert to ints
	}
	/*user input for column is not an alphabetical char*/
	else{
		printf("Sorry, the column you enterred was incorrect. Please enter coordinates again.\n");
		getPlayerMove(playerMove);
	}
	
	/*row*/
	/*if row coordinate lower than 10*/
	if(playerMove[1] >= '1' && playerMove[1] <= '9'){
		if(playerMove[2] == '\0'){
			/*convert to long*/
			str2[0] = playerMove[1];
			row = strtol(str2, &ptr, 10);
			
			/*store to coordinate variable*/
			*rowCoordinate = row;
		}
		/*checks if second coordinate is 10 or greater*/
		if(playerMove[2] >= '0' && playerMove[2] <= '9'){
		/*convert to long*/
		str1[0] = playerMove[1];
		str1[1] = playerMove[2];
		row = strtol(str1, &ptr, 10);
		
		/*store to coordinate variable*/
		*rowCoordinate = row;
		}
	}
	/*user input for row is not a numerical char*/
	else{
		printf("Sorry, the column you enterred was incorrect. Please enter coordinates again.\n");
		getPlayerMove(playerMove);
	}

	return;
}

/*check if tile position is valid. Return 1 if true, 0 if false*/
int isValid(int turn, int freedom, char **board, int size, int previousRowCoordinate, int previousColumnCoordinate, int rowCoordinate, int columnCoordinate){ //FIX ME: make more general
	
	/*if playerMove is within bounds of board*/
	if(rowCoordinate >= 0 && rowCoordinate <= size){
		if(columnCoordinate >= 0 && columnCoordinate <= columnCoordinate){
			/*if its turn 0*/
			if(turn == 0){
				return 1;
			}
			/*if tile is empty*/
			if(board[rowCoordinate][columnCoordinate] == ' '){
				/*if freedom mechanic is true. (all adjacent tiles are filled)*/
				if(freedom == 1){ //FIX ME: may have to check this my self
					return 1;
				} 
				/*if the position is adjacent to last move OR all adjacent tiles are filled*/
				/*call to adjacentTiles()*/
				if(adjacentTiles(previousRowCoordinate, previousColumnCoordinate, rowCoordinate, columnCoordinate) == 1){
					return 1;
				}
			}
			
		}
	}
	//if tile is empty
	
	//if the position is adjacent to last move OR all adjacent tiles are filled
	
	/*if both elements of playerMove are NOT valid return 0*/
	return 0;
}
/*check adjacent tiles of previous move. Return 1 if true, 0 if false*/
int adjacentTiles(int previousRowCoordinate, int previousColumnCoordinate, int rowCoordinate, int columnCoordinate){
	/*column -1*/
	if(previousColumnCoordinate - 1 == columnCoordinate){
		/*row == row*/
		if(previousRowCoordinate == rowCoordinate){
			return 1;
		}
		/*row + 1*/
		if(previousRowCoordinate + 1 == rowCoordinate){
			return 1;
		}
		/*row - 1*/
		if(previousRowCoordinate - 1 == rowCoordinate){
			return 1;
		}
		return 0;
	}
	
	/*row -1*/
	if(previousRowCoordinate - 1 == rowCoordinate){
		/*column == column*/ 
		if(previousColumnCoordinate == columnCoordinate){
			return 1;
		}
		/*column + 1*/
		if(previousColumnCoordinate + 1 == columnCoordinate){
			return 1;
		}
		return 0;
	}
	
	/*column + 1*/
	if(previousColumnCoordinate + 1 == columnCoordinate){
		/*row == row*/
		if(previousRowCoordinate == rowCoordinate){
			return 1;
		}
		
		/*row + 1*/
		if(previousRowCoordinate + 1 == rowCoordinate){
			return 1;
		}
		return 0;
	}
	
	/*row + 1*/
	if(previousRowCoordinate + 1 == rowCoordinate){
		
		/*column == column*/
		if(previousColumnCoordinate == columnCoordinate){
			return 1;
		}
		return 0;
	}

}
/*place piece on tile position*/
void implementPlayerMove(int player, int coordinates[], char **board){
	
	/*check if player1 (white)*/
	if(player == 1){
		/*place white piece*/
		board[coordinates[0]][coordinates[1]] = 'W';
	}
	/*check if player2 (black)*/
	else if(player == 2){
		/*place black piece*/
		board[coordinates[0]][coordinates[1]] = 'B';
	}
	printf("%c\n", board[coordinates[0]][coordinates[1]]);
	return;
}