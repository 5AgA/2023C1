#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void saveArray(int arr[])
{
	printf("Enter five numbers: ");
	for (int i = 0; i < 5; i++)
		scanf("%d", &arr[i]);
}
void reverseArray(int arr[])
{
	for (int i = 4; i >= 0; i--)
		printf("%d ", arr[i]);
}
int main(void)
{
	int arr[5];
	saveArray(arr);
	reverseArray(arr);
}