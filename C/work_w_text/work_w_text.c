#include<stdio.h>

int summ(int a){
    static int sumator = 10;
    // sumator++;
    return a+sumator++;
}

int main()
{
    // char t[10];
    // char e[10];
    // scanf("%[XYZ]%[0-9]", t, e);
    // // scanf("%[0+-]%s",t, e);
    // printf("%s %s\n", t, e);

    // float f = 3.8415;
    // printf("|%3.3f|\n", f);

    // char s[] = "Abc"; char c = 'Q';
    // printf("|%-5.s|\n", s);

    // int*a;
    // int arr[3];
    // for (int i = 0; i < 3; ++i) scanf("%d", );

    // for (int i = 0; i < 3; ++i) printf("%d ", arr[i]);
    int a = summ(1);
    int b = summ(2);
    int c = summ(3);
    printf("%d %d %d\n", a, b, c);

    return 0;
}