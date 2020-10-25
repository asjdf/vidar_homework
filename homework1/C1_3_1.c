#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    for (size_t i = 1; i < n + 1; i=i+2)
    {
        for (size_t s = (n-i)/2; s > 0; s--)
        {
            printf(" ");
        }
        for (size_t s = 0; s < i; s++)
        {
            printf("*");
        }
        printf("\n");
    }
}