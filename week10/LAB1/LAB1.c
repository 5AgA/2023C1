// 행렬 합 정적 할당
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void readMatrix(int a[][3])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &a[i][j]);

	return;
}

void matrixAdd(int a[][3], int b[][3], int x[][3])
{
	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < 3; j++) 
			x[i][j] = a[i][j] + b[i][j];
	return;
}

void printMatrix(int a[][3])
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			printf("%d\t", a[i][j]);
		printf("\n");
	}

	return;
}

int main(void)
{
	int A[3][3], B[3][3], X[3][3];

	printf("(3 x 3) 행렬 A 입력:\n");
	readMatrix(A);
	printf("(3 x 3) 행렬 B 입력:\n");
	readMatrix(B);
	matrixAdd(A, B, X);
	printf("행렬합:\n");
	printMatrix(X);

	return 0;
}