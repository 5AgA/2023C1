#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void carryNum(char num1[], char num2[], int s1, int s2, int carry, int carry_count) {
    int rem1 = 0, rem2 = 0;

    if (s1 - 1 < 0 && s2 - 1 < 0) {
        printf("%d\n", carry_count);
        return;
    }

    else {
        if (num1[s1 - 1] - 48 >= 0)
            rem1 = num1[s1 - 1] - 48;
        if (num2[s2 - 1] - 48 >= 0)
            rem2 = num2[s2 - 1] - 48;

        if (rem1 + rem2 + carry >= 10) {
            carryNum(num1, num2, (s1 - 1), (s2 - 1), 1, (carry_count + 1));
        }
        else {
            carryNum(num1, num2, (s1 - 1), (s2 - 1), 0, carry_count);
        }
    }
}
void main() {
    char num1[101] = { 0 };
    char num2[101] = { 0 };
    int s1, s2;

    scanf("%s", num1);
    scanf("%s", num2);
    for (s1 = 0; num1[s1] != '\0'; s1++);
    for (s2 = 0; num2[s2] != '\0'; s2++);

    carryNum(num1, num2, s1, s2, 0, 0);
}