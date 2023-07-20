// 제곱수의 합
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int pick(int* picked, int m, int k, int n, int min)
{
	int biggest, lastIndex, i;

	if (m - k + 1 > min) return min;
	if (k == 0 || n == 0) {
		/*for (i = 0; i < m - k; i++) {
			printf("%d^2 ", picked[i]);
			if (i != m - k - 1) printf("+ ");
		}
		printf("\n");*/
		return m - k;
	}

	lastIndex = m - k - 1;
	if (m == k) biggest = n;
	else biggest = picked[lastIndex];

	int cnt = 0;
	for (i = biggest; i >= 0; i--) {
		if (i * i > n) continue;
		picked[lastIndex + 1] = i;
		cnt = pick(picked, m, k - 1, n - i * i, min);
		if (cnt < min) min = cnt;
	}
	return cnt;
}

int main(void)
{
	int* picked;
	int item = 3, n;

	scanf("%d", &n);

	if (n <= 0) return 0;
	picked = (int*)malloc(sizeof(int) * n);
	if (!picked) return 0;

	printf("%d\n", pick(picked, n, n, n, n));

	free(picked);
	return 0;
}
