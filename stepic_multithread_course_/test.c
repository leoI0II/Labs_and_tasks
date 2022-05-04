#include<stdio.h>

struct test{
    int a;
    int b;
};


int main()
{
    struct test aa = {.a = 10, .b = 23};
    // aa.a = 10;
    // aa.b = 23;

    printf("%d %d\n", aa.a, aa.b);

    return 0;
}