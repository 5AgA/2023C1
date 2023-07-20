// 세뱃돈 - 중복조합
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int* item, int n, int* bucket, int m, int k, int give) {
	int lastIndex, smallest, leng, original;
	original = give;
	leng = m - k;
	if (give == 0) {
		for (int i = 0; i < leng; i++)
			printf("%d ", bucket[i]);
		printf("\n");
		return;
	}

	lastIndex = m - k - 1;
	for (int i = 0; i < n; i++)
		if (give >= item[i] && give == original) {
			smallest = i;
			bucket[lastIndex + 1] = item[smallest];
			if (lastIndex >= 0 && bucket[lastIndex] < bucket[lastIndex + 1])
				return;
			pick(item, n, bucket, m, k - 1, give - item[smallest]);
		}
}

int main(void) {
	int item[3] = { 1000, 5000, 10000 };
	int* bucket;
	int give, bucketSize;

	scanf("%d", &give);
	if (give <= 0) return 0;
	bucketSize = give / 1000;
	bucket = (int*)malloc(sizeof(int) * bucketSize);
	if (!bucket) {
		printf("메모리를 할당할 수 없습니다.");
		return 0;
	}

	pick(item, 3, bucket, bucketSize, bucketSize, give);

	free(bucket);
	return 0;
}