// Insertion Sort ���� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // rand, srand
#include <time.h> // time
void insertionSort(int* arr, int n) {
	int tmp, i, j, k;

	for (i = 1; i < n; i++) 
	{
		for (j = 0; j < i; j++) 
			if (arr[j] > arr[i]) break;

		tmp = arr[i];
		for (k = i; k > j; k--)
			arr[k] = arr[k - 1];
		arr[j] = tmp;
	
	}

	printf("���ĵ� ��:\n");
	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\n");

	return;
}
int main(void) {
	int n;
	int* arr;

	printf("Enter a number: ");
	scanf("%d", &n);
	if (n <= 0) return 0;
	arr = (int*)malloc(sizeof(int) * n);
	if (!arr) {
		printf("�޸𸮸� �Ҵ��� �� ����");
		exit(1);
	}

	srand(time(NULL));
	for (int i = 0; i < n; i++) arr[i] = rand() % 1000;
	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\n");

	insertionSort(arr, n);

	free(arr);
	return 0;
}