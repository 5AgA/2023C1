#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int getLength(int num)
{
	if (num == 0) return 0;
	else return 1 + getLength(num / 10);
}

int getNum(int n)
{
	int N = 1;
	while (n != 0) {
		int l = getLength(N);
		if (l == 1) {
			n--;
		}
		else {
			int num = N;
			for (int i = l; i > 0; i--) {
				int highest = num / pow(10, i - 1); // 제일 높은 자릿수 추출
				n--;
				if (n == 0) 
					return highest;
				num -= highest * pow(10, i - 1);
			}
		}
		if (n == 0) return N % 10;
		N++;
	 }
}

int main(void)
{
	int n;

	scanf("%d", &n);

	printf("%d\n", getNum(n));

	return 0;
}