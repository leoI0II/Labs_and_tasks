#define STEP 10
#define LOWER 0
#define UPPER 300

#include <stdio.h>

int main(){
    // float fahr, celsius;
    // int lower, upper, step, count = 0;
    // lower = 0; /* нижняя граница таблицы температур */
    // upper = 300; /* верхняя граница */
    // step = 10; /* шаг */
    // celsius = lower; printf("\tТаблица градусов из Форенгейта в Цельсий\n");
    // while (celsius <= upper) {
    //     fahr = 32.0 + (9.0/5.0)*celsius;
    //     printf ("\t\t%3.1f\t%6.2f\n", celsius, fahr);
    //     celsius += step;
    //     count++;
    // } printf("%d\n", count);
    //printf("Color %s, Number %d, Float %4.2f\n", "red", 1234, 3.14);
    int fahr;
    for(fahr = UPPER; fahr >= LOWER; fahr -= STEP)
        printf("%3d   %.2f\n", fahr, (5.0/9.0)*(fahr - 32.0)); //тоже самое, что и выше, только с for
}