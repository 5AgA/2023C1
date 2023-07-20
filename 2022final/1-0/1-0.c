//자리수 구하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int getLength(int num)
{
	if (num == 0) return 0;
	else return 1 + getLength(num / 10);
}

int main(void)
{
	char num[100];
	int i, n;

	scanf("%s", num);
	for (i = 0; num[i] != '\0'; i++);
	num[i] = '\0';
	n = atoi(num);

	printf("%d\n", getLength(n));

	return 0;
}