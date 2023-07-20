// 2345의 배수인지 판별
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char num[52] = { 0 };
	int two, three, four, five;
	int len;
	int i;
	int sum = 0;
	int tmpNum;

	scanf("%s", num);

	len = strlen(num);

	if ((num[len - 1] - '0') % 2 == 0)
		two = 1;
	else
		two = 0;

	if ((num[len - 1] - '0') % 5 == 0)
		five = 1;
	else
		five = 0;

	for (i = 0; i < len; i++)
		sum += num[i] - '0';
	if (sum % 3 == 0)
		three = 1;
	else
		three = 0;

	tmpNum = 10 * (num[len - 2] - '0') + (num[len - 1] - '0');
	if (tmpNum % 4 == 0)
		four = 1;
	else four = 0;

	printf("%d%d%d%d\n", two, three, four, five);
	return 0;
}