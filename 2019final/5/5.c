// 문해기 난이도 체크
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
	int num, comp;
}std;

void checkLevel(int** L, int n, int m, std* c)
{
	int i, j, min = m;

	for (i = 0; i < n; i++) 
		for (j = 0; j < m; j++) 
			if (L[j][i] == 1)
				c[i].comp += 1;
	return;
}

int partition(std* A, int p, int r)
{
	int i = p - 1, j;
	std t;

	for (j = p; j < r; j++) {
		if (A[j].comp <= A[r].comp) {
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

int main(void)
{
	int n, m, i, j;    // n: 문제수, m: 학생수
	int** level;
	std* check;

	scanf("%d %d", &n, &m);

	check = (std*)malloc(sizeof(std) * n);
	level = (int**)malloc(sizeof(int*) * m);
	if (!level || !check) return 0;
	for (i = 0; i < m; i++) {
		level[i] = (int*)malloc(sizeof(int) * n);
		if (!level[i]) return 0;
	}
	for (i = 0; i < m; i++) {
		check[i].num = i + 1;
		check[i].comp = 0;
	}

	for (i = 0; i < m; i++) 
		for (j = 0; j < n; j++)
			scanf("%d", &level[i][j]);
	printf("\n");

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) 
			printf("%d ", level[i][j]);
		printf("\n");
	}

	checkLevel(level, n, m, check);
	quickSort(check, 0, n - 1);

	for (i = 0; i < n; i++) 
		printf("%d", check[i].num);
	printf("\n");

	for (i = 0; i < m; i++)
		free(level[i]);
	free(level);
	free(check);
	return 0;
}
/* 
1 0 0 0
1 0 1 0
1 0 1 0
1 0 0 1
1 1 1 1

1 1 0 0 0
1 0 1 0 0
1 1 1 1 0
1 1 0 1 0
1 0 0 1 0
1 0 1 1 1
*/
