// Matrix path - backpointer
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void print_path(int i, int j, int** bp); // 0: up, 1: left

int matrixPath_memo(int** m, int r, int c, int i, int j, int** M, int** bp)
{
	if (M[i][j] != 0) {
		return M[i][j];
	}
	if (i == 0 && j == 0) {
		bp[i][j] = -1;
		return m[i][j];
	}
	else if (i == 0) {
		M[i][j] = matrixPath_memo(m, r, c, 0, j - 1, M, bp) + m[i][j];
		bp[i][j] = 1;
		return M[i][j];
	}
	else if (j == 0) {
		M[i][j] = matrixPath_memo(m, r, c, i - 1, 0, M, bp) + m[i][j];
		bp[i][j] = 0;
		return M[i][j];
	}
	else {
		int a, b;
		a = matrixPath_memo(m, r, c, i - 1, j, M, bp); // up
		b = matrixPath_memo(m, r, c, i, j - 1, M, bp); // le
		bp[i][j] = (a < b) ? 0 : 1;
		M[i][j] = ((a < b) ? a : b) + m[i][j];
		return M[i][j];
	}
}

void print_path(int i, int j, int** bp)
{
	if (bp[i][j] == 0)
		print_path(i - 1, j, bp);
	else if (bp[i][j] == 1)
		print_path(i, j - 1, bp);
	printf("<%d, %d> ", i, j);
	return;
}

int main(void)
{
	int** m, ** M;
	int** bp;
	int i, j, r, c;
	r = c = 4; // 4x4 matrix

	m = (int**)malloc(sizeof(int*) * r);
	M = (int**)malloc(sizeof(int*) * r);
	bp = (int**)malloc(sizeof(int*) * r);
	if (!m || !M || !bp) return 0;
	for (i = 0; i < r; i++) {
		m[i] = (int*)malloc(sizeof(int) * c);
		M[i] = (int*)malloc(sizeof(int) * c);
		bp[i] = (int*)malloc(sizeof(int) * c);
		if (!m[i] || !M[i] || !bp[i]) return 0;
	}

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			scanf("%d", &m[i][j]);
			M[i][j] = 0;
			bp[i][j] = -1;
		}
	}

	printf("%d\n", matrixPath_memo(m, r, c, 3, 3, M, bp));
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			if (bp[i][j] == 0)
				printf("UP\t");
			else if (bp[i][j] == 1)
				printf("Left\t");
			else
				printf("Start\t");
		}
		printf("\n");
	}
	printf("\n경로 출력: ");
	print_path(3, 3, bp);
	printf("\n");

	for (i = 0; i < r; i++) {
		free(m[i]);
		free(M[i]);
		free(bp[i]);
	}
	free(bp);
	free(m);
	free(M);
	return 0;
}

/*
6 7 12 5
5 3 11 18
7 17 3 3
8 10 14 9
*/