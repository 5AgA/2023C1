// Merge Sort
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int* A, int p, int q, int r, int *temp) 
{
	int i, j, t;

	i = p;
	j = q + 1;
	t = p;

	while (i <= q && j <= r) {
		if (A[i] < A[j]) {
			temp[t] = A[i];
			t++; i++;
		}
		else {
			temp[t] = A[j];
			t++; j++;
		}
	}

	if (j > r) {
		for (; i <= q; i++, t++)
			temp[t] = A[i];
	}
	else {
		for (; j <= r; j++, t++)
			temp[t] = A[j];
	}
	for (i = p; i <= r; i++)
		A[i] = temp[i];
	return;
}

void mergeSort(int* A, int p, int r, int* temp)
{
	if (p < r) {
		int q = (p + r) / 2;
		mergeSort(A, p, q, temp);
		mergeSort(A, q + 1, r, temp);
		merge(A, p, q, r, temp);
	}
	return;
}
int main(void)
{
	int n, i;
	int* temp, * A;

	scanf("%d", &n);
	if (n <= 0) return 0;
	A = (int*)malloc(sizeof(int) * n);
	temp = (int*)malloc(sizeof(int) * n);
	if (!A || !temp) return 0;

	for (i = 0; i < n; i++) {
		A[i] = rand() % 100000;
		printf("%d ", A[i]);
	}
	printf("\n\nÁ¤·Ä ÈÄ\n");

	mergeSort(A, 0, n-1, temp);

	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	free(A);
	free(temp);
	return 0;
}