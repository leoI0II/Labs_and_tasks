#include "headers.h"
int index_first_zero(int arr[], int count){
    int res, i;
    for(i=0; i < count; i++){
        if (arr[i] == 0){
            res = i;
            break;
        }
    } return res;
}
