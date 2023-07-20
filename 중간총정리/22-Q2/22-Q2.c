// 중복 순열 (무엇을 뽑아야 하는지부터 생각 - -1, 0, 1)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int arithmetical_progression(int* number, int n) {
	int diff;
	
	if (n == 1)
		return 1;
	diff = number[1] - number[0];
	for (int i = 0; i < n - 1; i++)
		if (number[i + 1] - number[i] != diff)
			return 0;
	return 1;
}
int pick(int* item, int n, int* picked, int m, int k, int *num1, int *num2) {
	int lastIndex;
	int op_count = 0;

	if (k == 0) {
		for (int i = 0; i < m; i++) {
			num2[i] = num1[i] + item[picked[i]];
			if (item[picked[i]] != 0)
				op_count++;
		}
		if (arithmetical_progression(num2, m) == 1) {
			for (int i = 0; i < m; i++)             // 등차수열이면 출력
				//printf("%d ", item[picked[i]]);
				printf("%d ", num2[i]);
			printf(" %d\n", op_count);
			return op_count;                           // 등차수열이면 출력
		}
		return m + 1;                                  // 아니면 m + 1 출력
	}
	
	lastIndex = m - k - 1;

	op_count = m + 1;

	for (int i = 0; i < n; i++) {
		int ret;                                       // 이게 포인트
		picked[lastIndex + 1] = i;
		ret = pick(item, n, picked, m, k - 1, num1, num2);   // 여기서 최솟값 검토
		if (op_count > ret)
			op_count = ret;
	}
	return op_count;                            // 최솟값 반환
}
int main(void) {
	int n, ret; // n개의 숫자
	int* A, *B, * picked;
	int item[] = { -1, 0, 1 };  // n개만큼 뽑아야함


	scanf("%d", &n);

	if (n <= 0) return 0;
	A = (int*)malloc(sizeof(int) * n);
	B = (int*)malloc(sizeof(int) * n);
	picked = (int*)malloc(sizeof(int) * n);
	if (!A || !B || !picked) {
		printf("MEMORY ALLOCATE ERROR");
		return 0;
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	ret = pick(item, 3, picked, n, n, A, B);
	
	printf("%d\n", ret == (n + 1) ? -1 : ret);

	free(A);
	free(B);
	free(picked);
	return 0;
}