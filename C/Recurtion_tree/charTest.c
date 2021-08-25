#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void pr(char* str)
{
    while(*str){
        putc(*str, stdout);
        ++str;
    }
}

int main()
{
    char s[256];
    fgets(s, 256, stdin);
    pr(s);

    return 0;
}