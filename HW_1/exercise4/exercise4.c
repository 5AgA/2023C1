#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int arr[5], key;
	printf("Enter 5개의 정수: ");
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("Enter a key: ");
	scanf("%d", &key);
	for (int i = 0; i < 5; i++)
	{
		if (arr[i] == key)
		{
			printf("%d번째에 있다\n", i + 1);
			break;
		}
		if (i == 4)
			printf("없다\n");
	}
}