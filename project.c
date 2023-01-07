#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>;
#include <string.h>;
#include <conio.h>
#include <stdlib.h>
#include <time.h>

char square[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int choice;
int aiChoice;
int i;

void board();
void select();
void playAgain();
int checkwin();
int aiSelect();
int numberRandom();
int start();

int main() {
	srand(time(NULL));
	printf("Have you ever played against a machine?\n\n");
	start();
	//system("pause");
	return 0;
}

int start() {
	int whoStart;
	printf("Do you want to play first? Press 1 If not press 0");
	scanf("%d", &whoStart);
	if (whoStart == 1) {
		board();
		select();
	}
	else {
		square[5] = 'o';
		board();
		select();
	}
}

void board()
{
	printf("\n\n\tTic Tac Toe\n\n");

	printf("Player 1 (X)  VS  AI machine (O)\n\n\n");


	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

	printf("_____|_____|_____\n");
	printf("     |     |     \n");

	printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

	printf("_____|_____|_____\n");
	printf("     |     |     \n");

	printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

	printf("     |     |     \n\n");

}

void select() {
	printf("Select a number: ");
	scanf("%d", &choice);
	printf("%c\n", square[choice]);

	if (square[choice] == 'o' || square[choice] == 'x') {
		printf("This number is already taken\n");
		select();
	}
	else {
		square[choice] = 'x';
	    i = checkwin();
		if (i == 1) {
			board();
			printf("\n\nYou win, congratulations!!!\n\n");
			playAgain();
		}
		else if (i == 0) {
			board();
			printf("\n\nThe game ended in a draw\n\n");
			playAgain();
		}
		else if (i == -1) {
        aiChoice = aiSelect();
		square[aiChoice] = 'o';
		board();
		i = checkwin();
		if (i == 1) {
			board();
			printf("\n\nYou lose...\n\n");
			playAgain();
		}
		else if (i == 0) {
			board();
			printf("\n\nThe game ended in a draw\n\n");
			playAgain();
		}
		else if (i == -1) {
			select();
		}
		}
	}
}

int checkwin() {
	if (square[1] == square[2] && square[2] == square[3])
		return 1;

	else if (square[4] == square[5] && square[5] == square[6])
		return 1;

	else if (square[7] == square[8] && square[8] == square[9])
		return 1;

	else if (square[1] == square[4] && square[4] == square[7])
		return 1;

	else if (square[2] == square[5] && square[5] == square[8])
		return 1;

	else if (square[3] == square[6] && square[6] == square[9])
		return 1;

	else if (square[1] == square[5] && square[5] == square[9])
		return 1;

	else if (square[3] == square[5] && square[5] == square[7])
		return 1;

	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
		square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
		!= '7' && square[8] != '8' && square[9] != '9')

		return 0;
	else
		return  -1;
};

