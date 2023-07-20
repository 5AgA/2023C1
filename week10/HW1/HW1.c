// quickSort
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

void quickSort(int* A, int p, int r, int key)
{
	if (p < r) {
		int q = partition(A, p, r);
		if (key == q)
			return;
		else if (key < q)
			quickSort(A, p, q - 1, key);
		else if (key > q)
			quickSort(A, q + 1, r, r + 1 - key);
	}
}

int main(void)
{
	int* A;
	int n, key;

	printf("Enter the number of numbers: ");
	scanf("%d", &n);
	printf("몇 번째로 작은 수: ");
	scanf("%d", &key);
	if (n <= 0) return 0;
	A = (int*)malloc(sizeof(int) * n);
	if (!A) return 0;

	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		A[i] = rand() % 101;
		printf("%d ", A[i]);
	}

	quickSort(A, 0, n - 1, key);

	printf("\n%d번째 작은 수는 %d\n", key, A[key-1]);

	free(A);
	return 0;
}