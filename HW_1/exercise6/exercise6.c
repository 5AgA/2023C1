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
	printf("���� ��ȣ: ");
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
		printf("*** �ζ� ��ȣ ������ ***\n");
		printNum(num);
		printf("�ٽ� �����ϰڽ��ϱ�? (y/n): ");
		scanf(" %c", &choice);
	} while (choice != 'n');

}