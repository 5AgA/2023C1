#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int fib(int n, int* F, int k)
{
	if (F[n] != 0) {
		return F[n];
	}
	else if (n <= k && n > 0) {
		F[n] = 1;
		return F[n];
	}
	else {
		for (int i = 1; i <= k; i++) {
			F[n] += fib(n - i, F, k);
		}
		return F[n];
	}
}

int main(void)
{
	int n, i, k;
	int* F;

	scanf("%d %d", &n, &k);
	if (n <= 0) return 0;
	F = (int*)malloc(sizeof(int) * (n + 1));
	if (!F) return 0;
	for (i = 1; i <= n; i++)
		F[i] = 0;

	fib(n, F, k);
	printf("%d\n", F[n]);

	free(F);
	return 0;
}