#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int solution(int n) {
	int cnt = 0;
	while (n > 0) {
		n /= 10;
		cnt++;
	}
	return cnt;
}
int main(void) {
	int turn, num = 1, cnt = 0, mul3, rslt = 0, l;

	scanf("%d", &turn);
	while (cnt != turn) {
		mul3 = 3 * num++;
		l = solution(mul3);
		if (l > 1) {
			while (l != 0) {
				rslt = mul3 / pow(10, (l - 1));
				mul3 -= rslt * pow(10, (l - 1));
				l--;
				cnt++;
				if (cnt == turn)
					break;
			}
		}
		else {
			rslt = mul3;
			cnt++;
		}
	}
	printf("%d", rslt);
}