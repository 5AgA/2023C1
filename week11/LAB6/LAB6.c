// H �Լ� - memo O
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int H(int n, int* M)
{
	if (M[n] != 0) return M[n];
	if (n == 0 || n == 1) {
		M[n] = 1;
		return M[n];
	}
	else {
		for (int i = n - 1; i >= 0; i--) {
			M[n] += H(i, M) * H(n - i - 1, M);
		}
		return M[n];
	}
}

int main(void)
{
	int* M;
	int n;

	printf("0���� ū ����: ");
	scanf("%d", &n);

	M = (int*)malloc(sizeof(int) * (n + 1));
	if (!M) return 0;
	for (int i = 0; i < n + 1; i++)
		M[i] = 0;

	printf("����� %d\n", H(n, M));


	free(M);
	return 0;
}