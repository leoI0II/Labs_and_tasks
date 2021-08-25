#include <stdio.h>
//#define RED   "\033[0;46;31m"  
//#define CYAN  "\033[0;36m"  
//#define NONE   "\033[0m"    
#define CODE1  "\033[32;43m"  
#define NONE  "\033[0m"


int main()
{
    // int N=3, result; printf("%s, %s, %d: Инициализация переменных\n", __FILE__, __func__, __LINE__);
    // result = N; printf("%s, %s, %d: Присваивание result\n", __FILE__, __func__, __LINE__);
    // result = result*N; printf("%s, %s, %d: Умножение на N\n", __FILE__, __func__, __LINE__);
    // return 0;
    //printf("%sHello, %sworld!%s\n", RED, CYAN, NONE);
    // int *p = NULL;
    // fprintf(stderr, "Before: ");
    // *p = 10;
    // printf("After: ");
    // printf("%s, %d: первый вызов\n",  __func__, __LINE__);
    // printf("%s, %d: второй вызов\n",  __func__, __LINE__);
    printf("%sHello%s\n", CODE1, NONE);
    return 0;
}