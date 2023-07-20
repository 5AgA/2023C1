// 피보나치 최적화
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int fib(int n, int* F)
{
	if (F[n] != 0) {
		return F[n];
	}
	else if (n == 1 || n == 2) {
		F[n] = 1;
		printf(" %d", F[n]);
		return F[n];
	}
	else {
		F[n] = fib(n - 1, F) + fib(n - 2, F);
		printf(" %d", F[n]);
		return F[n];
	}
}

int main(void)
{
	int n, i;
	int* F;

	printf("몇 번째까지의 피보나치 수열: ");
	scanf("%d", &n);
	if (n <= 0) return 0;
	F = (int*)malloc(sizeof(int) * (n + 1));
	if (!F) return 0;
	for (i = 1; i <= n; i++)
		F[i] = 0;

	fib(n, F);
	printf("\n");

	free(F);
	return 0;
}