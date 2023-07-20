// bubble
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Student{
	int id;
	int korean, english, math;
} student;

void bubbleSortDescendingByKorean(student* A, int n)
{
	int i, j;
	student tmp;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (A[j].korean < A[j + 1].korean)
			{
				tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
			}
}

void bubbleSortAscendingById(student* A, int n)
{
	int i, j;
	student tmp;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (A[j].id > A[j + 1].id)
			{
				tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
			}
}

int main(void)
{
	int n, i;
	student* A;

	scanf("%d", &n);
	if (n <= 0) return 0;

	A = (student*)malloc(sizeof(student) * n);
	if (!A) return 0;

	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		A[i].id = i + 1;
		A[i].korean = rand() % 101;
		A[i].english = rand() % 101;
		A[i].math = rand() % 101;
	}

	for (i = 0; i < n; i++)
		printf("%d\t%d\t%d\t%d\n", A[i].id, A[i].korean, A[i].english, A[i].math);

	bubbleSortDescendingByKorean(A, n);
	printf("\nBubble Sort\n");
	for (i = 0; i < n; i++)
		printf("%d\t%d\t%d\t%d\n", A[i].id, A[i].korean, A[i].english, A[i].math);

	bubbleSortAscendingById(A, n);
	printf("\nOriginal\n");
	for (i = 0; i < n; i++)
		printf("%d\t%d\t%d\t%d\n", A[i].id, A[i].korean, A[i].english, A[i].math);

	return 0;
}