#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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

int minDiff(int* N, int n, int diff, int k)
{
	int d;

	if (k > (n - 1) / 2)
		return diff;

	else {
		int sub = N[n - k - 1] - N[k];
		if (diff > 0)                         // s1 > s2
			d = minDiff(N, n, diff - sub, k + 1);
		else if (diff <= 0)                    // s1 < s2
			d = minDiff(N, n, diff + sub, k + 1);
	}
	return d;
}

void printData(int* N, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d\t", N[i]);
	printf("\n");
	return;
}

int main(void)
{
	int n, i;
	int diff;           
	int* N;

	scanf("%d", &n); 
	if (n < 1 || n % 2 != 0) return 0;
	N = (int*)malloc(sizeof(int) * n);
	if (!N) return 0;
	for (i = 0; i < n; i++) 
		scanf("%d", &N[i]);

	quickSort(N, 0, n - 1);
	printData(N, n);

	diff = N[0] + N[n - 1] - N[1] - N[n - 2];

	printf("%d\n", abs(minDiff(N, n, diff, 2)));

	free(N);
	return 0;
}