#include<stdio.h>
int main(){
    int N,M,K;
    scanf("%d %d %d", &N, &M, &K);
    int list[N];
    int nowL = 0;// 记录当前在列表的第几个
    int nowN = 1;// 记录当前点到了第几个
    int stuLeft = N;
    for (int i = 0; i < N; i++){
        list[i] = 0;
    }
    
    while (1){
        if (!list[nowL]){// 遇到还没点过的人
            nowN++;
            if (nowN >= M)// 遇到被抽的人
            {
                list[nowL] = 1;
                nowN = 0;
                stuLeft--;
            }
        }
        if (stuLeft < M){
            break;
        }

        nowL++;
        if (nowL >= N){
            nowL = 0;
        }
    }
    if (list[K-1]){
        printf("YES");
    }else{
        printf("NO");
    }
}