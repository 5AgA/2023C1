#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int pick(int itemSize, int* picked, int size, int k, int * A)
{
	int i, lastIndex, rslt = 0;

	if (k == 0) {
		for (i = 0; i < size; i++) {
			switch (picked[i]) {
			case 0:
				rslt += A[i];
				break;
			case 1:
				rslt -= A[i];
				break;
			case 2 :
				rslt *= A[i];
				break;
			}
		}
		
		return rslt;
	}

	lastIndex = size - k - 1;
	rslt = -1;

	for (i = 0; i < itemSize; i++) {
		int ret;
		picked[lastIndex + 1] = i;
		ret = pick(itemSize, picked, size, k - 1, A);
		if (ret > rslt)
			rslt = ret;
	}
	return rslt;
}

int main(void)
{
	int* A, *picked;
	int n, i;
	// char item[3] = {'+', '-', 'x'};

	scanf("%d", &n);
	if (n <= 0) return 0;
	A = (int*)malloc(sizeof(int) * n);
	picked = (int*)malloc(sizeof(int) * n);
	if (!A || !picked) return 0;

	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);

	printf("%d\n", pick(3, picked, n, n, A));

	free(A);
	free(picked);
	return 0;
}