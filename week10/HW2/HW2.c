// ��� �� �����Ҵ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void readMatrix(int** a, int r, int c)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			scanf("%d", &a[i][j]);

	return;
}

void matrixMulti(int** a, int** b, int** x, int r, int l, int c)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			x[i][j] = 0;
			for (int k = 0; k < l; k++)
				x[i][j] += a[i][k] * b[k][j];
		}
	return;
}

void printMatrix(int** a, int r, int c)
{
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			printf("%d\t", a[i][j]);
		printf("\n");
	}

	return;
}

int main(void)
{
	int** A, ** B, ** X;
	int  aR, aC, bR, bC;
	int i, j;

	printf("Enter ��� A�� ��� ���� ����: ");
	scanf("%d %d", &aR, &aC);
	printf("Enter ��� B�� ��� ���� ����(B�� ���� %d�̾��): ", aC);
	scanf("%d %d", &bR, &bC);

	if (aR <= 0 || bR <= 0) return 0;
	A = (int**)malloc(sizeof(int*) * aR);
	B = (int**)malloc(sizeof(int*) * bR);
	X = (int**)malloc(sizeof(int*) * aR);
	for (i = 0; i < aR; i++) {
		A[i] = (int*)malloc(sizeof(int) * aC);
		X[i] = (int*)malloc(sizeof(int) * bC);
	}
	for (i = 0; i < bR; i++)
		B[i] = (int*)malloc(sizeof(int) * bC);
	if (!A || !B || !X) return 0;

	printf("%d x %d ��� A �Է�:\n", aR, aC);
	readMatrix(A, aR, aC);
	printf("\n%d x %d ��� B �Է�:\n", bR, bC);
	readMatrix(B, bR, bC);

	matrixMulti(A, B, X, aR, aC, bC);
	printf("\n��İ�:\n");
	printMatrix(X, aR, bC); printf("\n");

	printf("\n��ġ���:\n");
	for (i = 0; i < aC; i++) {
		for (j = 0; j < aR; j++)
			printf("%d\t", A[j][i]);
		printf("\n");
	}

	for (i = 0; i < aR; i++) {
		free(A[i]);
		free(X[i]);
	}
	for (i = 0; i < bR; i++)
		free(B[i]);
	free(A);
	free(B);
	free(X);
	return 0;
}