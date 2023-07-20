#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n = 0, value = 1;

	printf("Enter a number: ");
	scanf("%d", &n);

	while (n > 0)
	{
		n--;
		value *= 2;
	}

	printf("%d\n", value);

	return 0;
}