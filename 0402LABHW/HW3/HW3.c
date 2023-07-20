// bubble
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Student {
	int id;
	int korean, english, math;
} student;

void printInfo(student* A, int n)
{
	for (int i = 0; i < n; i++)
		printf("학번 : %d\t국어 : %d\t영어 : %d\t수학 : %d\n", A[i].id, A[i].korean, A[i].english, A[i].math);
	printf("\n");
}

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

void bubbleSortDescendingByEnglish(student* A, int n)
{
	int i, j;
	student tmp;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (A[j].english < A[j + 1].english)
			{
				tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
			}
}

void bubbleSortDescendingByMath(student* A, int n)
{
	int i, j;
	student tmp;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (A[j].math < A[j + 1].math)
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
	int n, i, s;
	student* A;

	printf("학생 수를 입력하세요 : ");
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

	printInfo(A, n);
	do {
		printf("정렬 기준 선택(1:국어, 2:수학, 3:영어, 4:id(오름차순), 0:끝내기) : ");
		scanf("%d", &s);
		
		switch (s) {
			case 1:
				bubbleSortDescendingByKorean(A, n);
				printInfo(A, n);
				break;
			case 2:
				bubbleSortDescendingByMath(A, n);
				printInfo(A, n);
				break;
			case 3:
				bubbleSortDescendingByEnglish(A, n);
				printInfo(A, n);
				break;
			case 4:
				bubbleSortAscendingById(A, n);
				printInfo(A, n);
				break;
			case 0:
				break;
			default:
				printf("다시 입력하세용~^^*\n");
				getchar();
				break;
		}

	} while (s != 0);

	free(A);
	return 0;
}