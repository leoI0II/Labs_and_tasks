// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// //Напишите функцию f здесь

// // void f(int a[], int b[]){
// //     int temp = 0;
// //     for (size_t i = 0; i < 10; i++){
// //         if (!(i%2)){
// //             temp = a[i];
// //             a[i] = b[i];
// //             b[i] = temp;
// //         }
// //     }
// // }


// // int main(){
// //     int a[10];
// //     int b[10];
// //     for(int i = 0 ; i < 10; i++){
// //         scanf("%d",&a[i]);
// //     }
// //     for(int i = 0 ; i < 10; i++){
// //         scanf("%d",&b[i]);
// //     }

// //     //Напишите вызов функции f здесь
// //     f(a, b);

// //     for(int i = 0 ; i < 10; i++){
// //         printf("%d ",a[i]);
// //     }
// //     printf("\n");
// //     for(int i = 0 ; i < 10; i++){
// //         printf("%d ",b[i]);
// //     }
// //     return 0;
// // }


// void clean_buffer()
// {
//     int c;
//     while((c = getchar()) != '\n');
// }


// int main(){

//     char *str = malloc( 20 * sizeof(char) );

//     fgets(str, 20, stdin);
//     str[strlen(str)-1] = '\0';

//     char* solveStr = malloc( 2 * strlen(str) * sizeof(char) );

//     for( size_t i = 0, j = 0; i < strlen(str) && j < strlen(str)*2; i++ , j += 2 ){
//         solveStr[j] = str[i];
//         solveStr[j+1] = str[i];
//     }

//     solveStr[strlen(solveStr)] = '\0';
//     printf("%s\n", solveStr);

//     return 0;
// }





#include <stdio.h>
#include <stdlib.h>

int main(){
    
    // int c, nl = 0;

    // while ((c = fgetc(stdin)) != '\n' ){
    //     if (c == '.') ++nl;
    // }

    // printf("%d\n", nl);



    // int ch, space = 0;

    // while ((ch = getchar()) != '\n' ){
    //     space = (ch == ' ') ? space+1 : 0;
    //     if (space < 2) putchar(ch);
    // }
    


    // int ch, count = 0;

    // while ((ch = getchar()) != '\n' ){
    //     if (ch == ' ' || ch == '\t' ) ++count;
    // }
    // printf("%d\n", count);



    // int s[10];
    // for(int i = 0; i < 10; i++){
    //     scanf("%lc", &s[i]);
    // }
    // for (int i = 0; i < 10; i++)
    //     printf("%d", s[i]);




    // unsigned int x = 7;
    // int b = 0;
    // for (int i = 0; x != 0; x>>= 1){
    //     if(x & 01) b++;
    // }
    // printf("%d\n", b);



    char* a;
    printf("%ld", sizeof(a));


    return 0;
}