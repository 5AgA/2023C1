#include <stdio.h>

void main() {
    int num1, num2;
    int rem1, rem2;
    int carry = 0;
    int carry_count = 0;

    scanf_s("%d %d", &num1, &num2);

    while (num1 != 0 || num2 != 0) {
        rem1 = num1 % 10;
        rem2 = num2 % 10;

        if (rem1 + rem2 + carry >= 10) {
            carry = 1;
            carry_count++;
        }
        else
            carry = 0;

        num1 = num1 / 10;
        num2 = num2 / 10;
    }

    printf("%d\n", carry_count);
}