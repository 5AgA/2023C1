//6을 1, 2, 3의 합으로
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int pick(int itemSize, int* picked, int pickedSize, int k, int n)
{
	int smallest, lastIndex, i;

	if (k == 0 || n == 0) {
		/*for (i = 0; i < pickedSize - k; i++) {
			printf("%d ", picked[i]);
			if (i != pickedSize - k - 1) printf("+ ");
		}
		printf("\n");*/
		return 1;
	}

	lastIndex = pickedSize - k - 1;
	if (pickedSize == k) smallest = 1;
	else smallest = picked[lastIndex];

	int cnt = 0;
	for (i = smallest; i < itemSize + 1; i++) {
		int ret = 0;
		picked[lastIndex + 1] = i;
		n -= i;
		if (n < 0) break;
		cnt += pick(itemSize, picked, pickedSize, k - 1, n);
		n += i;
	}
	return cnt;
}

int main(void)
{
	int* picked;
	int item = 3, n;

	scanf("%d", &n);
	picked = (int*)malloc(sizeof(int) * n);
	if (!picked) return 0;

	printf("%d\n", pick(item, picked, n, n, n));

	free(picked);
	return 0;
}