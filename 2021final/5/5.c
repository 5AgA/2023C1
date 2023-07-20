// 피보나치 최적화
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int fib(int n, int* F)
{
    if (F[n] != 0) {
        return F[n];
    }
    else if (n == 1 || n == 2) {
        F[n] = 1;
        return F[n];
    }
    else {
        F[n] = fib(n - 1, F) + fib(n - 2, F);
        return F[n];
    }
}

int main(void)
{
    int n, i;
    int* F;

    scanf("%d", &n);
    if (n <= 0) return 0;
    F = (int*)malloc(sizeof(int) * (n + 1));
    if (!F) return 0;
    for (i = 1; i <= n; i++)
        F[i] = 0;

    fib(n, F);
    printf("%d %d\n", F[n], F[n - 1]);

    free(F);
    return 0;
}