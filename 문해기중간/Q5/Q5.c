#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int n, k, l, tmp, i, j;
	int* A, * B;

	scanf("%d", &n);
	scanf("%d", &k);
	scanf("%d", &l);

	if (n <= 0 || k <= 0) return 0;
	A = (int*)malloc(sizeof(int) * n);
	B = (int*)malloc(sizeof(int) * k);
	if (!A || !B) return 0;

	for (i = 0; i < k; i++) scanf("%d", &B[i]);
	for (i = 0; i < n; i++) A[i] = i;

	for (i = 0; i < k; i++)
	{
		int idx = 0;
		for (j = 0; j < n; j++)
			if (A[j] == B[i]) {
				idx = j;
				break;
			}
		if (idx != 0)
		{
			tmp = A[idx];
			A[idx] = A[idx - 1];
			A[idx - 1] = tmp;
		}
	}

	printf("%d\n", A[l]);

	free(A);
	free(B);
	return 0;
}