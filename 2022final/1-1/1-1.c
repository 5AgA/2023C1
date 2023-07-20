#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int getLength(int n)
{
	int size = 0, num = n;

	if (n == 0) return 0;
	else {
		while (num != 0) {
			num /= 10;
			size++;
		}
		return size + getLength(n - 1);
	}
}

int main(void) 
{
	int n;

	scanf("%d", &n);

	printf("%d\n", getLength(n));

	return 0;
}