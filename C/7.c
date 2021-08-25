//Задача на сумму факториалов
#include <stdio.h>
#include <limits.h>
//Добавьте библиотеку для поддержки INT_MAX

//Функции менять не недо
//---------------------------------
void factorial_summ(int n);

int main(){
    int n;
    scanf("%i",&n);
    factorial_summ(n);
    return 0;
}
//---------------------------------


void factorial_summ(int n){
    int i = 1, fact = 1, sum = 1; //pre_sum = 0;
    int if_one = 1;
    
    if (n == 0) printf("%d\n", if_one);
    else {
        for(i; i <= n; i++){
            fact *= i;

            if (fact < INT_MAX){
                if (sum < (INT_MAX - fact)){
                    sum += fact;
                    //printf("pre_Sum = %d + fact(%d) = %d is %d\n", pre_sum, i, fact, sum);
                    if(i == n) printf("%d\n", sum);
                } else {
                    printf("переполнение");
                    break;
                }
            } else {
                printf("переполнение");
                break;
            }
        }
    }
}
    // Ответ на задачу должен быть выведен на консоль







//     for(i; i < 2; i++){
//         if(i == 0) printf("%d\n", if_one);
//         else {
//             do {
//                 //pre_sum = sum;
//                 fact *= i;

//                 if (fact < INT_MAX){
//                     if (sum < (INT_MAX - fact)){
//                         sum += fact;
//                         //printf("pre_Sum = %d + fact(%d) = %d is %d\n", pre_sum, i, fact, sum);
//                         if(i == n) printf("%d\n", sum);
//                     } else {
//                         printf("переполнение");
//                         break;
//                     }
//                 } else {
//                     printf("переполнение");
//                     break;
//                 }
//                 //sum += fact;

//                 i++;
                
            
//             } while (i <= n);
//         }
//     }
// }
  
//   if(n == 0){
//       printf("%d\n", if_one);
//   } else {