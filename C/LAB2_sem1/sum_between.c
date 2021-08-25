#include "headers.h"

int sum_between(int arr[], int count){
    int first_zero_index = index_first_zero(arr, count), 
    last_zero_index = index_last_zero(arr, count), res = 0;

    int index = first_zero_index;

    for(index; index < last_zero_index; index++){
        res += abs(arr[index]);
    }
    return res;
}
