// 9의 배수 공백 포함 출력하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int calDigits(int n) {                  // 자리수를 세고 그걸 사용해서
	int result = 1;                     // 제일 높은 자릿수를 먼저 출력한다.
	int i;
	while (n != 0) {
		n /= 10;
		result *= 10;
	}
	return result / 10;
}

int main(void) {
	int n;
	int count = 0;
	int nextDigit, tmpNum2;
	int jarisu;
	
	scanf("%d", &n);

	jarisu = calDigits(n * 9);
	tmpNum2 = n * 9;
	do {
		nextDigit = tmpNum2 / jarisu;
		printf("%d ", nextDigit);
		tmpNum2 %= jarisu;
		jarisu /= 10; 
	} while (jarisu != 0);

	return 0;
}