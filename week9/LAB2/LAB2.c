// Quick Sort
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int* A, int p, int r)
{
	int i = p - 1, j, t;

	for (j = p; j < r; j++) {
		if (A[j] < A[r]) {
			i++;
			t = A[i];
			A[i] = A[j];
			A[j] = t;
		}
	}

	t = A[r];
	A[r] = A[i + 1];
	A[i + 1] = t;

	return i + 1;
}

void quickSort(int* A, int p, int r)
{
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
	return;
}

int main(void)
{
	int* A;
	int n;

	scanf("%d", &n);
	if (n <= 0) return 0;
	A = (int*)malloc(sizeof(int) * n);
	if (!A) return 0;

	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		A[i] = rand() % 101;
		printf("%d ", A[i]);
	}
	printf("\n\nÁ¤·Ä ÈÄ\n");

	quickSort(A, 0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");

	free(A);
	return 0;
}