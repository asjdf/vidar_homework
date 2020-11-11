#include <stdio.h>

char* str = "I'm the most evil E99p1ant!!!";
int main() {
    printf("initial addr:\n%p\ninitial E99p1ant:\n%s\n\n", str, str);
    char* str2 = (char*)&str;
    *str2 = "I'm the most hentai E99p1ant!!!";
    printf("now addr:\n%p\nnow E99p1ant:\n%s\n", str, str);
    return 0;
}