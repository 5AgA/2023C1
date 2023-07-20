#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int partition(char* A, int p, int r)
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

void quickSort(char* A, int p, int r)
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
	char str[500000] = { 0 };
	int i, s;

	scanf("%s", str);

	quickSort(str, 0, strlen(str) - 1);

	for (s = 0; s < strlen(str); s++)
		if (str[s] >= 'A' && str[s] <= 'Z') break;

	for (i = s; i < strlen(str); i++)
		printf("%c", str[i]);
	for (i = 0; i < s; i++)
		printf("%c", str[i]);
	printf("\n");

	return 0;
}
// K1Ka5Cb75