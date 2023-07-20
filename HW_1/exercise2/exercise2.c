#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int isPrime(int num)
{
	int prime = 1;
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			prime = 0;
			break;
		}
	}
	return prime;
}
int main(void)
{
	for (int i = 2; i < 30; i++)
	{
		if (isPrime(i))
		{
			if (i > 2)
				printf(", ");
			printf("%d", i);
		}
	}

	return 0;
}