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
int whosWin(char b[][3])
{
	int sumX = 0, sumO = 0;
	// 가로
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (b[i][j] == 'X')
				sumX++;
			else if (b[i][j] == 'O')
				sumO++;
		}
		if (sumX == 3)
			return 1;
		else if (sumO == 3)
			return 2;
		else
		{
			sumX = 0;
			sumO = 0;
		}
	}
	// 세로
 	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (b[j][i] == 'X')
				sumX++;
			else if (b[j][i] == 'O')
				sumO++;
		}
		if (sumX == 3)
			return 1;
		else if (sumO == 3)
			return 2;
		else
		{
			sumX = 0;
			sumO = 0;
		}
	}

	// 대각선1
	for (int i = 0; i < 3; i++)
	{
		if (b[i][i] == 'X')
			sumX++;
		else if (b[i][i] == 'O')
			sumO++;
	}
	if (sumX == 3)
		return 1;
	else if (sumO == 3)
		return 2;
	else
	{
		sumX = 0;
		sumO = 0;
	}

	// 대각선2
	for (int i = 2; i >= 0; i--)
	{
		if (b[2 - i][i] == 'X')
			sumX++;
		else if (b[2 - i][i] == 'O')
			sumO++;
	}
	if (sumX == 3)
		return 1;
	else if (sumO == 3)
		return 2;
	else
	{
		sumX = 0;
		sumO = 0;
	}

	return 0;
}
int main(void)
{
	int isFull = 0;
	int row, col;
	char board[3][3] = { 0 };
	for (int i = 0; i < 9; i++)
	{
		display(board);
		if (i % 2 == 0)
		{
			do {
				printf("Player X(행 열):");
				scanf_s("%d %d", &col, &row);
			} while (board[col][row] == 'X' || board[col][row] == 'O');
			board[col][row] = 'X';
		}
		else
		{
			do {
				printf("Player O(행 열):");
				scanf_s("%d %d", &col, &row);
			} while (board[col][row] == 'X' || board[col][row] == 'O');
			board[col][row] = 'O';
		}
		if (i == 8 && whosWin(board) == 0)
		{
			display(board);
			printf("Nobody wins!");
		}
		else if (whosWin(board) == 1)
		{
			display(board);
			printf("Player X wins!\n");
			break;
		}
		else if (whosWin(board) == 2)
		{
			display(board);
			printf("Player O wins!\n");
			break;
		}
	}

	return 0;
}