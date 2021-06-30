#include <stdio.h>
#include<stdlib.h>
#include<string.h>

//task1 Factorial DONE
// long long int recFact(int a)
// {
//     if( a < 0 ) return 0;
//     else if ( a == 0 ) return 1;
//     else return a * recFact( a - 1 );
// }

// int main(){
//     int a;
//     scanf("%d", &a);
//     long long b = recFact(a);
    
//     printf("%lld", b);

//     return 0;
// }

//task2 Power DONE
// double recPow(int a, int b)
// {
//     if (b == 0) return 1;
//     if (a == 0) return 0;
//     if (b > 0) return a * recPow(a, b-1);
//     if (b < 0) return 1.0/recPow(a, -b);
// }

// int main(){
//     int a, b;
//     scanf("%d%d", &a, &b);
//     printf("%lf\n", recPow(a, b));

//     return 0;
// }




//task3 DONE
// void pr(int c)
// {
//     if (c == 0) return;

//     int n;
//     scanf("%d", &n);
//     pr(c - 1);
//     printf("%d ", n);
// }

// int main(){

//     int a;
//     scanf("%d", &a);
//     pr(a);

//     return 0;
// }



//task4 DecToBin DONE
// void recDecToBin(int n, char* result)
// {
//     if (n < 0) return;

//     int del = n%2;
//     n /= 2;
//     if (n == 0) {
//         if (del == 1)
//             strcat(result, "1");
//         else strcat(result, "0");
//     return;}
    
//     recDecToBin(n, result);
    
//     if (del == 1)
//         strcat(result, "1");
//     else strcat(result, "0");
// }

// int main(){
//     int n;
//     // char result[30] = "";
//     char *result = (char*) malloc (30 * sizeof(char));
//     scanf("%d", &n);
//     // вызов функции recDecToBin
//     recDecToBin(n, result);
//     // puts(result);
//     printf("%s", result);
//     return 0;           
// }


//task5 DONE
// static int count = 0;
// int recSum(int arr[])
// {
//     int i = count;
//     count++;

//     if (count == 100) return arr[i];
//     return arr[i] + recSum(arr);
// }

// int main()
// {
//     int arr[5];
//     for (int i = 0; i < 100; i++) scanf("%d", &arr[i]);
//     // for (int i = 0; i < 5; i++) printf("%d ", arr[i]); printf("\n");
//     printf("%d\n", recSum(arr));

//     return 0;
// }




//task6 
static int gg, vv, r = 0;
void FF(int **arr, int i, int j)
{
    if (i >= gg || i < 0 || j>= vv || j < 0) return;    
    if (arr[i][j] == 1) return;
    arr[i][j] = 1;

    if (i == gg -1 && j == vv -1) r = 1;
    // if (i >= gg || i < 0 || j>= vv || j < 0) return;
    FF(arr, i+1, j);
    FF(arr, i, j+1);
    FF(arr, i-1, j);
    FF(arr, i, j-1);

    if (r == 1){
        printf("exist\n");
        return;
    }
    else{
        printf("doesn't exist\n");
        return;
    }
}


int main()
{
    int v, g;
    scanf("%d%d", &g, &v);
    gg = g; vv = v;
    
    int **labir = (int**) malloc (g * sizeof(int*));

    for (int i = 0; i < g; i++){
        labir[i] = (int*) malloc (v * sizeof(int));
        for (int j = 0; j < v; j++){
            scanf("%d", &labir[i][j]);
        }
    }

    FF(labir, 0, 0);

    return 0;
}