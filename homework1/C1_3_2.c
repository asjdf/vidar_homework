#include <stdio.h>
#include <math.h>
int circle(int line, int row, int r){
    if (pow(r - line,2) + pow(r - row,2) <= pow(r+0.5, 2)
     && pow(r - line,2) + pow(r - row,2) >= pow(r-0.5, 2)){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    int n;
    scanf("%d", &n);
    // 行
    for (size_t i = 0; i <= 2*n; i++){
        // 列
        for (size_t l = 0; l <= 2*n; l++){
            // printf("%d ", l);
            if (circle(i,l,n)){
                printf(" . ");
            }else{
                printf("   ");
            }
        }
        printf("\n");
    }
    return 0;
}