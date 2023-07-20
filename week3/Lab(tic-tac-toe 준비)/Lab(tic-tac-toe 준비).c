#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void display(char b[][3])
{
	printf("    0 1 2\n");
	printf("    -----\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%d  |", i);
		for (int j = 0; j < 3; j++)
		{
			if (b[i][j] == '\0')
				printf("  ");
			else
				printf("%c ", b[i][j]);
		}
		printf("\n");
	}
}
int main(void)
{
	int isFull = 0;
	int row, col;
	char game[3][3] = {0};
	for (int i = 0; i < 9; i++) 
	{
		display(game);
		if (i % 2 == 0)
		{
			printf("Player X(행 열):");
			scanf_s("%d %d", &col, &row);
			game[col][row] = 'X';
		}
		else
		{
			printf("Player O(행 열):");
			scanf_s("%d %d", &col, &row);
			game[col][row] = 'O';
		}
	}

	return 0;
}