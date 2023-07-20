// Selection 선택 정렬
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student
{
	int id;
	int korean, english, math;
};

void printInfo(struct Student* s, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d\t%d\t%d\t%d\n", (i + 1), s[i].korean, s[i].english, s[i].math);
	}
}

void selectionSort(struct Student* s, int size) {
	int i, j, maxIdx;
	struct Student max;
	struct Student tmp;

	for (i = 0; i < size - 1; i++) {

		max = s[0];
		maxIdx = 0;
		for (j = 1; j < size - i; j++)
			if (s[j].korean > max.korean) {
				max = s[j];
				maxIdx = j;
			}
		tmp = s[size - i - 1];
		s[size - i - 1] = s[maxIdx];
		s[maxIdx] = tmp;
	}
}
int main(void) {
	int n, i;
	struct Student* s;

	scanf("%d", &n);
	if (n <= 0) return 0;

	s = (struct Student*)malloc(sizeof(struct Student) * n);
	if (!s) {
		printf("memmory allocate error!!");
		return 0;
	}

	srand(time(NULL));

	for (i = 0; i < n; i++) {
		s[i].id = i + 1;
		s[i].korean = rand() % 101;
		s[i].english = rand() % 101;
		s[i].math = rand() % 101;
	}

	for (i = 0; i < n; i++) 
		printf("%d\t%d\t%d\t%d\n", s[i].id, s[i].korean, s[i].english, s[i].math);
	printf("\n");

	printf("\n---------정렬 후---------\n");

	selectionSort(s, n);
	for (i = n - 1; i >= 0; i--) 
		printf("%d\t%d\t%d\t%d\n", s[i].id, s[i].korean, s[i].english, s[i].math);
	printf("\n");

	free(s);
	return 0;
}