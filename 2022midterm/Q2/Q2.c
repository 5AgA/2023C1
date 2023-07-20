// �ߺ� ���� - ������ �̾ƾ� �ϴ���?? -1, 0, 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int cnt = 0, min;
int isSequence(int a[], int size) {
    int d = a[1] - a[0];
    for (int i = 1; i < size - 1; i++) {
        if (a[i + 1] - a[i] != d) {
            return 0;
        }
    }
    return 1;
}

void makeSequence(int* a, int size, int item[], int n, int* bucket, int m, int k, int* tmp) {
    int lastIndex, smallest;
    
    if (k == 0) {
        // �ӽ� �迭�� a �迭 �� ����
        for (int i = 0; i < size; i++) {
            tmp[i] = a[i] + bucket[i];
        }
        
        if (isSequence(tmp, size) == 1) {
            for (int i = 0; i < size; i++)
                if (bucket[i] != 0)
                    cnt++;
            if (cnt < min)
                min = cnt;
            cnt = 0;
            return;
        }
        else {
            cnt = 0;
            return;
        }
    }

    lastIndex = m - k - 1;
    smallest = 0;

    for (int i = smallest; i < n; i++) {
        bucket[lastIndex + 1] = item[i];
        makeSequence(a, size, item, n, bucket, m, k - 1, tmp);
    }
}

int main(void) {
    int* numbers;
    int* bucket;
    int* tmp; // �ӽ� �迭 ����
    int size;
    int item[3] = { -1, 0, 1 };

    scanf("%d", &size);
    if (size <= 0) return 0;
    min = size + 1;
    numbers = (int*)malloc(sizeof(int) * size);
    bucket = (int*)malloc(sizeof(int) * size);
    tmp = (int*)malloc(sizeof(int) * size);

    if (!numbers || !bucket || !tmp) {
        printf("�޸𸮸� �Ҵ��� �� �����ϴ�.");
        return 0;
    }

    for (int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }

    makeSequence(numbers, size, item, 3, bucket, size, size, tmp);

    if (min == size + 1)
        printf("-1\n");
    else
        printf("%d\n", min);

    free(numbers);
    free(bucket);
    free(tmp);
    return 0;
}
