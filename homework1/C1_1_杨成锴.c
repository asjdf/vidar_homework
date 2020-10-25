#define TEXT_LEN 512
#include <stdio.h>
char down2up(char c){
    if (c>='a'&&c<='z')
    {
        return c - 'a' +'A';
    }else
    {
        return c;
    } 
}
char up2down(char c){
    if (c>='A'&&c<='Z')
    {
        return c - 'A' + 'a';
    }else
    {
        return c;
    } 
}

int main(){
    char text[TEXT_LEN];
    for (size_t i = 0; i < 512; i++)
    {
        text[i] = ' ';
    }
    int strLen = 0;
    int up = 0;
    int down = 0;
    char c;
    do
    {
        c=getchar();
        if (c>='a'&&c<='z')
        {
            
            down++;
        }else if (c>='A'&&c<='Z')
        {
            up++;
        }
        text[strLen] = c;
        strLen++;
    } while (c != '\n');

    if (down > up)
    {
        for (size_t i = 0; i < strLen-1; i++)
            {
                printf("%c", up2down(text[i]));
            }
    }else
    {
        for (size_t i = 0; i < strLen-1; i++)
        {
            printf("%c", down2up(text[i]));
        }
    }
    return 0;
}