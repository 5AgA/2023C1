// quickSort
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Student {
	int id, english, math, korean;
}std;

int partition(std* A, int p, int r, int sub)
{
	int i = p - 1, j;
	std t;
	
	switch (sub) {
	case 1:
		for (j = p; j < r; j++) {
			if (A[j].korean > A[r].korean) {
				i++;
				t = A[j];
				A[j] = A[i];
				A[i] = t;
			}
		} break;
	case 2:
		for (j = p; j < r; j++) {
			if (A[j].math > A[r].math) {
				i++;
				t = A[j];
				A[j] = A[i];
				A[i] = t;
			}
		} break;
	case 3:
		for (j = p; j < r; j++) {
			if (A[j].english > A[r].english) {
				i++;
				t = A[j];
				A[j] = A[i];
				A[i] = t;
			}
		} break;
	case 4:
		for (j = p; j < r; j++) {
			if (A[j].id < A[r].id) {
				i++;
				t = A[j];
				A[j] = A[i];
				A[i] = t;
			}
		} break;
	}

	t = A[r];
	A[r] = A[i + 1];
	A[i + 1] = t;

	return i + 1;
}

void quickSort(std* A, int p, int r, int sub)
{
	if (p < r) {
		int q = partition(A, p, r, sub);
		quickSort(A, p, q - 1, sub);
		quickSort(A, q + 1, r, sub);
	}
}

void printData(std* student, int n)
{
	for (int i = 0; i < n; i++) {
		printf("학번 : %d\t영어 : %d\t수학 : %d\t국어 : %d\n", student[i].id, student[i].english, student[i].math, student[i].korean);
	}
	printf("\n");
	return;
}
int main(void)
{
	std* student;
	int n, i, s;

	printf("학생 수를 입력하세요 : ");
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
	printData(student, n);
	printf("정렬 기준 선택(1:국어, 2:수학, 3:영어, 4:id(오름차순), 0:끝내기) : ");
	scanf("%d", &s);

	do {
		quickSort(student, 0, n - 1, s);
		printData(student, n);
		printf("정렬 기준 선택(1:국어, 2:수학, 3:영어, 4:id(오름차순), 0:끝내기) : ");
		scanf("%d", &s);
	} while (s != 0);

	free(student);
	return 0;
}