#include "headers.h"

int sum_before_and_after(int arr[], int count){
    int first_zero_index = index_first_zero(arr, count), 
    last_zero_index = index_last_zero(arr, count), res_before = 0, res_after = 0;

    int i;
    for(i = 0; i < first_zero_index; i++){
        res_before += abs(arr[i]);
    }
    int j;
    for(j = last_zero_index; j < count; j++){
        res_after += abs(arr[j]);
    }
    return res_before + res_after;
}
