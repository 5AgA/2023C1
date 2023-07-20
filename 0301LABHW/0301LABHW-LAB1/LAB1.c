// °ø»Ì±â - Á¶ÇÕ
#include <stdio.h>
void pick(char item[], int n, char bucket[], int m, int k) {
	int lastIndex, smallest;

	if (k == 0) {
		for (int i = 0; i < m; i++)
			printf("%c ", bucket[i]);
		printf("\n");
		return;
	}
	lastIndex = m - k - 1;
	if (k == m)
		smallest = 0;
	else
		smallest = bucket[lastIndex] - 64;

	for (int i = smallest; i < n; i++) {
		bucket[lastIndex + 1] = item[i];
		pick(item, n, bucket, m, k - 1);
	}
}

int main(void) {
	char balls[7] = "ABCDEFG";
	char bucket[3];

	pick(balls, 7, bucket, 3, 3);

	return 0;
}