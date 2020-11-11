#include <stdarg.h>
#include <stdio.h>

double ave(int n, ...);  // n代表可变部分总共有几个变量

int main() {
    printf("First term : %.2lf\n", ave(5, 88, 99, 70, 95, 93));
    printf("Second term : %.2lf", ave(7, 100, 99, 92, 88, 68, 94, 92));
}

double ave(int n, ...) {
    double total = 0;
    va_list ap;
    va_start(ap, n);
    for (size_t i = 0; i < n; i++) {
        total += va_arg(ap, int);
    }
    return total / n;
}