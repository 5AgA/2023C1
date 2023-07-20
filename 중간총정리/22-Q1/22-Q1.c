// 이진수 회문 검사 - 뒤집어 봐서 두 배열이 같은지 판단
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int n, k;
	char num1[64];
	char num2[64];
	int i = 0;
	int str_len;

	scanf("%d %d", &n, &k);  // n은 정수, k는 기수

	memset(num1, 0x00, 64);
	memset(num2, 0x00, 64);

	while (n != 0) {
		if (k == 16 && n % k >= 10)
			num1[i] = (n % k - 10) + 'A';
		else
			num1[i] = n % k + '0';
		n /= k;
		i++;
	}
	str_len = i;
	num1[i] = "\0";
	num2[i] = "\0";

	for (i = 0; i < str_len; i++)
		num2[i] = num1[str_len - i - 1];

	printf("%s\n", num1);
	printf("%s\n", num2);

	printf("%d\n", !strcmp(num1, num2));

	return 0;
}