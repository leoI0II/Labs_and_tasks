#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(){
    //tests
    // char num;
    // scanf("%c", &num);
    // char arNum[sizeof(char)*8];

    // for(int i = 0; i < sizeof(char)*8 || num > 0 ; i++){
    //     arNum[i] = num % 2 ;
    //     num /= 2 ;
    // }

    // for(int i = 0; i < sizeof(char)*8 ; i++){
    //     printf("%d", arNum[i]);
    // }
    // printf("\n");


    // task 1 DONE
    // unsigned long n;
    // scanf("%lu", &n);
    
    // int counter = 0;
    // while( n > 0 ){
    //     if ( n % 2 ) counter++;
    //     n /= 2;
    // }
    // printf("%d\n", counter);
    


    // // task 2
    // char n; int nc; int counter = 0;
    // scanf("%d", &nc);
    // n = nc;
    // // printf("%ld %ld %d %d\n", sizeof(nc), sizeof(n));
    // //char arr[sizeof(char)*8];
    // // printf("%d\n", n);
    // int i = 0;

    // // for (i; n > 0 || i < sizeof(char)*8 ; i++){
    // //     if (n % 2 == 0){
    // //         counter++;
    // //     }
    // //     //printf("%d mod 2 in iter %d = %d\n", n, i, n%2);
    // //     arr[i] = n % 2; n /= 2;
    // // }

    // while ( n > 0 || i < sizeof(char)*8 ){
    //     if (n % 2 == 0){
    //         ++counter;
    //     }
    //     //arr[i] = n % 2;
    //     n /= 2;
    //     i++;
    // }

    // for (i = 0; i < 8; ++i){
    //     printf("%d", arr[i]);
    // }
    // printf("\n");
    // printf("%d\n", counter);



    // task 3 DONE
    // unsigned char n; int nc, i;
    // scanf("%d%d", &nc, &i);
    
    // nc <<= i;
    
    // for (int j = 0; j < i; j++){
    //     nc += (int)pow(2, j);
    // }
    // n = nc;
    // printf("%d\n", n);



    //task 4 DONE
    // printf("%ld\n", sizeof(short int));
    
    // unsigned short n; int i;
    // scanf("%hd%i", &n, &i);
    // int arr[sizeof(short int)*8];

    // // 2 var
    // int j = 0; unsigned short res = 0;
    // while (j < i-1){
    //     res += ( n % 2 ) * (int)pow(2, j);
    //     ++j;
    // }

    // // 1 var
    // for(int j = 0; n > 0 || j < sizeof(short int)*8; j++){
    //     arr[j] = n % 2;
    //     n /= 2;
    //     //printf("%d", arr[j]);
    // }
    // n = 0;
    // for( int j = 0; j < i ; j++){
    //     n += arr[j] * (int)pow(2,j);
    // }
    // printf("%hd\n", res);



    // task 5 
    // unsigned short n; int i;
    // scanf("%hd%i", &n, &i); int arr[sizeof(short int)*8];

    // for(int j = 0 ; n > 0 || j < sizeof(short int)*8; j++){
    //     arr[j] = n % 2; n /= 2;
    // }

    // int res = 0;
    // // n = res;
    // for(int j = 0; j < sizeof(short int)*8; j++){
    //     if (j == i){
    //         res += arr[j] * (int)pow(2, j);
    //     } else {
    //         res += !arr[j] * (int)pow(2, j);
    //     }
    // }

    // printf("%d\n", res);
    // bool n = true;
    // printf("%u\n", !n);

    return 0;
}