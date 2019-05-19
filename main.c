#include <stdio.h>
#include <stdbool.h>


void printPromptAI() {
	printf("Welcome to the Tic Tac Toe game!!!\n\
			\rWould you like to play with a computer or another player?\n"
		  ); // add large sign with AI or another player, choice use with a number subtracted by 1
}


bool isAIplaying(int userChoice) {
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


void getUserSymbol(char player, char other) {
	int choice
	scanf("%c", &choice);
	--choice;
	//check choice
	//mechanism to check if input is correct if letter is small use toUpper
	if (choice) 
		player = "X";
		other == "O";
	else
		player = "O";
		other == "X";
}


void updateGameBoard(int move, int[] board, int bsize, int userNumber);


bool isMoveAllowed(int move, int[] board, int bsize);


void printBoard(int[] board, int bsize);


bool makeAImove(int[] board, int bsize);


bool isGameWon(int[] board) {
	// 012 345 678 horizontal lines
	// 036 147 258 vertical lines 
	// 048 246     diagonals
	// ignore zeroes! emptyy element
}




int main()
{
	bool isAgainstAI; //flag that will be used to choose correct game mode
	char player1; player2;

	printPromptAI();
	isAgainstAI = isAIplaying(userChoice);

	printPromtOX();
	getUserSymbol(player1, player2);

	//save O or X
    //promt lets begin game
	//clear the screen

	printf("\n%c", userChoice);
	int counter = 0;
	
	int gameBoad[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	bool isCounterEven;




		// PRINT THE BOARD

	while (1) {

		//   is counter even/odd
		isCounterEven = counter % 2 ? true : false;

		

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
