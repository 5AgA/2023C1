// H 함수 - memo X
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int H(int n)
{
	int sum = 0;

	if (n == 0 || n == 1)
		return 1;
	else {
		for (int i = n - 1; i >= 0; i--)
			sum += H(i) * H(n - i - 1);
		return sum;
	}
}

int main(void)
{
	int n;

	printf("0보다 큰 정수: ");
	scanf("%d", &n);
	printf("결과는 %d\n", H(n));

	return 0;
}