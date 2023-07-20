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

void matrixAdd(int** a, int** b, int** x, int r, int c)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			x[i][j] = a[i][j] + b[i][j];
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
	int  aRow, aCol;
	int i;

	printf("Enter ��� A�� B�� ��� ���� ����: ");
	scanf("%d %d", &aRow, &aCol);

	if (aRow <= 0) return 0;
	A = (int**)malloc(sizeof(int*) * aRow);
	B = (int**)malloc(sizeof(int*) * aRow);
	X = (int**)malloc(sizeof(int*) * aRow);
	for (i = 0; i < aRow; i++) {
		A[i] = (int*)malloc(sizeof(int) * aCol);
		B[i] = (int*)malloc(sizeof(int) * aCol);
		X[i] = (int*)malloc(sizeof(int) * aCol);
	}
	if (!A || !B || !X) return 0;

	printf("��� A�� ���� �Է�:\n");
	readMatrix(A, aRow, aCol);
	printf("��� B�� ���� �Է�:\n");
	readMatrix(B, aRow, aCol);

	matrixAdd(A, B, X, aRow, aCol);
	printf("�����:\n");
	printMatrix(X, aRow, aCol); printf("\n");

	for (i = 0; i < aRow; i++) {
		free(A[i]);
		free(B[i]);
		free(X[i]);
	}
	free(A);
	free(B);
	free(X);
	return 0;
}