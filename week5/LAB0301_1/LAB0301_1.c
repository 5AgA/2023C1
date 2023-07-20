#include <stdio.h>
void pick(char* balls, int n, int *picked, int m, int toPick) {
	int LastIndex, smallest, i;

	if (toPick == 0) {
		for (i = 0; i < n; i++)
			printf("%c", balls[picked[i]]);
		printf("\n");
		return;
	}

	LastIndex = m - toPick - 1;
	if (toPick == m)
		smallest = 0;
	else
		smallest = picked[LastIndex] + 1;

	for (i = smallest; i < n; i++) {
		picked[LastIndex + 1] = i;
		pick(balls, n, picked, m, toPick - 1);
	}
}
int main(void) {
	char balls[] = "ABCDEFG";
	int picked[3];

	pick(balls, 7, picked, 3, 3);

	return 0;
}