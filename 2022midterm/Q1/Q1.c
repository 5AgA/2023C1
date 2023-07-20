// 진수 회문 체크
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void isPalindrome(char* bin, int s) {
	for (int i = 0; i < s / 2; i++)
		if (bin[i] != bin[s - 1 - i]) {
			printf("0\n");
			return;
		}
	printf("1\n");
	return;
}
int main(void) {
	int n, k, size = 0, num;
	char* bin; 

	scanf_s("%d %d", &n, &k);

	num = n;
	while (num > 0) {
		num /= k;
		size++;
	}
	bin = (char*)malloc(sizeof(char) * size);
	if (!bin) {
		printf("메모리를 할당할 수 없습니다.");
		return 0;
	}

	for (int i = 0; i < size; i++) {
		int rem = n % k;
		if (n == 0 || n == 1) 
			bin[i] = n + 48;
		else {
			if (rem > 9)
				bin[i] = rem + 7 + 48;
			else
				bin[i] = rem + 48;
		}
		n /= k;
	}

	for (int i = size - 1; i >= 0; i--) printf("%c", bin[i]);
	printf("\n");

	isPalindrome(bin, size);

	free(bin);
	return 0;
}
