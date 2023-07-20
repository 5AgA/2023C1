// 연기상 - 순열
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(char* actors[], int n, int* bucket, int m, int k) {
	int lastIndex, smallest;

	if (k == 0) {
		for (int i = 0; i < m; i++) 
			printf("\t%s", actors[bucket[i]]);
		printf("\n");
		return;
	}

	lastIndex = m - k - 1;
	smallest = 0;
	for (int i = smallest; i < n; i++) {
		int flag = 0;
		for (int j = 0; j <= lastIndex; j++)
			if (bucket[j] == i) flag = 1;
		if (flag == 1) continue;
		bucket[lastIndex + 1] = i;
		pick(actors, n, bucket, m, k - 1);
	}
}

int main(void) {
	char* actors[] = { "공유", "김수현", 
		"송중기", "지성", "현빈" };
	int* b;
	int m;

	printf("상의 종류는? ");
	scanf("%d", &m);
	if (m <= 0) return 0;
	b = (int*)malloc(sizeof(int) * m);
	if (!b) {
		printf("메모리를 할당할 수 없습니다.");
		return 0;
	}

	printf("\t상1\t상2\n");
	pick(actors, 5, b, m, m);

	free(b);
	return 0;
}