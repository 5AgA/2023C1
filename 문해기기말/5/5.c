#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int n, int* B, int m, int k, int l, int* cnt)
{
	int i, lastIndex = m - k - 1, smallest, e = 0;

	for (i = 0; i < lastIndex + 1; i++)
		if (B[i] % 2 == 0) e++;

	if ((i - e) + l > m) return;		     // i - e: �汝鶺� 偃熱

	if (k == 0) {
		/*for (i = 0; i < m; i++)
			printf("%d ", N[B[i]]);
		printf("\t礎熱曖 偃熱: %d\n", e);*/
		*cnt += 1;
		return;
	}

	if (k == m) smallest = 1;
	else smallest = B[lastIndex] + 1;

	for (i = smallest; i <= n; i++) {
		B[lastIndex + 1] = i;
		pick(n, B, m, k - 1, l, cnt);
	}
	return;
}


int main(void)
{
	int n, m, l, i, cnt = 0;
	int*b;

	scanf("%d %d %d", &n, &m, &l);

	b = (int*)malloc(sizeof(int) * m);
	if (!b) return 0;

	pick(n, b, m, m, l, &cnt);
	printf("%d\n", cnt);

	free(b);
	return 0;
}