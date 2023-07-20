// (뽑기) 1과 2의 합 - 중복 조합
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int cnt = 0;
void pick(int n, int* picked, int m, int k, int num)
{
	int i, lastIndex, smallest;
	if (k == 0 || num == 0) {
		/*
		for (i = 0; i < m - k; i++) {
			printf("%d", picked[i]);
			if (i != m - k - 1)
				printf(" + ");
		}
		printf("\n");
		*/
		cnt++;
		return;
	}

	lastIndex = m - k - 1;
	if (m == k) smallest = 1;
	else smallest = picked[lastIndex];

	for (i = smallest; i <= n; i++) {
		picked[lastIndex + 1] = i;
		num -= i;
		if (num < 0) return;
		pick(n, picked, m, k - 1, num);
		num += picked[lastIndex + 1];       // num 값 원복
	}
	return;
}

int main(void)
{
	int num;
	int* picked;

	scanf("%d", &num);
	if (num <= 0) return 0;
	picked = (int*)malloc(sizeof(int) * num);
	if (!picked) return 0;

	pick(2, picked, num, num, num);
	printf("%d\n", cnt);

	free(picked);
	return 0;
}