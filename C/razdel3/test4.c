#include <stdio.h>
#include <math.h>


// task 1 DONE
// void cube(int * a){
//     *a = pow(*a, 3);
// }

// int main(){
//     int a;
//     scanf("%d", &a);

//     cube(&a);

//     printf("%d\n", a);
// }



// task 2 
void swap(int *a, int *b){
    int c = 0;
    for(int i = 0 ; i < 10 ; i++){
        c = *(a + i);
        *(a + i) = *(b + i);
        *(b + i) = c;
    }
    for(int i = 0 ; i < 10 ; i++){
        c = a[i];
        a[i] = b[i];
        b[i] = c;
    }
}

// void print(int* a){
//     printf("%d\n", *a);
// }


// int main(){
//     int a[10] = {1,2,3,4,5,6,7,8,9,10};
//     int b[10] = {10,9,8,7,6,5,4,3,2,1};

//     printf("First array:\n");
//     for (int i = 0 ; i < 10; i++) printf("%d,", a[i]);
//     printf("\nSecond array:\n");
//     for (int i = 0 ; i < 10; i++) printf("%d,", b[i]); printf("\n");

//     swap(a, b);
//     // print(&a);


//     printf("New First Array\n");
//     for (int i = 0 ; i < 10; i++) printf("%d,", a[i]);
//     printf("\nNew Second array:\n");
//     for (int i = 0 ; i < 10; i++) printf("%d,", b[i]); printf("\n");

//     return 0;
// }









// int main(void)
// {
//     int c;
     
//     while((c=getchar())!=EOF)
//     {
//         putchar(c);
//     }
//     return 0;
// }





// int main(void)
// {
//     char name[20];
//     puts("Enter name:");
     
//     gets(name);
//     printf("Your name: %s\n", name);
//     return 0;
// }



//Mnogomernye massivy
// int main(){
//     // int array[3][2] = {{1, 2}, {3, 4}, {5, 6}};

//     // for (int i = 0; i < 3; ++i){
//     //     for (int j = 0; j < 2; ++j){
//     //         printf("%d ", array[i][j]);
//     //     }
//     //     printf("\n");
//     // }

//     int arr[5][2];
//     for (int i = 0; i < 5; ++i){
//         for (int j = 0; j < 2; ++j){
//             scanf("%d", &arr[i][j]);
//         }
//     }

//     for (int i = 0; i < 5; ++i){
//         for (int j = 0; j < 2; ++j){
//             printf("%d ", arr[i][j]);
//         }
//         printf("\n");
//     }


//     return 0;
// }





// Strings array 
//Bad exp
// int main(){

//     char world[20]; char space = ' ';
//     int i = 0;
//     do{
//         scanf("%c%c", &world[i], &space);
//         ++i;
//     } while(space != '\n');

//     for(int j = 0; j < i; ++j){
//         printf("%c", world[j]);
//     }

//     // printf("%s\n", world);


//     return 0;
// }




// int main(){

//     int arr[2] = {0,1};

//     printf("%d\n", *(arr+2));


//     return 0 ;
// }




// void sum_digits(int *x){
//     int sum_digits = 0;
//     int temp = *x;
//     for (int i = 0 ; temp > 0; i++){
//         sum_digits += temp % 10;
//         temp = temp / 10;
//     }
//     *x = sum_digits;

// }


// int main(){

//     int x;
//     scanf("%d", &x);

//     sum_digits(&x);

//     printf("%d\n", x);

//     return 0;
// }







// int main(){



//     return 0;
// }