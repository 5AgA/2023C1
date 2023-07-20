#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char alpha[100];
	char ch;
	int cnt = 0;

	printf("Enter a String: ");
	scanf("%s", alpha);
	printf("Enter a character: ");
	scanf(" %c", &ch);

	for (int i = 0; alpha[i] != '\0'; i++)
	{
		if (alpha[i] == ch)
			cnt++;
	}

	printf("'%c' is appeared %d times\n", ch, cnt);
}