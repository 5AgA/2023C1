#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	int idx = 0, sum = 0, lgth, number = 0;
	int reslt[4] = { 0 };
	char num[52];

	scanf("%s", num);
	for (lgth = 0; num[lgth] != '\0'; lgth++);

	//2의 배수 확인
	if ((int)(num[lgth - 1] - 48) % 2 == 0)
		reslt[idx++] = 1;
	else
		reslt[idx++] = 0;

	//3의 배수 확인
	for (int i = 0; i < lgth; i++)
		sum += (int)(num[i] - 48);
	
	if (sum % 3 == 0)
		reslt[idx++] = 1;
	else
		reslt[idx++] = 0;

	//4의 배수 확인
	number += (int)(num[lgth - 2] - 48) * 10 + (int)(num[lgth - 1] - 48);
	if (number % 4 == 0)
		reslt[idx++] = 1;
	else
		reslt[idx++] = 0;

	//5의 배수 확인
	if ((int)(num[lgth - 1] - 48) == 0 || (int)(num[lgth - 1] - 48) == 5)
		reslt[idx++] = 1;
	else
		reslt[idx++] = 0;

	for (int i = 0; i < 4; i++) printf("%d", reslt[i]);
}