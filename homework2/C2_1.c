#include <stdio.h>
#include "bigNumCount.h"

int main() {
    char num1[101];
    char num2[101];
    scanf("%s\n%s", num1, num2);
    BIGNUM num = add(expToNum(num1), expToNum(num2));
    printf("%c", num->symbol);
    for (int i = num->len - 1; i >= 0; --i) {
        printf("%d", num->number[i]);
    }
    putchar('\n');
}