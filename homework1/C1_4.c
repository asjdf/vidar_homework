#include <stdio.h>
#include <stdlib.h>
char num[3][11];
int main(){

    // 数据读取部分开始
    char c;
    int i = 0;
    int n = 0;// 当前记录的数字位置
    int endFlag = 0;
    while (1)
    {
        c=getchar();
        printf("%c", c);
        if ((c >= '0'&&c <= '9')||(c >= 'A'&&c <= 'F'))
        {
            endFlag = 0;
            num[i][n] = c;
            n++;
        }else
        {
            if (!endFlag){
                // 如果数结束了同时没有记录已结束
                num[i][n] = '#';
                endFlag = !endFlag;
                i++;
                n = 0;
            }
        }
        if (i >= 3) break;
    }
    // 数据读取部分结束

    

    for (int i = 2; i <= 16; i++)
    {
        int num0 = strtol(num[0],NULL,i);
        int num1 = strtol(num[1],NULL,i);
        int num2 = strtol(num[2],NULL,i); 
        if (num0 == 0 && !(num[0][0] == '0' && num[0][1] == '#'))continue;
        if (num1 == 0 && !(num[1][0] == '0' && num[1][1] == '#'))continue;
        if (num2 == 0 && !(num[2][0] == '0' && num[2][1] == '#'))continue;
        
        if (strtol(num[0],NULL,i) + strtol(num[1],NULL,i) == strtol(num[2],NULL,i))
        {
            printf("%d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}