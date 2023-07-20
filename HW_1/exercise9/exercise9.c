#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void input(int arr1[], int arr2[])
{
	printf("Enter 첫번째 배열: ");
	for (int i = 0; i < 5; i++)
		scanf("%d", &arr1[i]);
	printf("Enter 두번째 배열: ");
	for (int i = 0; i < 5; i++)
		scanf("%d", &arr2[i]);
}
int compare(int arr1[], int arr2[])
{
	for (int i = 0; i < 5; i++)
		if (arr1[i] != arr2[i])
			return 0;
	return 1;
}
int main(void)
{
	int arr1[5], arr2[5];
	input(arr1, arr2);
	if (compare(arr1, arr2))
		printf("두 개의 배열은 같다\n");
	else
		printf("두 개의 배열은 다르다\n");
}