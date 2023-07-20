#include <stdio.h>

unsigned long long generate_number_ones(int nlen) {
    unsigned long long ret = 0;
    int i;

    for (i = 0; i < nlen; i++) {
        ret = ret * 10 + 1;
    }
    return ret;
}

void main() {
    unsigned long long number_ones = 0;
    int input_number;
    int i = 1;

    scanf_s("%d", &input_number);

    while (1) {
        number_ones = generate_number_ones(i);
        if (number_ones % input_number == 0) {
            break;
        }
        i++;
    }

    printf("%d\n", i);
}