#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define CIRCLE 0
#define CROSS 1


void printWelcome() {
	char letter;
	FILE *fptr;
	fptr = fopen("welcome.txt", "r");

	if (fptr == NULL) {
		printf("Error!");
		fclose(fptr);
		return;
	}

	while (fscanf(fptr, "%c", &letter) != EOF) {
		printf("%c", letter);
	}

	fclose(fptr);
	return;
}


void printPromptAI() {
	printf("Would you like to play with a computer or another player?\n"); 
	// add large sign with AI or another player, 
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
	printf("Player ONE!!! Chose symbol!\n");
	printf("X    X         OOOO\n"
	       " X  X         O    O\n"
		   "  XX          O    O\n"
		   " X  X         O    O\n"
		   "X    X         OOOO\n"
		   "(1)     or    (2)\n"
		   );
}


void getUserSymbol(int *player, int  *other) {
	int choice;
	scanf("%d", &choice);
	--choice;

	if (!choice) {
		*player = CROSS;
		*other = CIRCLE;
	} 
	else {
		*player = CIRCLE;
		*other = CROSS;
	}
}


void printGameBegin() {
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


void printBoard(int board[], int bsize) {
}

// | needs corrections
int makePlayerMove(int board[]) {
	int move;
	scanf("%d", &move);
	while (!isMoveAllowed(move, board)) {
		printf("WRONG MOVE! Please repeat!");
		scanf("%d", &move); //check for weird inputs such as letters
	}
	return move;
}


int makeAIMove(int board[]) {
	int move = rand() % 9;
	while (!isMoveAllowed(move, board))
		move = rand() % 9;

	return move;
}

//maybe bool is not correct return type
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
	//flag that will be used to choose correct game mode,
	bool isAgainstAI;
	//true - player 1, false -player 2
	bool playerTurn;
	//saves the chosen symbol, 0 circle, 1 cross
	int player1, player2; 
	//-1 empty, 0 circle, 1 cross
	int gameBoard[9] = { -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	// saves moves between 1 and 9
	int nextMove; 

	printWelcome();
	printPromptAI();
	isAgainstAI = isAIplaying();

	printPromtOX();
	getUserSymbol(&player1, &player2);   //save O or X
	//make function that displays assigned symbols

    //promt lets begin game
	//clear the screen
	
	int counter = 0;
	int currentPlayer;
	while (false) {
		playerTurn = counter % 2 ? false : true;
		//check if game is won or is it draw


		if (playerTurn) {
			printf("Player 1! Make a move!\n");
			//nextMove = ->implement makePlayerMove();
		}
		else if (isAgainstAI) {
			printf("AI makes a move...");
			nextMove = makeAIMove(gameBoard);
		}
		else {
			printf("Player 2! Make a move!\n");
			//nextMove = ->implement makePlayerMove();
		}
			
		currentPlayer = playerTurn ? player1 : player2;
		updateGameBoard(nextMove, gameBoard, currentPlayer);
			
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
		++counter;
	}

	return 0;
}
