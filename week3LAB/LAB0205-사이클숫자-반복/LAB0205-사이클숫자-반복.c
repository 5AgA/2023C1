#include <stdio.h>

int get_cycle_number(int n) {
    int ret = 1;
    while (n != 1) {
        if (n % 2 == 0)
            n = n / 2;
        else
            n = n * 3 + 1;

        ret++;
    }
    return ret;
}

void main() {
    int n = 22;

    printf("%d\n", get_cycle_number(n));
}