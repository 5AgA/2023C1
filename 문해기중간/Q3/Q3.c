#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* A, int n)
{
	int i, j;
	int tmp;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (A[j] > A[j + 1])
			{
				tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
			}
}

int main(void)
{
	int n, i, k, sum = 0;
	int* A, * B;

	scanf("%d", &n);
	scanf("%d", &k);
	if (n <= 0) return 0;
	A = (int*)malloc(sizeof(int) * n);
	B = (int*)malloc(sizeof(int) * n);
	if (!A || !B) return 0;

	for (i = 0; i < n; i++) scanf("%d", &A[i]);
	for (i = 0; i < n; i++) scanf("%d", &B[i]);

	bubbleSort(A, n);
	bubbleSort(B, n);

	for (i = 0; i < k; i++)
		B[i] = A[n - i - 1];
	
	for (i = 0; i < n; i++)
		sum += B[i];

	printf("%d\n", sum);

	free(A);
	free(B);
	return 0;
}