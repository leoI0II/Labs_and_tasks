// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// char* merge(char* str1, char* str2);

// void clean_buffer()
// {
//     int c;
//     while((c = getchar()) != '\n');
// }


//#3
// int main(){
    
//     int str1_len;
//     int str2_len;
//     scanf("%i %i", &str1_len, &str2_len); clean_buffer();
//     //char str1[str1_len], str2[str2_len];
//     char* str1;
//     char* str2;
    
//     str1 = calloc((str1_len+1), sizeof(char));
//     str2 = calloc((str2_len+1), sizeof(char));

//     // int i = 0;
//     // while( i <= str1_len ){
//     //     *(str1 + i) = getchar();
//     //     i++;
//     // }
//     // i = 0;
//     // while( i <= str2_len ){
//     //     *(str2 + i) = getchar();
//     //     i++;
//     // }

//     // scanf("%s", str1);
//     // scanf("%s", str2);
    
//     fgets(str1, str1_len+1, stdin); clean_buffer();
//     fgets(str2, str2_len+1, stdin); //clean_buffer();

// //    printf("%s %s\n", str1, str2);

//     printf("%s\n", merge(str1, str2));
// }

// char* merge(char* str1, char* str2){
//     char* mergedStr;
//     //printf("Enter at function\n");
//     if( strlen(str1) == strlen(str2) ){
//         //printf("Same strings\n");
//         mergedStr = malloc( (strlen(str1) + strlen(str2)) * sizeof(char) ); int j;
//         for( int i = 0; i < strlen(str1)*2; i++ ){
//             //printf("%i iteration\n", i);
//             *(mergedStr + i) = *(str + i); j = i++
//         }
//         return mergedStr;
//     } else if ( strlen(str1) > strlen(str2) ){
//         printf("First in bigger\n");
//         mergedStr = malloc( (strlen(str1) + strlen(str2)) * sizeof(char) );
        
//         for (int i = 0; i < strlen(str2); i++){
//             strcat( mergedStr, str1[i] ); strcat( mergedStr, str2[i] );
//         }
//         for ( int i = strlen(str2) ; i < strlen(str1); i++){
//             strcat( mergedStr, str1[i] );
//         }
//         return mergedStr;
//     } else {
//         printf("Second is bigger\n");
//         mergedStr = malloc( (strlen(str1) + strlen(str2)) * sizeof(char) );
        
//         for (int i = 0; i < strlen(str1); i++){
//             strcat( mergedStr, str1[i] ); strcat( mergedStr, str2[i] );
//         }
//         for (int i = strlen(str1); i < strlen(str2); i++){
//             strcat( mergedStr, str1[i] );
//         }
//         return mergedStr;
//     }
// }


// char* merge(char* str1, char* str2){
//     char* mergedStr;
//     printf("%ld %ld\n", strlen(str1), strlen(str2));
//     int str_len_new = strlen(str1) + strlen(str2), glob = 0, fir = 0, sec = 0;
//     mergedStr = malloc((str_len_new) * sizeof(char));

//     while( glob < str_len_new ){
//         if(fir < strlen(str1)){
//             mergedStr[glob] = str1[fir];
//             glob++;
//             fir++;
//         }
//         if(sec < strlen(str2)){
//             mergedStr[glob] = str2[sec];
//             glob++;
//             sec++;
//         }
//     }
//     return mergedStr;
// }



//#3
// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>

// char* merge(char* str1, char* str2);

// int main()
// {
//     int str1_len;
//     int str2_len;
//     scanf("%i %i", &str1_len, &str2_len);
//     str1_len+=1; str2_len+=1;
//     char* str1;
//     char* str2;

//     str1 = malloc(str1_len * sizeof(char));
//     str2 = malloc(str2_len * sizeof(char));
//     scanf("%s", str1);
//     scanf("%s", str2);
//     printf("%s", merge(str1, str2));
// }

// char* merge(char* str1, char* str2)
// {
//     int str3_len = strlen(str1) + strlen(str2);
//     char *str3 = malloc(str3_len * sizeof(char));
//     int k = 0, i = 0,j = 0;
//     for( ;k < str3_len ; ){
//         if( i < strlen(str1) ){
//             str3[k++] = str1[i++];
//         }
//         if( j < strlen(str2) ){
//             str3[k++] = str2[j++];
//         }
//     }
//     return str3;
// } 




//#4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clean_buffer()
{
    int c;
    while((c = getchar()) != '\n');
}

int substr(char* str1, char* str2, int** result);

int main()
{
    int str1_len;
    int str2_len;
    scanf("%i %i", &str1_len, &str2_len);
    clean_buffer();

    char* str1 = malloc ((str1_len + 1) * sizeof(char)); 
    char* str2 = malloc ((str2_len + 1) * sizeof(char)); 
    
    fgets(str1, str1_len + 1, stdin); clean_buffer();
    fgets(str2, str2_len + 1, stdin); clean_buffer();

    int* result = (int *) calloc ((str1_len + 2 + str2_len), sizeof(int));
    int arr_len = substr(str1, str2, &result), i = 0;

    for( i; i < arr_len; i++ ) printf("%i ", result[i]);
}

int substr(char* str1, char* str2, int** result)
{
    int *s = *result, count = 0;;
    char *res = str2;

    while ( res = strstr(res, str1) ){
        s[count] = (int)( res - str2 );
        *res++; count++;
    }
    
    return count;
}
