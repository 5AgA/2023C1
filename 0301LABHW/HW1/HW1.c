// 4���� �̱� - �ߺ� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int n, int bucket[], int m, int toPick) {
	int lastIndex;

	if (toPick == 0) {
		for (int i = 0; i < m; i++) {
			printf("%d ", bucket[i]);
		}
		printf("\n");
		return;
	}
	lastIndex = m - toPick;

	for (int i = 0; i < n; i++) {
		bucket[lastIndex] = i;
		pick(n, bucket, m, toPick - 1);
	}

}
int main(void) {
	int* bucket;
	int m;

	scanf("%d", &m);
	if (m <= 0) return;
	bucket = (int*)malloc(sizeof(int) * m);
	if (!bucket) {
		printf("�޸𸮸� �Ҵ��� �� �����ϴ�.");
		return;
	}

	pick(4, bucket, m, m);

	free(bucket);
	return 0;
}