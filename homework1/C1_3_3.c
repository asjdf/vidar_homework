#include <stdio.h>
#include <math.h>
int main(){
    int n = 22;
    for (int y = n; y > -n; y--){
        for (float x = -n; x < n; x += 0.35){
            if (pow(x,2) + pow(y - pow(pow(x,2),1/3.0),2) <= 200){
                printf(".");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0; 
}