int aiSelect() {
	if (square[1] == 'o' && square[3] == 'o' && square[2] == '2')
		return 2;

	else if (square[4] == 'o' && square[6] == 'o' && square[5] == '5')
		return 5;

	else if (square[7] == 'o' && square[9] == 'o' && square[8] == '8')
		return 8;

	else if (square[1] == 'o' && square[7] == 'o' && square[4] == '4')
		return 4;

	else if (square[2] == 'o' && square[8] == 'o' && square[5] == '5')
		return 5;

	else if (square[3] == 'o' && square[9] == 'o' && square[6] == '6')
		return 6;

	else if (square[1] == 'o' && square[9] == 'o' && square[5] == '5')
		return 5;

	else if (square[3] == 'o' && square[7] == 'o' && square[5] == '5')
		return 5;

	else if (square[1] == 'o' && square[2] == 'o' && square[3] == '3')
		return 3;

	else if (square[3] == 'o' && square[2] == 'o' && square[1] == '1')
		return 1;

	else if (square[4] == 'o' && square[5] == 'o' && square[6] == '6')
		return 6;

	else if (square[5] == 'o' && square[6] == 'o' && square[4] == '4')
		return 4;

	else if (square[7] == 'o' && square[8] == 'o' && square[9] == '9')
		return 9;

	else if (square[8] == 'o' && square[9] == 'o' && square[7] == '7')
		return 7;

	else if (square[1] == 'o' && square[4] == 'o' && square[7] == '7')
		return 7;

	else if (square[4] == 'o' && square[7] == 'o' && square[1] == '1')
		return 1;

	else if (square[2] == 'o' && square[5] == 'o' && square[8] == '8')
		return 8;

	else if (square[5] == 'o' && square[8] == 'o' && square[2] == '2')
		return 2;

	else if (square[3] == 'o' && square[6] == 'o' && square[9] == '9')
		return 9;

	else if (square[6] == 'o' && square[9] == 'o' && square[3] == '3')
		return 3;
	else if (square[1] == 'o' && square[5] == 'o' && square[9] == '9')
		return 9;

	else if (square[5] == 'o' && square[9] == 'o' && square[1] == '1')
		return 1;

	else if (square[3] == 'o' && square[5] == 'o' && square[7] == '7')
		return 7;

	else if (square[5] == 'o' && square[7] == 'o' && square[3] == '3')
		return 3;



	else if (square[1] == 'x' && square[3] == 'x' && square[2] == '2')
		return 2;

	else if (square[4] == 'x' && square[6] == 'x' && square[5] == '5')
		return 5;

	else if (square[7] == 'x' && square[9] == 'x' && square[8] == '8')
		return 8;

	else if (square[1] == 'x' && square[7] == 'x' && square[4] == '4')
		return 4;

	else if (square[2] == 'x' && square[8] == 'x' && square[5] == '5')
		return 5;

	else if (square[3] == 'x' && square[9] == 'x' && square[6] == '6')
		return 6;

	else if (square[1] == 'x' && square[9] == 'x' && square[5] == '5')
		return 5;

	else if (square[3] == 'x' && square[7] == 'x' && square[5] == '5')
		return 5;

	else if (square[1] == 'x' && square[2] == 'x' && square[3] == '3')
		return 3;

	else if (square[3] == 'x' && square[2] == 'x' && square[1] == '1')
		return 1;

	else if (square[4] == 'x' && square[5] == 'x' && square[6] == '6')
		return 6;

	else if (square[5] == 'x' && square[6] == 'x' && square[4] == '4')
		return 4;

	else if (square[7] == 'x' && square[8] == 'x' && square[9] == '9')
		return 9;

	else if (square[8] == 'x' && square[9] == 'x' && square[7] == '7')
		return 7;

	else if (square[1] == 'x' && square[4] == 'x' && square[7] == '7')
		return 7;

	else if (square[4] == 'x' && square[7] == 'x' && square[1] == '1')
		return 1;

	else if (square[2] == 'x' && square[5] == 'x' && square[8] == '8')
		return 8;

	else if (square[5] == 'x' && square[8] == 'x' && square[2] == '2')
		return 2;

	else if (square[3] == 'x' && square[6] == 'x' && square[9] == '9')
		return 9;

	else if (square[6] == 'x' && square[9] == 'x' && square[3] == '3')
		return 3;

	else if (square[1] == 'x' && square[5] == 'x' && square[9] == '9')
		return 9;

	else if (square[5] == 'x' && square[9] == 'x' && square[1] == '1')
		return 1;

	else if (square[3] == 'x' && square[5] == 'x' && square[7] == '7')
		return 7;

	else if (square[5] == 'x' && square[7] == 'x' && square[3] == '3')
		return 3;


	else if (square[5] == '5')
		return 5;

	else 
		return numberRandom();
}

int numberRandom() {
	int number = (rand() % 9) + 1;
	if (square[number] == 'o' || square[number] == 'x') {
		numberRandom();
	}
	else {
		printf("%d" , number);
		return number;
	}
}

void playAgain() {
	int again;
	printf("Do you want to play again? press 1 If not press 0");
	scanf("%d", &again);
	if (again == 1) {
		square[1] = '1'; square[2] = '2'; square[3] = '3';
		square[4] = '4'; square[5] = '5'; square[6] = '6';
		square[7] = '7'; square[8] = '8'; square[9] = '9';
		start();
		}
    else if (again == 'n') {
    exit(0);
     }
}
