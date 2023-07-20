// quickSort
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Student {
	int id, english, math, korean;
}std;

int partition(std* A, int p, int r)
{
	int i = p - 1, j;
	std t;

	for (j = p; j < r; j++) {
		if (A[j].korean > A[r].korean) {
			i++;
			t = A[j];
			A[j] = A[i];
			A[i] = t;
		}
	}

	t = A[r];
	A[r] = A[i + 1];
	A[i + 1] = t;

	return i + 1;
}

void quickSort(std* A, int p, int r)
{
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

void printData(std* student, int n)
{
	for (int i = 0; i < n; i++) {
		printf("%d\t%d\t%d\t%d\n", student[i].id, student[i].korean, student[i].english, student[i].math);
	}
	return;
}

int main(void)
{
	std* student;
	int n, i;

	scanf("%d", &n);
	if (n <= 0) return 0;
	student = (std*)malloc(sizeof(std) * n);
	if (!student) return 0;

	srand(time(NULL));
	for (i = 0; i < n; i++) {
		student[i].id = i + 1;
		student[i].korean = rand() % 101;
		student[i].english = rand() % 101;
		student[i].math = rand() % 101;
	}

	printf("ID\t국어\t영어\t수학\n");
	printData(student, n);

	quickSort(student, 0, n - 1);
	printf("\n정렬 후\n");
	printData(student, n);

	free(student);
	return 0;
}