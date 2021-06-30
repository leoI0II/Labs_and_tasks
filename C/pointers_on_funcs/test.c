// #include<stdio.h>
// #include<math.h>
// #include<stdlib.h>

// // void wwa(){
// //     printf("Hello yopta!\n");
// // }

// // void wws(){
// //     printf("Work emae\n");
// // }


// // void aa(void (*aas)(void))
// // {
// //     aas();
// // }


// // int main(){

// //     aa(wwa);
// //     aa(wws);


// //     return 0;
// // }

// /////////////////////////////

// int multiply_2(int a){
//     return 2*a;
// }

// int pow_3(int a){
//     return a*a*a;
// }

// int absolute(int a){
//     return abs(a);
// }

// void forEachElement(int* array, int n, int (*func)(int a)){
//     for (int i = 0; i < n; i++)
//         array[i] = func(array[i]);
// }

// int main(){

//     int size = 500;
//     int arr[size];

//     for(int i = 0; i < size; i++)
//         scanf("%d", &arr[i]);

//     int choice;
//     scanf("%d", &choice);

//     switch(choice){
//         case 1:
//             forEachElement(arr, size, multiply_2);
//             break;
        
//         case 2:
//             forEachElement(arr, size, pow_3);
//             break;

//         case 3:
//             forEachElement(arr, size, absolute);
//             break;
//     }

//     for (int i = 0; i < size; i++){
//         if (i == size-1){
//             printf("%d", arr[i]);
//             continue;
//         }
//         printf("%d\n", arr[i]);
//     }

//     return 0;
// }



/////////////////////////////////////////////////
//2)

// #include <stdio.h>
// #include <stdlib.h>

// int comp1(const void* a,const void* b)
// {
//     if((*(char*)a) > (*(char*)b))
//         return 1;
//     if((*(char*)a) < (*(char*)b))
//         return -1;
//     if((*(char*)a) == (*(char*)b))
//         return 0;
//     return 0;
// }

// int comp4(const void* a,const void* b)
// {
//     if((*(int*)a) > (*(int*)b))
//         return 1;
//     if((*(int*)a) < (*(int*)b))
//         return -1;
//     if((*(int*)a) == (*(int*)b))
//         return 0;
//     return 0;
// }

// int comp8(const void* a,const void* b)
// {
//     if((*(double*)a) > (*(double*)b))
//         return 1;
//     if((*(double*)a) < (*(double*)b))
//         return -1;
//     if((*(double*)a) == (*(double*)b))
//         return 0;
//     return 0;
// }


// int universalMax(void* array,int len,int size,int(*comp)(const void*,const void*))
// {
//     int res = 0;
//     for(int i = 0; i < len ; i++)
//         if (comp((char*)array+i*size, (char*)array + res * size) == 1)
//             res=i;

//     return res;
// }

// int main() {
//     int size=0;
//     char c = 0;
//     int(*f)(const void*,const void*);
//     void* arr;
//     scanf("%d",&size);
//     switch(size)
//     {
//         case 1:
//             arr = malloc(sizeof(char) * 20);
//             for (int i = 0; i < 20; i++)
//             {
//                 scanf("%c%c", &c, (char*)arr+i);
//             }
//             f = &comp1;
//             break;
//         case 4:
//             arr = malloc(sizeof(int) * 20);
//             for (int i = 0; i < 20; i++)
//             {
//                 scanf("%d", (int*)arr+i);
//             }
//             f = &comp4;
//             break;
//         case 8:
//             arr = malloc(sizeof(double) * 20);
//             for (int i = 0; i < 20; i++)
//             {
//                 scanf("%lf", (double*)arr+i);
//             }
//             f = &comp8;
//             break;
//     }
//     int res = universalMax(arr, 20, size, f);
//     printf("%d", res);

//     return 0;
// }



/////////////////////////////////////////
//3)

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int cmp(const void** a,const void** b)
// {
//     if(strlen(*((char**)a)) < strlen(*((char**)b)))
//         return -1;
//     if(strlen(*((char**)a)) == strlen(*((char**)b)))
//         return 0;
//     if(strlen(*((char**)a)) > strlen(*((char**)b)))
//         return 1;
//     return 0;
// }

// int main()
// {
//     char input[1000];
//     fgets(input, 1000, stdin);

//     int s = 0;
//     char* c = strchr(input, '.');
//     while(c)
//     {
//         s++;
//         c = strchr(c+1, '.');
//     }
//     char** arr = malloc(sizeof(char*)*s);
//     int i = 0;

//     char * pch;
//     pch = strtok (input,".");
    
//     while (pch != NULL)
//     {
//         if(*pch == ' ')
//             arr[i] = pch + 1;
//         else
//             arr[i] = pch;
//         i++;
//         pch = strtok(NULL, ".");
//     }

