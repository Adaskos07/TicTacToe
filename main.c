#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define CIRCLE 0
#define CROSS 1


void printPromptAI() {
	printf("Welcome to the Tic Tac Toe game!!!\n\
			\rWould you like to play with a computer or another player?\n"
		  ); // add large sign with AI or another player, 
	         // choice use with a number subtracted by 1
}


bool isAIplaying() {
	int userChoice;
	scanf("%d", &userChoice);
	--userChoice;
	if (!userChoice) // choice has to be deacreased by one 
		return true; // first option is AI !(1 - 1 = 0) = true
	else
		return false; // any number larger than 1 will be play with parter
}


void printPromtOX() {
	printf("Player ONE!!! Chose symbol! X or O?");
	//print large X and large O with numbers 1 and 2 unerneath
}


void getUserSymbol(int *player, int  *other) {
	int choice;
	scanf("%d", &choice);
	--choice;
	//check choice
	if (choice) {
		*player = CIRCLE;
		*other = CROSS;
	}
	else {
		*player = CROSS;
		*other = CIRCLE;
	}
}


void updateGameBoard(int move, int board[], int bsize) {
}


bool isMoveAllowed(int move, int board[], int bsize) {
}


void printBoard(int board[], int bsize);


void makeAImove(int board[], int bsize) {
	int move = rand() % 9;

	while (!isMoveAllowed(move, board, bsize))
		move = rand() % 9;

	updateGameBoard(move, board, bsize);
}


bool isGameWon(int board[]) {
	// 012 345 678 horizontal lines
	// 036 147 258 vertical lines 
	// 048 246     diagonals
	// ignore zeroes! emptyy element
	return false;
}

/*
X    X         OO
 X  X         O  O
  XX         O    O
 X  X         O  O
X    X         OO
*/

int main()
{
	srand(time(NULL));
	bool isAgainstAI; //flag that will be used to choose correct game mode
	int player1, player2;

	int gameBoad[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	bool counterEven;

	printPromptAI();
	isAgainstAI = isAIplaying();

	printPromtOX();
	getUserSymbol(&player1, &player2);

	//save O or X
    //promt lets begin game
	//clear the screen

	
	int counter = 0;
	while (1) {

		counterEven = counter % 2 ? true : false;

		if (isGameWon(gameBoad)) {
			// congrats and result prompt
			break; //quit
		}
		break;

			 

		//   check is the game is won,remember the counter
		//   promt user 1 or 2 depending in the counter
		//   take  input
		//   check if move is correct if not move back two steps
		//   change the internal board represented by array
		//    clear the screen
		//    print the noew updated board


		//   is counter even/odd 
		//   check is the game is won,
		//   promt user 1
		//   take  input
		//   check if move is correct if not move back two steps
		//   AI makes move
		//   check if AI is correct
		//   change the internal board represented by array
		//    clear the screen
		//    print the noew updated board

		//user input
		//clear screen
		//data processing
		//terminal output
		++counter;
		
	}

	return 0;
}
