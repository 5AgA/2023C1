#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, sum, i;
	int* p;
	scanf("%d", &n);
	if (n <= 0) return 0;
	p = (int*)malloc(sizeof(int) * n);
	
	if (!p)
	{
		printf("�޸𸮸� �Ҵ��� �� �����ϴ�.");
		return 0;
	}

	for (i = 0; i < n; i++)
	{
		scanf("%d", &p[i]);
	}

	sum = 0;
	for (i = 0; i < n; i++)
		sum += p[i];
	printf("��� = %d\n", sum/n);

	free(p);
}