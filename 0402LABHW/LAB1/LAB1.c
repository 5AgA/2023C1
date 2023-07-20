//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // rand, srand
#include <time.h> // time
int main(void) {
	int n;
	int* arr;

	printf("Enter a number: ");
	scanf("%d", &n);
	if (n <= 0) return 0;
	arr = (int*)malloc(sizeof(int) * n);
	if (!arr) {
		printf("메모리를 할당할 수 없음");
		exit(1);
	}

	srand(time(NULL));
	for (int i = 0; i < n; i++) arr[i] = rand() % 1000;
	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\n");

	return 0;
}