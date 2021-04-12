#include "headers.h"
int index_last_zero(int arr[], int count){
    int res;
    int i;
    for(i=0; i < count; i++){
        if (arr[i] == 0) res = i; }
    return res;
}
