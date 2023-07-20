#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int search_binary(int* list, int p, int r, int key) 
{
	if (p <= r) {
		int q = (p + r) / 2;

		if (key == list[q]) return q;
		else if (key < list[q])
			return search_binary(list, 0, q - 1, key);
		else if (key > list[q])
			return search_binary(list, q + 1, r, key);
	}
	return -1;
}

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
	int m, n, i, isSell = 0;
	int* M, * N;

	scanf("%d", &m);
	M = (int*)malloc(sizeof(int) * m);
	if (!M) return 0;
	for (i = 0; i < m; i++)
		scanf("%d", &M[i]);

	scanf("%d", &n);
	N = (int*)malloc(sizeof(int) * n);
	if (!N) return 0;
	for (i = 0; i < n; i++)
		scanf("%d", &N[i]);

	quickSort(M, 0, m - 1);

	for (i = 0; i < n; i++) {
		if (search_binary(M, 0, m - 1, N[i]) != -1)
			isSell++;
	}

	printf("%d\n", isSell);

	free(M);
	free(N);
	return 0;
}
//  5 8 3 7 9 2 3 5 9 7
