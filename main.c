#include <stdio.h>
#include <stdbool.h>

int main()
{
	bool isAgainstAI = false; //flag that will be used to choose correct game mode
	char userChoice;
	int gameBoad[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

	printf("Welcome to the Tic Tac Toe game!!!\n\
			\rWould you like to play with a computer or another player?\n\
			\rTo play with the computer type \"C\"\n\
			\rTo play with a partner type \"H\"\n"
		  );

	scanf("%c", &userChoice);

	if (userChoice == 'c' || userChoice == 'C')
		isAgainstAI == true;
	else
		isAgainstAI == false;
	
	printf("\n%c", userChoice);

	while (1) {
		//user input
		//data processing
		//terminal output
		break;
	}

	return 0;
}
