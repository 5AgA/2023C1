#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int arithmetical_progression(int* number, int n) 
{
	int diff;

	if (n == 1)
		return 1;
	diff = number[1] - number[0];
	for (int i = 0; i < n - 1; i++)
		if (number[i + 1] - number[i] != diff)
			return 0;
	return 1;
}

int main(void)
{
	int n;
	int* A;

	scanf("%d", &n);
	if (n <= 0) return 0;
	A = (int*)malloc(sizeof(int) * n);
	if (!A) return 0;

	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);

	printf("%d\n", arithmetical_progression(A, n));

	return 0;
}