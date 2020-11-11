#include <stdlib.h>

#define LEN 512

typedef struct num {
    int len;          //数值长度
    char symbol;      //数字正负形
    int number[LEN];  //数组
} NUM, *BIGNUM;

BIGNUM expToNum(char exp[]);     //将输入字符串转换为对应结构体
void reverse(int a[], int len);  //数组逆序
int compareAbs(BIGNUM left, BIGNUM right);   //比较两数绝对值大小
BIGNUM anti_add(BIGNUM left, BIGNUM right);  //元加法
BIGNUM anti_sub(BIGNUM left, BIGNUM right);  //元减法
BIGNUM add(BIGNUM left, BIGNUM right);       //加法
BIGNUM sub(BIGNUM left, BIGNUM right);       //减法
BIGNUM multiply(BIGNUM left, BIGNUM right);  //乘法
BIGNUM mod(BIGNUM left, BIGNUM right);       //求摸运算

BIGNUM multiply(BIGNUM left, BIGNUM right) {
    // left作为被乘数，right作为乘数
    BIGNUM mul = (struct num*)malloc(sizeof(struct num));
    int i, j;
    for (i = 0; i < LEN; i++) {
        mul->number[i] = 0;
    }

    if (left->symbol == right->symbol) {
        mul->symbol = '+';
    } else {
        mul->symbol = '-';
    }

    //逐位相乘同时相加
    for (i = 0; i < right->len; i++) {
        for (j = 0; j < left->len; j++) {
            mul->number[i + j] += left->number[j] * right->number[i];
        }
    }

    //进位化简
    int len = left->len + right->len - 1;  //长度

    //加和
    for (i = 0; i < len; i++) {
        mul->number[i + 1] += mul->number[i] / 10;
        mul->number[i] %= 10;

        if (i == len - 1) {
            if (mul->number[i + 1] != 0) {  //还存在高位
                len++;
            } else {  //进位完毕，退出
                break;
            }
        }
    }

    //舍去多余0位
    for (i = len - 1; i >= 0; i--) {
        if (mul->number[i] == 0) {
            len--;
        } else {
            break;
        }
    }
    if (len == 0) {
        len = 1;
    }

    mul->len = len;

    //它免费了
    free(left);
    free(right);
    return mul;
}

//减一个数等于加上一个数的相反数
BIGNUM sub(BIGNUM left, BIGNUM right) {
    right->symbol = (right->symbol == '+' ? '-' : '+');
    return add(left, right);
}

//比较两数绝对值大小
int compareAbs(BIGNUM left, BIGNUM right) {
    if (left->len > right->len) {  // left的位数更多
        return 1;
    } else if (left->len < right->len) {  // right的位数更多
        return -1;
    } else {
        int i = left->len - 1;
        while (i >= 0) {  //从高位开始比较
            if (left->number[i] > right->number[i]) {
                return 1;
            }
            if (left->number[i] < right->number[i]) {
                return -1;
            }
            i--;
        }
        return 0;  //两者绝对值相等
    }
}

BIGNUM expToNum(char exp[]) {
    BIGNUM temp = (struct num*)malloc(sizeof(struct num));

    int locan = 0;
    //确定正负号
    if (exp[0] == '+' || exp[0] == '-') {
        temp->symbol = exp[0];
        locan++;
    } else {
        temp->symbol = '+';
    }

    //输入到数组
    int count = 0;
    while (exp[locan] != '\0') {
        temp->number[count] = exp[locan] - '0';
        locan++;
        count++;
    }

    int i = count;
    for (i = count; i < LEN - 1; i++) {
        temp->number[i] = 0;
    }

    temp->len = count;

    //数组逆序从个位开始计算
    reverse(temp->number, temp->len);

    return temp;
}

//数组逆序
void reverse(int a[], int len) {
    int i, temp;
    for (i = 0; i < len / 2; i++) {
        temp = a[i];
        a[i] = a[len - 1 - i];
        a[len - 1 - i] = temp;
    }
}

//元加法，假设left和right都为正数或0
BIGNUM anti_add(BIGNUM left, BIGNUM right) {
    int i = 0;

    while (i < left->len || i < right->len) {
        int sum = 0;
        sum = left->number[i] + right->number[i];
        if (sum >= 10) {
            left->number[i] = sum % 10;
            left->number[i + 1] += sum / 10;  //进位
        } else {
            left->number[i] = sum;  //不进位
        }

        i++;
    }

    if (left->number[i] != 0) {
        i += 1;
    }

    left->len = i;
    return left;
}

//实现正数或负数的加法
BIGNUM add(BIGNUM left, BIGNUM right) {
    BIGNUM temp;
    if (left->symbol == right->symbol) {
        temp = anti_add(left, right);
    } else {
        if (compareAbs(left, right) >= 0) {
            temp = anti_sub(left, right);

        } else {
            temp = anti_sub(right, left);
        }
    }
    return temp;
}

//元减法,假设left>=right，left和right均为正数或0
BIGNUM anti_sub(BIGNUM left, BIGNUM right) {
    int i = 0;
    int count = 0;
    while (i < left->len) {
        int temp = left->number[i] - right->number[i];
        if (temp < 0) {
            left->number[i + 1] -= 1;
            left->number[i] = temp + 10;  //退位
        } else {
            left->number[i] = temp;
        }

        count += 1;

        i++;
    }

    //舍掉多余的0
    for (i = count - 1; i >= 0; i--) {
        if (left->number[i] == 0) {
            count--;
        } else {
            break;
        }
    }

    if (count == 0) {
        count++;
    }

    left->len = count;
    return left;
}