// �α�� - ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(char* actors[], int n, int* picked, int m, int toPick) {
    int lastIndex, smallest, i;

    if (toPick == 0) {
        for (i = 0; i < m; i++)
            //printf("%d ", picked[i]);
            printf("%s ", actors[picked[i]]);
        printf("\n");
        return;
    }

    lastIndex = m - toPick - 1;
    if (toPick == m)
        smallest = 0;
    else
        smallest = picked[lastIndex] + 1;

    for (i = smallest; i < n; i++) {
        picked[lastIndex + 1] = i;
        pick(actors, n, picked, m, toPick - 1);
    }
}

int main(void) {
    char* actors[] = { "����", "�����",
        "���߱�", "����", "����" };
    int* picked;
    int num;

    scanf("%d", &num);
    if (num <= 0) return 0;
    picked = (int*)malloc(sizeof(int) * num);
    if (!picked) {
        printf("�޸𸮸� �Ҵ��� �� �����ϴ�.");
        return 0;
    }

    pick(actors, 5, picked, num, num);

    free(picked);
    return 0;
}