#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void input(int arr1[], int arr2[])
{
	printf("Enter ù��° �迭: ");
	for (int i = 0; i < 5; i++)
		scanf("%d", &arr1[i]);
	printf("Enter �ι�° �迭: ");
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
		printf("�� ���� �迭�� ����\n");
	else
		printf("�� ���� �迭�� �ٸ���\n");
}