//     qsort(arr, s, sizeof(char*), (int(*)(const void*,const void*))cmp);

//     for(int j = 0; j < s-1; j++)
//     {
//         printf("%s. ", arr[j]);
//     }
//     printf("%s.", arr[s-1]);
//     return 0;
// }


//////////////////////////////////////////////////////////
//4)

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>


// typedef struct Book {

//     char name[30];
//     char author[30];
//     unsigned int pages;
//     char isbn[20];
// } Book;

// int cmp(const void* a, const void* b)
// {
//     return strcmp(((Book*)b)->author, ((Book*)a)->author);
// }

// int main()
// {
//     int n = 0;
//     scanf("%d\n", &n);

//     Book *books = malloc(sizeof(Book) * n);

//     for(int i = 0; i < n; i++)
//     {
//         scanf("%s %s %d %s", books[i].name, books[i].author, &books[i].pages, books[i].isbn);
//     }

//     qsort(books, n, sizeof(Book), (int(*)(const void*, const void*))cmp);
//     for(int i = 0; i < n - 1; i++)
//     {
//         printf("%s %s %d %s ",books[i].name,books[i].author,books[i].pages,books[i].isbn);
//     }

//     printf("%s %s %d %s",books[n-1].name,books[n-1].author,books[n-1].pages,books[n-1].isbn);

//     return 0;
// }

/////////////////////////////////////////////////////
//5)

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>


// typedef struct Country {

//     char name[30];
//     unsigned int population;
//     char capital[30];

// } Country;

// int cmp(const void* a,const void* b)
// {
//     int r = strcmp(((Country*)a)->name, ((Country*)b)->name);
//     if (r == 0)
//         return (int)(((Country*)a)-> population - ((Country*) b)->population);

//     return r;
// }

// int main()
// {
//     int n = 0;
//     scanf("%d\n", &n);

//     Country *books = malloc(sizeof(Country) * n);
    
//     for(int i = 0; i < n; i++)
//         scanf("%s %d %s", books[i].name, &books[i].population, books[i].capital);

//     qsort(books, n, sizeof(Country), (int(*)(const void*,const void*))cmp);

//     for(int i = 0; i < n-1; i++)
//         printf("%s %d %s ",books[i].name, books[i].population, books[i].capital);

//     printf("%s %d %s", books[n-1].name, books[n-1].population, books[n-1].capital);

//     return 0;
// }


//////////////////////////////////////
// #include<stdio.h>
// #include<stdlib.h>

// int cmp1(const void* a, const void* b){
//     return *(char*)a - *(char*)b;
//     // if (*(char*)a > *(char*)b)
//     //     return 1;
//     // else if (*(char*)a < *(char*)b)
//     //     return -1;
//     // else return 0;
// }

// int cmp4(const void* a, const void* b){
//     return *(int*)a - *(int*)b;
//     // if (*(int*)a > *(int*)b)
//     //     return 1;
//     // else if (*(int*)a < *(int*)b)
//     //     return -1;
//     // else 
//     //     return 0;
// }

// int cmp8(const void* a, const void* b){
//     return *(double*)a - *(double*)b;
//     // if (*(double*)a > *(double*)b)
//     //     return 1;
//     // else if (*(double*)a < *(double*)b)
//     //     return -1;
//     // else 
//     //     return 0;
// }

// int universalMax(void* array, int count, int size, int (*cmp)(const void* a, const void* b))
// {
//     int max = 0;
//     for (int i = 0; i < count; i++){
//         if (cmp(array+i*size, array+max*size) > 0)
//             max = i;
//     }
//     return max;
// }

// int main()
// {
//     long size;
//     scanf("%ld", &size);
//     int count = 20;
//     void* array;
//     char ch;
//     int res;
//     switch(size){
//         case 1:
//             array = (char*) malloc (count);
//             for (int i = 0; i < count; i++)
//                 scanf("%c%c", &ch, (char*)array + i);
//             res = universalMax(array, count, sizeof(char), cmp1);
//             break;
        
//         case 4:
//             array = (int*) malloc (count * sizeof(int));
//             for (int i = 0; i < count; i++)
//                 scanf("%d", (int*)array + i);
//             res = universalMax(array, count, sizeof(int), cmp4);
//             break;

//         case 8:
//             array = (double*) malloc (count * sizeof(double));
//             for (int i = 0; i < count; i++)
//                 scanf("%lf", (double*)array + i);
//                 res = universalMax(array, count, sizeof(double), cmp8);
//             break;
//     }
//     printf("%d\n", res);

//     return 0;
// }


////////////////////////////////////////////////////////////////
// #include<stdio.h>
// int main(){
//     printf("%ld %ld\n", sizeof(float), sizeof(double));
//     return 0;
// }