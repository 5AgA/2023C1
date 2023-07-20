#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int total(int n)
{
	if (n == 0)
		return 0;
	else
		return n + total(n - 1);
}

int main(void)
{
	int num, sum;

	while (1)
	{
		printf("Input a number(-1 for exit): ");
		scanf("%d", &num);
		if (num == -1)
			break;
		else
		{
			sum = total(num);
			printf("1부터 %d까지의 합은 %d\n", num, sum);
		}
	}
}
