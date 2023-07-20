#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	int num, i, n;
	int rslt[8];

	scanf("%d", &n);
	num = n * 9;
	for (i = 0; num != 0; i++) {
		rslt[i] = num % 10;
		num /= 10;
	}
	for (int j = i - 1; j >= 0; j--) {
		printf("%d ", rslt[j]);
	}
	printf("\n");
	return 0;
}