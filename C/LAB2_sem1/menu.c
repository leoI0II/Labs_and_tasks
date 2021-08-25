#include "headers.h"
#define SIZE 100
//#include "index_first_zero.h"
//#include "index_last_zero.h"
//#include "sum_between.h"
//#include "sum_before_and_after.h"

int main(){
    
    int choice, arr[SIZE], count = 0;
    char space = ' ';
    scanf("%d", &choice);

    while(count < SIZE && space == ' '){
        scanf("%d%c", &arr[count], &space);
        ++count;
    }

    switch(choice){
        case 0:
            printf("%d\n", index_first_zero(arr, count));
            break;
        case 1:
            printf("%d\n", index_last_zero(arr, count));
            break;
        case 2:
            printf("%d\n", sum_between(arr, count));
            break;
        case 3:
            printf("%d\n", sum_before_and_after(arr, count));
            break;
        default:
            printf("Данные некорректны");
    }

    return 0;
}
