#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int calDigits(int n) 
{
	int count = 0;
	while (n != 0) {
		n /= 10;
		count++;
	}
	return count;
}

int main(void)
{
	int n, k, cnt = 0;
	int* A;

	scanf("%d", &n);
	scanf("%d", &k);

	if (n <= 0) return 0;
	A = (int*)malloc(sizeof(int) * n);
	if (!A) return 0;

	
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);

	for (int i = 0; i < n; i++)
	{
		if (calDigits(A[i]) == 1 && A[i] == k)
			cnt++;
		else
			while (A[i] != 0)
			{
				int rem = A[i] % 10;
				if (rem == k)
					cnt++;
				A[i] /= 10;
			}
	}

	printf("%d\n", cnt);
	free(A);
	return 0;
}