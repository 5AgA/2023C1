#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	char ladder[100][100];
	int row, col, start;

	scanf("%d %d", &row, &col);
	scanf("%d", &start);
	for (int i = 0; i < col; i++)
		scanf("%s", ladder[i]);
	for (int i = 0; i < col; i++) {
		if (ladder[i][start] == '1') {
			start++;
			continue;
		}
		if (ladder[i][start - 1] == '1' && start != 0) {
			start--;
			continue;
		}
	}
	printf("%d", start);

	return 0;
}