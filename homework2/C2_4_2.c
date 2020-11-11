// 关于这一题的解法的我的解释：因为我认为没有办法完成这个变参函数
// 所以我用了define的方法来实现 这是我目前能想到的最好的解法了

#include <stdio.h>
#define ave(ret_p, ...)                                           \
    do {                                                          \
        int arg[] = {__VA_ARGS__};                                \
        *(double*)(ret_p) = clac(arg, sizeof(arg) / sizeof(int)); \
    } while (0)

double clac(int arg[], int n) {
    double average;
    for (size_t i = 0; i < n; i++) {
        average += arg[i];
    }
    return average / n;
}

int main() {
    double sum = 0;
    ave(&sum, 88, 99, 70, 95, 93);
    printf("First term : %.2lf\n", sum);
    ave(&sum, 100, 99, 92, 88, 68, 94, 92);
    printf("Second term : %.2lf", sum);
}