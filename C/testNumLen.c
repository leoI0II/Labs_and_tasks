#include <stdio.h>
#include <stdlib.h>
//#include <ncurses.h>
#include <math.h>

void char_register(char * ch, int fl);

int main(){

        // int num, count = 0;
        // scanf("%d", &num);

        // while(num){
	// 	//printf("%d\n", num/=10);
	// 	num /= 10;
        //         count++;
	// 	//printf("%d\n", count);
        // }

        // printf("%d\n", count);
	// int a;
	// a = getchar();
	// putchar(a);
	// //putchar(a);

        // double a = 5.213223;
        // printf("%d\n", (int)a);

//task1 Ariphmetica C gradusy v radian
        // int a;
        // double pi = 3.1415926, b;
        // scanf("%d", &a);

        // printf("%.2f\n", (a*pi)/180);

//task2 Rasstoyanie mezhdu koordinatami

        // double cor1x, cor1y, cor2x, cor2y;
        // scanf("%lf%lf%lf%lf", &cor1x, &cor1y, &cor2x, &cor2y);

        // printf("%.2f", sqrt(pow(cor1x - cor2x,2) + pow(cor1y - cor2y,2)));

//task3 Bit 2 ** n
        // int n;
        // scanf("%d", &n);
        // printf("%.0f\n", pow(2,n));


//task4 Ploschad treugolnika
        // double a, b, c;
        // scanf("%lf%lf%lf", &a, &b, &c);

        // double p = (a+b+c)/2, square = sqrt(p*(p-a)*(p-b)*(p-c));
        // printf("%.2f\n", square);


// Argumenty v func s pointers 
//task 4

        char let; int var;
        scanf("%c %d", &let, &var);
        char_register(&let, var);
        printf("%c\n", let);


        return 0;
}



// void char_register(char * ch, int fl){
//     if( *ch >= 65 && *ch <= 90 || *ch >= 97 && *ch <= 122 ){
//         if( *ch >= 65 && *ch <= 90 ){
//             if( fl ) *ch = tolower(*ch);
//         } else {
//             if ( fl ) *ch = toupper(*ch);
//         }
//     }
// }

void char_register(char * ch, int fl){
    if( *ch >= 65 && *ch <= 90){
        if( fl ) *ch = *ch + 32;
    } else if( *ch >= 'a' && *ch <= 'z' ){
        if( fl ) *ch = *ch - 32;
    }
}