#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int arithmetical_progression(int* number, int n)
{
	int diff, sum = 0;

	if (n == 1)
		return 1;
	diff = number[1] - number[0];
	for (int i = 0; i < n - 1; i++)
	{
		if (number[i + 1] - number[i] != diff)
			return -1;
		else
			sum += number[i];
	}
	sum += number[n - 1];
	return sum;
}

int switchAandB(int* A, int n, int* B, int m, int* bucket, int l, int k, int* C)
{
	int i, lastIndex, smallest, ret = -1, rslt = -1;

	if (k == 0)
	{
		for (i = 0; i < m; i++) 
			C[i] = B[i];
		for (i = 0; i < n; i++)
			C[bucket[i]] = A[i];
		//for (i = 0; i < m; i++) printf("%d ", C[i]); 
		ret = arithmetical_progression(C, m);
		//printf("---- %d\n", ret);
		if (ret != -1) 
			return ret;
		
		return ret;
	}

	lastIndex = l - k - 1;
	smallest = 0;
	for (i = smallest; i < m; i++) {
		int j = 0; int flag = 0; 
		for (j = 0; j <= lastIndex; j++)
			if (bucket[j] == i) flag = 1;
		if (flag == 1) continue;
		bucket[lastIndex + 1] = i;
		ret = switchAandB(A, n, B, m, bucket, l, k - 1, C);
		if (ret != -1)
			rslt = ret;
	}
	return rslt;
}

int main(void)
{
	int Na, Nb, i;
	int* A, * B, *C, *bucket;

	scanf("%d", &Na);
	if (Na <= 0) return 0;
	A = (int*)malloc(sizeof(int) * Na);
	bucket = (int*)malloc(sizeof(int) * Na);
	if (!A || !bucket) return 0;
	for (i = 0; i < Na; i++) scanf("%d", &A[i]);

	scanf("%d", &Nb);
	if (Nb <= 0) return 0;
	B = (int*)malloc(sizeof(int) * Nb);
	C = (int*)malloc(sizeof(int) * Nb);
	if (!B || !C) return 0;
	for (i = 0; i < Nb; i++) scanf("%d", &B[i]);

	printf("%d\n", switchAandB(A, Na, B, Nb, bucket, Na, Na, C));

	free(A);
	free(B);
	free(C);
	free(bucket);
	return 0;
}