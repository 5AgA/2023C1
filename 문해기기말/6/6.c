#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getAlphaNum(int* alpha, char a)
{
	for (int i = 0; i < 5; i++)
		if ('A' + i == a)
			return alpha[i];
	return 0;
}

int findBigNum(int* alpha, char* s1, char* s2, int k) 
{
	int i, j, lastIndex, max = 0;
	int N1 = 0, N2 = 0;

	if (k == 0) {
		/*for (i = 0; i < 5; i++) {
			printf("%c : %d\t", 65 + i, alpha[i]);
		}
		printf("\n");*/
		for (i = 0; i < strlen(s1); i++) 
			N1 = N1 * 10 + getAlphaNum(alpha, s1[i]);
		for (i = 0; i < strlen(s2); i++) 
			N2 = N2 * 10 + getAlphaNum(alpha, s2[i]);
		//printf("%d + %d = %d\n", N1, N2, N1 + N2);
		return N1 + N2;
	}

	lastIndex = 5 - k - 1;

	for (i = 1; i < 6; i++) {
		int flag = 0;
		for (j = 0; j < lastIndex + 1; j++) 
			if (alpha[j] == i) {
				flag = 1;
				break;
			}
		if (flag == 1) continue;

		int sum;
		alpha[lastIndex + 1] = i;
		sum = findBigNum(alpha, s1, s2, k - 1);
		if (sum > max)
			max = sum;
	}
	return max;
}

int main(void)
{
	char str1[9] = { 0 }, str2[9] = { 0 };
	int alpha[5] = { 0 };

	scanf("%s", str1);
	scanf("%s", str2);

	printf("%d\n", findBigNum(alpha, str1, str2, 5));

	return 0;
}