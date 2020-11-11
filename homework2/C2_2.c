#include <math.h>
#include <stdio.h>
int oWin(int _map[3][3]) {
    // 用于判断是否已经胜利 如果胜利则返回1 否则返回0
    // 横向满足
    int total;
    for (size_t line = 0; line < 3; line++) {
        total = 0;
        for (size_t i = 0; i < 3; i++) {
            total += _map[line][i];
        }
        if (total == 3) {
            return 1;
        }
    }
    // 纵向满足
    for (size_t row = 0; row < 3; row++) {
        total = 0;
        for (size_t i = 0; i < 3; i++) {
            total += _map[i][row];
        }
        if (total == 3) {
            return 1;
        }
    }
    // 斜方向满足
    total = 0;
    for (size_t i = 0; i < 3; i++) {
        total += _map[i][i];
    }
    if (total == 3) {
        return 1;
    }
    total = 0;
    for (size_t i = 0; i < 3; i++) {
        total += _map[i][2 - i];
    }
    if (total == 3) {
        return 1;
    }

    return 0;
}

int main() {
    int map[3][3];
    int empty = 0;  // 记录剩余棋盘位置数
    // 读取棋谱
    for (size_t line = 0; line < 3; line++) {
        for (size_t row = 0; row < 3; row++) {
            switch (getchar()) {
                case 'X':
                    map[line][row] = -1;
                    break;
                case 'O':
                    map[line][row] = 1;
                    break;
                case '_':
                    map[line][row] = 0;
                    break;
            }
            empty += !map[line][row];
        }
        getchar();
    }

    if (oWin(map)) {
        printf("win");
    }

    // 读取完成
    int wrong = 0;  // 判断棋谱是否存在
    for (size_t line = 0; line < 3; line++) {
        for (size_t row = 0; row < 3; row++) {
            wrong += map[line][row];
        }
    }
    // 当棋谱上数字不为0时说明棋盘上XO子的数量不同
    if (wrong) {
        printf("wrong");
        return 0;
    }

    if (oWin(map)) {
        printf("alre4dy w1n");
    }

    //分别测只落1子和2子的可行性
    if (empty >= 1) {
        for (size_t line = 0; line < 3; line++) {
            for (size_t row = 0; row < 3; row++) {
                // 判断是否可以落子并落子
                if (map[line][row] == 0) {
                    int temp[3][3];
                    for (size_t i = 0; i < 3; i++) {
                        for (size_t j = 0; j < 3; j++) {
                            temp[i][j] = map[i][j];
                        }
                    }
                    temp[line][row] = 1;
                    if (oWin(temp)) {
                        printf("can win");
                        return 0;
                    }
                }
            }
        }
    }
    //落2子
    if (empty >= 3) {
        for (size_t line0 = 0; line0 < 3; line0++) {
            for (size_t row0 = 0; row0 < 3; row0++) {
                // 判断是否可以落子并落子
                if (map[line0][row0] == 0) {
                    int temp[3][3];
                    for (size_t i = 0; i < 3; i++) {
                        for (size_t j = 0; j < 3; j++) {
                            temp[i][j] = map[i][j];
                        }
                    }
                    temp[line0][row0] = 1;

                    //落第2子
                    for (size_t line1 = line0; line1 < 3; line1++) {
                        for (size_t row1 = row0; row1 < 3; row1++) {
                            // 判断是否可以落子并落子
                            if (temp[line1][row1] == 0) {
                                temp[line1][row1] = 1;
                                if (oWin(temp)) {
                                    printf("can win");
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    printf("can't win");
    return 0;
}