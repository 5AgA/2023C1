// 행렬 길 찾기 - memo X
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int matrixPath(int** m, int r, int c, int i, int j)
{
	if (i == 0 && j == 0) return m[i][j];
	else if (i == 0) return (matrixPath(m, r, c, 0, j - 1) + m[i][j]);  // 왼쪽
	else if (j == 0) return (matrixPath(m, r, c, i - 1, 0) + m[i][j]);  // 위
	else {
		int a, b;
		a = matrixPath(m, r, c, i - 1, j);  // 위
		b = matrixPath(m, r, c, i, j - 1);  // 왼쪽
		return ((a < b) ? a : b) + m[i][j];
	}
}

int main(void)
{
	int** m;
	int i, j, r, c;
	r = c = 4;        // 4x4 matrix

	m = (int**)malloc(sizeof(int*) * r); 
	if (!m) return 0;
	for (i = 0; i < r; i++) {
		m[i] = (int*)malloc(sizeof(int) * c);
		if (!m[i]) return 0;
	}
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			scanf("%d", &m[i][j]);
	printf("%d\n", matrixPath(m, r, c, 3, 3));
	
	for (i = 0; i < r; i++)
		free(m[i]);
	free(m);
	return 0;
}