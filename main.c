#include <stdio.h>
#include <stdbool.h>

void updateGameBoard(int move, int[] board, int bsize, int userNumber);


bool isMoveAllowed(int move, int[] board, int bsize);


void printBoard(int[] board, int bsize);


void printPrompt() {
	printf("Welcome to the Tic Tac Toe game!!!\n\
			\rWould you like to play with a computer or another player?\n\
			\rTo play with the computer type \"C\"\n\
			\rTo play with a partner type \"H\"\n"
		  ); // put in some funciton
}


void printPromtOX() {
	printf("Player ONE!!! Chose symbol! X or O?");
	//print large X and large O with numebrs pone and 2 unerneath
}

void getUserSymbol(char player, char other) {
	int choice
	scanf("%c", &choice);
	//check choice
	//mechanism to check if input is correct if letter is small use toUpper
	if (choice) 
		other = "X";
	else
		other == "O"
}



bool makeAImove(int[] board, int bsize);
bool isGameWon(i);

bool isAIplaying(char userChoice) {
	if (userChoice == 'c' || userChoice == 'C')
		return true;
	else
		return false;
}



int main()
{
	bool isAgainstAI; //flag that will be used to choose correct game mode
	char userChoice;
	char player1; player2;

	printPrompt();
	isAgainstAI = isAIplaying(userChoice);
	printPromtOX();
	getUserSymbol(player1);

	//save O or X
    //promt lets begin game
	//clear the screen

	printf("\n%c", userChoice);
	int counter = 0;
	int gameBoad[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};




		//__ PRINT THE BOARD

	while (1) {

		//   is counter even/odd

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
		break;
	}

	return 0;
}
