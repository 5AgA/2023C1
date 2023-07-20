#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
char calculateReverse(int n) {
    int ret = 0;
    int rem = 0;

    while (n != 0) {
        rem = n % 10;
        ret = ret * 10;
        ret = ret + rem;
        n = n / 10;
    }
    return (char)ret;
}

void main() {
    char num1, num2;
    int input_num;
    int count = 0;

    scanf_s("%d", &input_num);

    num1 = (char)input_num;

    num2 = calculateReverse(atoi(num1));
    while (num1 != num2) {
        count++;
        num1 = num2 + num1;
        num2 = calculateReverse(atoi(num1));
        if (count > 1000) {
            printf("NaN\n");
            return;
        }
    }
    printf("%d %d\n", count, atoi(num1));
}