// 조합의 수 - memo O
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int comb(int n, int r, int **C)
{
	if (C[r][n] != 0) return C[r][n];
	if (r == 0 || r == n) {
		C[r][n] = 1;
		return C[r][n];
	}
	else {
		C[r][n] = comb(n - 1, r - 1, C) + comb(n - 1, r, C);
		return C[r][n];
	}
}

int main(void)
{
	int** C;
	int i, j, n, r;

	printf("Enter nCr(n r): ");
	scanf("%d %d", &n, &r);

	C = (int**)malloc(sizeof(int*) * (r + 1));
	if (!C) return 0;
	for (i = 0; i < (r + 1); i++) {
		C[i] = (int*)malloc(sizeof(int) * (n + 1));
		if (!C[i]) return 0;
	}
	for (i = 0; i < (r + 1); i++)
		for (j = 0; j < (n + 1); j++)
			C[i][j] = 0;

	printf("\n%dC%d = %d\n", n, r, comb(n, r, C));

	for (i = 0; i < (r + 1); i++)
		free(C[i]);
	free(C);
	return 0;
}