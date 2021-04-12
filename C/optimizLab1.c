#include <stdio.h>
#define SIZE 100
#include <stdlib.h>

int index_first_zero(int arr[], int count); // в аргументах массив
int index_last_zero(int arr[], int count);
int sum_between(int arr[], int count);
int sum_before_and_after(int arr[], int count);



int main(){
    
    int choice, arr[SIZE], count = 0;
    char space = ' ';
    scanf("%d", &choice);

    while(count < 100 && space == ' '){
        scanf("%d%c", &arr[count], &space);
        ++count;
    }

    // int arrCopy[count];
    // for(int j = 0; j < count; j++){
    //     arrCopy[j] = arr[j];
    // }

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


int index_first_zero(int arr[], int count){
    int res;
    for(int i=0; i < count; i++){
        if (arr[i] == 0){
            res = i;
            break;
        }
    } return res;
}


int index_last_zero(int arr[], int count){
    int res;
    for(int i=0; i < count; i++){
        if (arr[i] == 0) res = i; }
    return res;
}


int sum_between(int arr[], int count){
    int first_zero_index, last_zero_index, res = 0;
    for(int i=0; i < count; i++){
        if (arr[i] == 0){
            first_zero_index = i; 
            break; }
    }
    for(int i=0; i < count; i++){
        if (arr[i] == 0) last_zero_index = i;
    }


    for(int index = first_zero_index; index < last_zero_index; index++){
        res += abs(arr[index]);
    }
    return res;
}


int sum_before_and_after(int arr[], int count){
    int first_zero_index, last_zero_index, res_before = 0, res_after = 0;
    for(int i=0; i < count; i++){
        if (arr[i] == 0){
            first_zero_index = i; 
            break; }
    }
    for(int i=0; i < count; i++){
        if (arr[i] == 0) last_zero_index = i;
    }


    for(int i = 0; i < first_zero_index; i++){
        res_before += abs(arr[i]);
    }
    for(int i = last_zero_index; i < count; i++){
        res_after += abs(arr[i]);
    }
    return res_before + res_after;
}
