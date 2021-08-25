#include <stdio.h>

int main(){

    int A[15];

    int count = 0;
    char space = ' ';
    while (space == ' ' && count < 15){
        scanf("%d%c", &A[count], &space);
        count += 1;
    }

    int B[15];
    for (int j = 0; j < count; j++){
        if (j-1 == -1){
            //A[j-1] = 0; A[j+1] = 0;
            if (A[j+1] >= 0) B[j] = 0 - A[j+1];
            else B[j] = 0 + A[j+1];
        } else if ( j+1 == 15 ){
            if ( A[j-1] >= 0 ) B[j] = A[j-1] - 0;
            else B[j] = A[j-1] + 0;
        } else {    
            if ( (A[j+1] < 0 && A[j-1] > 0) || (A[j+1] > 0 && A[j-1] < 0) ){
                B[j] = A[j-1] + A[j+1];
            } else {
                B[j] = A[j-1] - A[j+1];
            }
        }
    }

    for (int i = 0; i < count; i++){
        if (count == 14) printf("%d\n", B[count]);
        else printf("%d ", B[count]);
    }

    return 0;
}