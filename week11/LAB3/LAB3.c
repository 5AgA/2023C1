// 행렬 길 찾기 - memo O
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int matrixPath_memo(int** m, int r, int c, int i, int j, int** M)
{
	if (M[i][j] != 0) return M[i][j];
	if (i == 0 && j == 0) return m[i][j];
	else if (i == 0) {
		M[i][j] = matrixPath_memo(m, r, c, 0, j - 1, M) + m[i][j];
		return M[i][j];
	}
	else if (j == 0) {
		M[i][j] = matrixPath_memo(m, r, c, i - 1, 0, M) + m[i][j];
		return M[i][j];
	}
	else {
		int a, b;
		a = matrixPath_memo(m, r, c, i - 1, j, M);
		b = matrixPath_memo(m, r, c, i, j - 1, M);
		M[i][j] = ((a < b) ? a : b) + m[i][j];
		return M[i][j];
	}
}

int main(void)
{
	int** m, ** M;
	int i, j, r, c;
	r = c = 4; // 4x4 matrix

	m = (int**)malloc(sizeof(int*) * r);
	M = (int**)malloc(sizeof(int*) * r);
	if (!m || !M) return 0;
	for (i = 0; i < r; i++) {
		m[i] = (int*)malloc(sizeof(int) * c);
		M[i] = (int*)malloc(sizeof(int) * c);
		if (!m[i] || !M[i]) return 0;
	}

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			scanf("%d", &m[i][j]);
			M[i][j] = 0;
		}
	}

	printf("%d\n", matrixPath_memo(m, r, c, 3, 3, M));

	for (i = 0; i < r; i++) {
		free(m[i]);
		free(M[i]);
	}
	free(m);
	free(M);
	return 0;
}