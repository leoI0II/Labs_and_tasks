#include <stdio.h>
#include <stdlib.h>


int main(){

    // float * arr1 = malloc(10 * sizeof(float));
    // arr1[0] = 100.0;

    // printf("%f\n", *arr1);

    // float *arr3 = realloc(arr1, 50 * sizeof(float));

    // printf("%f\n", *arr3);

    // if (arr3 != NULL) arr1 = arr3;

    // printf("1)%f 2)%f\n", arr1, arr3);

    
    long long array =/*(long long *)*/ calloc(200, sizeof(long long));

    array = 2000000;
    printf("First elem %lld\n", array);


    return 0;
}