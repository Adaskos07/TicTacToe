#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> //comment out if not on UNIX system

#define CIRCLE 0
#define CROSS 1
#define EMPTY -1

void printWelcome();
void printPromptAI();
bool isAIplaying();
void printPromtOX();
void getUserSymbol(int *player, int  *other);
void updateGameBoard(int move, int board[], int player);
bool isMoveAllowed(int move, int board[]);
void printBoard(int board[]);
int makePlayerMove(int board[]);
int makeAIMove(int board[]);
int makeAIMove(int board[]);
int isGameWon(int board[]);
void plrWonMsg(bool plrTurn, bool isAI);
void saveGameResult(bool draw, bool plrTurn, bool isAI);

		//   check is the game is won, remember the counter
		//   promt user 1 or 2 depending in the counter
		//   take  input
		//   check if move is correct if not move back two steps
		//   change the internal board represented by array
		//   clear the screen
		//   print the new updated board
		//   check is someone win
		//   if yes, ask for the next game else ask player for the move

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
	clear the screien
	*/
	int gameState = -1;
	int counter = 0;
	int currentPlrSymbol;
	while (true) {
		isPlrOneTurn = counter % 2 ? false : true;

		if (isPlrOneTurn) {
			printf("Player 1! Make a move!\n");
			nextMove = makePlayerMove(gameBoard);
		}
		else if (isAgainstAI) {
			printf("AI makes a move...\n");
			sleep(1); //non portable, comment out on windows
			nextMove = makeAIMove(gameBoard);
		}
		else {
			printf("Player 2! Make a move!\n");
			nextMove = makePlayerMove(gameBoard);
		}

			
		//system("clear");
		currentPlrSymbol = isPlrOneTurn ? player1 : player2;
		updateGameBoard(nextMove, gameBoard, currentPlrSymbol);

		printBoard(gameBoard);
		
		gameState = isGameWon(gameBoard);
		/* -1 = game goes on, 0 = draw, 1 - game won */
		/* check if game is won or is it a draw */
		if (gameState == 1) {
			plrWonMsg(isPlrOneTurn, isAgainstAI);	
            saveGameResult(false, isPlrOneTurn, isAgainstAI);
			break;
		}
		else if (gameState == 0) {
			printf("The game ended with DRAW!!!\n");
            saveGameResult(true, isPlrOneTurn, isAgainstAI);
			break;
		}
			
		++counter;
	}

	return 0;
}

void printWelcome() {
	char letter;
	FILE *fptr;
	fptr = fopen("welcome.txt", "r");

	if (fptr == NULL) {
		printf("Error!");
		fclose(fptr);
		return;
	}

	while (fscanf(fptr, "%c", &letter) != EOF)
		printf("%c", letter);

	fclose(fptr);
	return;
}


void printPromptAI() {
	printf("Would you like to play with a computer[TYPE 1]"
	       " or another player[TYPE 2]?\n"); 
		   printf(" ________ ________             _______\n"
		   		  " |      |    |         |****          |\n"
				  " |      |    |         |    *   ______|\n"
		          " |______|    |         |****   |       \n"
				  " |      | ___|____     |       |_______\n\n"
				  "  (1)              or            (2)    \n");
	/* add large sign with AI or another player, */
}


bool isAIplaying() {
	int userChoice;
	scanf("%d", &userChoice);
	--userChoice;

	if (userChoice) // choice has to be deacreased by one 
		return false; // first option is AI !(1 - 1 = 0) = true
	else
		return true; // any number larger than 1 will be play with parter
}


void printPromtOX() {
	printf("Player ONE!!! Chose symbol!\n\n");
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
	if (choice) {
		*player = CIRCLE;
		*other = CROSS;
	} 
	else {
		*player = CROSS;
		*other = CIRCLE;
	}
}


void printBoard(int board[]) {
	/* interpretation of numeric values loaded into a char array */
	char symbols[9]; 
	int symbol;
	for (int i = 0; i < 9; ++i) {
		symbol = board[i];
		switch (symbol) {
			case EMPTY:
				symbols[i] = '1' + i;
				break;
			case CIRCLE:
				symbols[i] = '0';
				break;
			case CROSS:
				symbols[i] = 'X';
		}
	}
	/* printing values according to symbols array */
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
		   ,symbols[0], symbols[1], symbols[2]
		   ,symbols[3], symbols[4], symbols[5]
		   ,symbols[6], symbols[7], symbols[8]
		   );
}


void updateGameBoard(int move, int board[], int player) {
	--move;
	board[move] = player;
}


bool isMoveAllowed(int move, int board[]) {
	if (move < 1 || move > 9)
		return false;

	--move;
	
	if (board[move] == EMPTY)
		return true;
	else
		return false;
}


/* needs corrections!!! Don't touch for now */
int makePlayerMove(int board[]) {
	int move;
	char buf[30], *buf_ptr, *ptr;
	/* I am not sure completely why it works...*/
	fgets(buf, (sizeof buf), stdin);
	move = strtol(buf, &ptr, 10);

	while (!isMoveAllowed(move, board)) {
		//int ch;
		//while ((ch = getchar() != '\n') && (ch != EOF))
		//	;
		printf("WRONG MOVE! Please repeat!\n");
		fgets(buf, (sizeof buf), stdin);
		move = strtol(buf, &ptr, 10);
		//scanf("%d", &move); /*check for weird inputs such as letters*/
	}
	return move;
}


int makeAIMove(int board[]) {
	int move = (rand() % 9) + 1;
	while (!isMoveAllowed(move, board))
		move = (rand() % 9) + 1;

	return move;
}


int isGameWon(int board[]) {
	// 012 345 678 horizontal lines
	// 036 147 258 vertical lines 
	// 048 246     diagonals
	// ignore -1! empty element
	int wins[8][3] = { {0, 1, 2},
					   {3, 4, 5},
					   {6, 7, 8},
					   {0, 3, 6},
					   {1, 4, 7},
					   {2, 5, 8},
					   {0, 4, 8},
					   {2, 4, 6} };

	/* if any winning position return 1 */
	int i, j, prev;
	for (i = 0; i < 8; ++i) {
		for (j = 1; j < 3; ++j) {
			prev = board[ wins[i][j-1] ];
			if ((prev != EMPTY) && (prev == board[ wins[i][j] ])) {
				if (j == 2)
					return 1;
				continue;
			}
			else
				break;
		}
	}
	/* if any non empty, then game goes on */
	int k;	
	for (k = 0; k < 9; ++k) {
		if (board[k] != EMPTY)
			continue;
		return -1;
	}
	return 0; /* otherwise return 0, a draw */
}


void plrWonMsg(bool plrTurn, bool isAI) {
	printf("Hooray!\n");
	if (plrTurn)
		printf("Player 1 won!\n");
	else if (isAI)
		printf("The superior computer won... >:) \n");
	else
		printf("Player 2 won!\n");
}


void saveGameResult(bool draw, bool plrTurn, bool isAI) {
    int rslt;
    FILE *fptr;
    fptr = fopen("results.txt", "a");

	if (fptr == NULL) {
		printf("ERROR File not found!");
		fclose(fptr);
		return;
	}

    int combs[4][3] = { {0, 0, 0}, {1, 0, 0}, {0, 0, 1}, {0, 1, 0} };

    if (draw)
        rslt = 0;
	else if (plrTurn)
        rslt = 1;
	else if (isAI)
        rslt = 2;
	else
        rslt = 3;

    fprintf(fptr, "Player 1: %d, Player 2: %d, AI: %d\n", 
            combs[rslt][0], combs[rslt][1], combs[rslt][2]);

	fclose(fptr);
}
