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
	printf("Player ONE!!! Chose symbol! X or O?\n");
	//print large X and large O with numbers 1 and 2 unerneath
}


void getUserSymbol(int *player, int  *other) {
	int choice;
	scanf("%d", &choice);
	--choice;
	//check choice
	if (!choice) {
		*player = CROSS;
		*other = CIRCLE;
	}
	else {
		*player = CIRCLE;
		*other = CROSS;
	}
}


void printGameBagin() {
	//lets begin game message
	// clear the screen


}


void updateGameBoard(int move, int board[], int player) {
	--move;
	board[move] = player;
}


bool isMoveAllowed(int move, int board[]) {
	if (move < 0 && move > 9)
		return false;

	--move;
	
	if (board[move] == -1)
		return true;
	else
		return false;
}


void printBoard(int board[], int bsize);


void makeAImove(int board[], int AIsymbol) {
	int move = rand() % 9;

	while (!isMoveAllowed(move, board))
		move = rand() % 9;

	updateGameBoard(AIsymbol, move, board);
}


bool isGameWon(int board[]) {
	// 012 345 678 horizontal lines
	// 036 147 258 vertical lines 
	// 048 246     diagonals
	// ignore -1! empty element
	return false;
}


int main()
{
	srand(time(NULL));
	
	//flag that will be used to choose correct game mode, true - player 1, false -player 2
	bool isAgainstAI, playerTurn;

	//saves the chosen symbol, 0 circle, 1 cross
	int player1, player2; 
	//-1 empty, 0 circle, 1 cross
	int gameBoard[9] = { -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int playerChoice;

	//printPromptAI();
	//isAgainstAI = isAIplaying();

	printPromtOX();
	getUserSymbol(&player1, &player2);   //save O or X
	//printf("%d  %d", player1, player2);

    //promt lets begin game
	//clear the screen

	
	int counter = 0;
	while (1) {

		playerTurn = counter % 2 ? false : true;

		//if (isGameWon(gameBoard)) {
			// congrats and result prompt
			//break; //quit
		//}

		if (playerTurn)
			printf("player 1 move!");
		else
			printf("player 2 move!");

		
		scanf("%d", &playerChoice);

		while (!isMoveAllowed(playerChoice, gameBoard)) {
			printf("WRONG INPUT, try again!");
			scanf("%d", &playerChoice);
		}

		if (playerTurn)
			updateGameBoard(playerChoice, gameBoard, player1);
		else
			updateGameBoard(playerChoice, gameBoard, player2);
			

		for (int i = 0; i < 9; ++i)
			printf("%d  ", gameBoard[i]);
			



			 

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
		//   clear the screen
		//   print the noew updated board

		//user input
		//clear screen
		//data processing
		//terminal output
		++counter;
	}

	return 0;
}
