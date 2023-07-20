#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void generateNum(int arr[])
{
	for (int i = 0; i < 6; i++)
		arr[i] = rand() % 46;
}
void printNum(int arr[])
{
	printf("생성 번호: ");
	for (int i = 0; i < 6; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
int main(void)
{
	srand(time(NULL));

	int num[6];
	char choice;

	do
	{
		generateNum(num);
		printf("*** 로또 번호 생성기 ***\n");
		printNum(num);
		printf("다시 생성하겠습니까? (y/n): ");
		scanf(" %c", &choice);
	} while (choice != 'n');

}