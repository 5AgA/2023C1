// 수식나열 - 연산자: 중복 순열
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int itemSize, int* bucket, int bucketSize, int k) {
	int lastIndex, smallest, item, total = 0;

	if (k == 0) {
		for (int i = 0; i < bucketSize; i++) {
			if (bucket[i] == 0) {
				printf("+ %d ", i + 1);
				total += (i + 1);
			}
			else {
				printf("- %d ", i + 1);
				total -= (i + 1);
			}
		}
		printf("= %d\n", total);
		return;
	}
	lastIndex = bucketSize - k - 1;

	smallest = 0;

	for (item = smallest; item < itemSize; item++) {
		bucket[lastIndex + 1] = item;
		pick(itemSize, bucket, bucketSize, k - 1);
	}
}
int main(void) {
	int* bucket;
	int num;

	scanf("%d", &num);
	if (num <= 0) return 0;
	bucket = (int*)malloc(sizeof(int) * num);

	if (!bucket) {
		printf("메모리를 할당할 수 없습니다.");
		return 0;
	}

	pick(2, bucket, num, num);

	free(bucket);

	return 0;
}