// 피구 - 조합 최종본
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int pick(int* N, int n, int* M, int m, int k, int sum, int tmp)
{
	int i, lastIndex, smallest, min = sum;

	if (k == 0) {
		/*for (i = 0; i < m; i++) {
			printf("%d\t", N[M[i]]);
		}
		printf("%d\n", abs(sum - 2 * tmp));*/
		return abs(sum - 2 * tmp);
	}

	lastIndex = m - k - 1;
	if (m == k) smallest = 0;
	else smallest = M[lastIndex] + 1;

	for (i = smallest; i < n; i++) {
		int d = 0;
		M[lastIndex + 1] = i;
		if (M[0] != 0) return min;
		d = pick(N, n, M, m, k - 1, sum, tmp + N[i]);
		if (d < min) min = d;
	}
	return min;
}

int main(void)
{
	int n, m, i, sum = 0;
	int* N,* M;

	scanf("%d", &n);
	if (n < 1 || n % 2 != 0) return 0;
	m = n / 2;
	N = (int*)malloc(sizeof(int) * n);
	M = (int*)malloc(sizeof(int) * m);
	if (!N || !M) return 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &N[i]);
		sum += N[i];
	}

	printf("%d\n", pick(N, n, M, m, m, sum, 0));

	free(N);
	free(M);
	return 0;
}