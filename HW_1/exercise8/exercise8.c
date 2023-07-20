#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void inputName(char arr[])
{
	printf("* Enter your name: ");
	scanf("%s", arr);
	getchar();
}
void reverseName(char arr[])
{
	int lngth;
	printf("* Reverse: ");
	for (lngth = 0; arr[lngth] != '\0'; lngth++);
	for (int i = lngth - 1; i >= 0; i--)
		printf("%c", arr[i]);
}
int main(void)
{
	char name[20];
	inputName(name);
	reverseName(name);
}