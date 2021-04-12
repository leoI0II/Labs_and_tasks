#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 1000

int * arrCpy(int* a, int len){
    int * b = (int*) malloc (len* sizeof(int));
    for (int i = 0; i < len; i++) b[i] = a[i];
    return b;
}

void swap(int *n1, int *n2){
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void BubbleSort(int *arr, int len){
    for (int i = 0; i < len - 1; i++){
        for (int j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
    }
}

int comp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int main()
{
    //adding nums
    int *nums = (int*) malloc (SIZE * sizeof(int));
    for (int i = 0; i < SIZE; i++) scanf("%d", &nums[i]);
    
    //copying nums to another array
    int *numscpy = arrCpy(nums, SIZE);
    
    //on clock
    clock_t timeBS = clock();

    //Bubble sort
    BubbleSort(nums, SIZE);
    //stop time for bubble sort
    timeBS = clock() - timeBS;
    
    //on clock for QSort
    clock_t timeQS = clock();
    //QSort
    qsort(numscpy, SIZE, sizeof(int), comp);
    //stop time
    timeQS = clock() - timeQS;

    for (int i = 0; i < SIZE; i++) printf("%d ", numscpy[i]);
    printf("\n");
    printf("%f\n%f\n", ((float)timeBS)/CLOCKS_PER_SEC, ((float)timeQS)/CLOCKS_PER_SEC);

    return 0;
}
