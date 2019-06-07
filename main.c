#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

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
	printf("Would you like to play with a computer[TYPE 1]"
	       " or another player[TYPE 2]?\n"); 
	/* add large sign with AI or another player, */
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
		   "X    X         OOOO\n\n"
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
	if (move < 1 || move > 9)
		return false;

	--move;
	
	if (board[move] == -1)
		return true;
	else
		return false;
}


void printBoard(int board[]) {
	char symbols[9]; 
	int symbol;
	for (int i = 0; i < 9; ++i) {
		symbol = board[i];
		switch (symbol) {
			case -1:
				symbols[i] = '1' + i;
				break;
			case 0:
				symbols[i] = 'O';
				break;
			case 1:
				symbols[i] = 'X';
		}
	}
    printf("\n\n\tTic Tac Toe\n\n");
    printf("      |      |     \n");
    printf("   %c  |  %c   |  %c \n", symbols[0], symbols[1], symbols[2]);
    printf("______|______|______\n");
    printf("      |      |     \n");
    printf("   %c  |  %c   |  %c \n", symbols[3], symbols[4], symbols[5]);
    printf("______|______|______\n");
    printf("      |      |     \n");
    printf("   %c  |  %c   |  %c \n", symbols[6], symbols[7], symbols[8]);
    printf("      |      |     \n\n");
	/*
    printf("\n\n\tTic Tac Toe\n\n"
           "      |      |     \n"
           "   %c  |  %c   |  %c \n"
           "______|______|______\n"
           "      |      |     \n"
           "   %c  |  %c   |  %c \n"
           "______|______|______\n"
           "      |      |     \n"
           "   %c  |  %c   |  %c \n"
           "      |      |     \n\n"
		   , symbols[0], symbols[1], symbols[2]
		   , symbols[3], symbols[4], symbols[5]
		   , symbols[6], symbols[7], symbols[8]
		   );
	*/
}

/* needs corrections */
int makePlayerMove(int board[]) {
	int move;
	scanf("%d", &move);
	while (!isMoveAllowed(move, board)) {
		printf("WRONG MOVE! Please repeat!");
		scanf("%d", &move); /*check for weird inputs such as letters*/
	}
	return move;
}


int makeAIMove(int board[]) {
	int move = (rand() % 9) + 1;
	while (!isMoveAllowed(move, board))
		move = (rand() % 9) + 1;

	return move;
}

/*maybe bool is not correct return type*/
int isGameWon(int board[]) {
	// 012 345 678 horizontal lines
	// 036 147 258 vertical lines 
	// 048 246     diagonals
	// ignore -1! empty element
	if (board[0] == board[1] && board[1] == board[2])                       
         return 1;                                                           
                                                                             
    else if (board[3] == board[4] && board[4] == board[5])                  
         return 1;                                                           
                                                                             
     else if (board[6] == board[7] && board[7] == board[8])                  
         return 1;                                                           
                                                                            
    // vertical lines                                                       
                                                                         
     else if (board[0] == board[3] && board[3] == board[6])                  
        return 1;                                                           
                                                                             
     else if (board[1] == board[4] && board[4] == board[7])                  
        return 1;                                                           
                                                                             
     else if (board[2] == board[5] && board[5] == board[8])                  
        return 1;                                                           
                                                                             
     // diagonals                                                            
                                                                             
     else if (board[0] == board[4] && board[4] == board[8])                  
         return 1;                                                           
                                                                             
     else if (board[2] == board[4] && board[4] == board[6])                  
         return 1;                                                           
                                                                             
     // basically the board is all filled up, so it's game over              
                                                                             
     else if (board[0] != -1 && board[1] != -1 && board[3] != -1 &&          
              board[4] != -1 && board[5] != -1 && board[6] != -1 &&
              board[7] != -1 && board[8] != -1 && board[9] != -1
			  )
          return 0;
  
     else
         return -1;
   	
}


int main()
{
	srand(time(NULL));
	/* flag that will be used to choose correct game mode */
	bool isAgainstAI;
	/* true - player 1, false -player 2 */
	bool isPlrOneTurn;
	/* saves the chosen symbol, 0 circle, 1 cross */
	int player1, player2; 
	/* -1 empty, 0 circle, 1 cross */
	int gameBoard[9] = { -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	/* saves moves between 1 and 9 */
	int nextMove; 

	printWelcome();
	printPromptAI();
	isAgainstAI = isAIplaying();
	printPromtOX();
	getUserSymbol(&player1, &player2); 
	/* make function that displays assigned symbols */
	printBoard(gameBoard);

    /*
	promt lets begin game
	clear the screen
	*/
	
	int counter = 0;
	int currentPlayer;
	while (true) {
		isPlrOneTurn = counter % 2 ? false : true;
		/* check if game is won or is it a draw */

		if (isPlrOneTurn) {
			printf("Player 1! Make a move!\n");
			nextMove = makePlayerMove(gameBoard);
		}
		else if (isAgainstAI) {
			printf("AI makes a move...\n");
			sleep(2); //non portable, comment out on windows
			nextMove = makeAIMove(gameBoard);
		}
		else {
			printf("Player 2! Make a move!\n");
			nextMove = makePlayerMove(gameBoard);
		}
			
		//system("clear");
		currentPlayer = isPlrOneTurn ? player1 : player2;
		updateGameBoard(nextMove, gameBoard, currentPlayer);

		printBoard(gameBoard);
			
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
