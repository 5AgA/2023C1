// 피구
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
	int num, stats;
}std;

int partition(std* A, int p, int r)
{
	int i = p - 1, j;
	std t;

	for (j = p; j < r; j++) {
		if (A[j].stats < A[r].stats) {
			i++;
			t = A[i];
			A[i] = A[j];
			A[j] = t;
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
	return;
}

void printData(std* student, int n)
{
	for (int i = 0; i < n; i++) 
		printf("%d\t%d\n", student[i].num, student[i].stats);
	printf("\n");

	return;
}


int minDiff(std* s, int n, std* s1, std* s2, int m, int d)
{
	for (int i = 1; i < m - 1; i++) {
		int sub = s[n - i - 2].stats - s[i + 1].stats;     // 큰거에서 작은거 뺌
		if (d <= 0) {
			s1[i] = s[n - i - 2]; s2[i] = s[i + 1];
			d += sub;
		}
		else if (d > 0) { // s1이 더 크면
			s2[i] = s[n - i - 2]; s1[i] = s[i + 1];
			d -= sub;
		}
	}
	return d;
}

int main(void)
{
	int n, m, i, d;
	std* N, * N1, * N2;

	scanf("%d", &n);
	if (n < 1 || n % 2 != 0) return 0;
	m = n / 2;
	N = (std*)malloc(sizeof(std) * n);
	N1 = (std*)malloc(sizeof(std) * m);
	N2 = (std*)malloc(sizeof(std) * m);
	if (!N || !N1 || !N2) return 0;
	for (i = 0; i < n; i++) {
		N[i].num = i + 1;
		scanf("%d", &N[i].stats);
	}

	/*printf("입력된 학생들의 능력치:\n");
	printData(N, n);*/
	quickSort(N, 0, n - 1);
	/*printf("오름차순으로 정렬된 학생들의 능력치:\n");
	printData(N, n);*/

	// 배열 분리
	N1[0] = N[0]; N1[m - 1] = N[n - 1]; // 최대와 최소
	N2[0] = N[1]; N2[m - 1] = N[n - 2]; // 그 다음 최대와 최소

	d = (N1[0].stats + N1[m - 1].stats) - (N2[0].stats + N2[m - 1].stats);

	printf("%d\n", abs(minDiff(N, n, N1, N2, m, d)));

	/*printf("\n팀 1:\n");
	printData(N1, m);
	printf("팀 2:\n");
	printData(N2, m);*/

	free(N); free(N1); free(N2);
	return 0;
}