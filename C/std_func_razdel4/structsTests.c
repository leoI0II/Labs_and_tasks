// #include<stdio.h>
// #include<stdlib.h>
// #define NLEN 20

// typedef struct Student
// {
//     char fname[NLEN];
//     char lname[NLEN];
//     int ball;
// } Student;

// int main()
// {
//     int cS;
//     puts("Enter count of students:");
//     scanf("%d", &cS);
//     Student students[cS];
//     puts("Enter first name, last name and his point:");
//     for (int i = 0; i < cS; i++){
//         printf("%d student: ", i+1);
//         scanf("%s %s %d", students[i].fname, students[i].lname, &students[i].ball);
//     }

//     double srAr = 0;
//     for (int i = 0; i < cS; i++) srAr += students[i].ball;
//     srAr = srAr / (float)cS;

//     printf("\n");
//     printf("Medium point is %f\n", srAr);
//     puts("Student(s) with point better medium:");

//     for (int i = 0; i < cS; i++)
//     {
//         if (students[i].ball > srAr)
//             printf("%s %s %d\n", students[i].fname, students[i].lname, students[i].ball);
//     }

//     return 0;
// }



// #include<stdio.h>
// #include<stdlib.h>
// #include <time.h>
// #include<string.h> 
// // for (int l = 0; text[l] == pattern[l]; l++) if (text[l] == '\0' && pattern[l] == '\0') return 0;

// int strstr1(const char *text, const char *pattern){
//     // printf("%s %s\n", text, pattern);
//     // puts("1");
//     if (text == pattern) return 0;
//     // puts("2");
//     if (pattern == "" || (pattern == "" && text == "")) return 0;
//     // puts("3");
//     if (text == "" && (strlen(pattern) > 0)) return -1;
//     // puts("4");
//     if (strlen(text) < strlen(pattern)) return -1;
//     // puts("5");
//     char *tt = text, *tp = pattern;
//     while (*text){
//         // char *cpT = text;
//         // printf("%c\n", *cpT);
//         if (*text == *pattern){
//             // puts("in IF");
//             int pos = text - tt;
//             // printf("%d\n", pos);
//             while (*(text++) == *(pattern++) && *pattern != '\0'){
//                 // printf("%c %c\n", *text, *pattern);
//             }
//             if (*pattern == '\0') return pos;
//             pattern = tp;
//         }
//         ++text;
//     }
// }


// int main()
// {
//     char *a = "Hello world!";
//     char *p = "world";
//     // if (a == "") printf("Work");
//     // printf("%ld \t%ld\n", sizeof(a)/sizeof(char), strlen(a));
//     printf("%d\n", strstr1(a, p));
//     return 0;
// }









// void sleep(float msec)
// {
//     unsigned int shotTime = clock();
//     while(clock()/CLOCKS_PER_SEC - shotTime/CLOCKS_PER_SEC < msec) {}
// }


// void slepp(int ms) {
//     int CLOCKS_PER_MSEC = CLOCKS_PER_SEC / 1000; 
//     clock_t end_time = clock() + ms * CLOCKS_PER_MSEC ;
//     while (clock() < end_time) {}
// }


// typedef struct testNum Lolo;

// struct testNum{
//     int x;
//     int y;
// } nums;

// void changeNum(Lolo *pstr)
// {
//     pstr->x = 300;
//     pstr-> y = 155;
// }

// int main()
// {
    // nums.x = 30;
    // nums.y = 35;

    // Lolo nums2 = {25, 40};

    // printf("Num1 %d \tNum2 %d\n", nums.x, nums.y);
    // printf("Num2_1 %d \tNum2_2 %d\n", nums2.x, nums2.y);

    // changeNum(&nums2);

    // printf("\n\nNum1 %d \tNum2 %d\n", nums.x, nums.y);
    // printf("Num2_1 %d \tNum2_2 %d\n", nums2.x, nums2.y);


    // Lolo *pnums2 = &nums2;
    // pnums2 -> x = 3000;
    // pnums2 -> y = 2300;

    // printf("\n\nNum1 %d \tNum2 %d\n", nums.x, nums.y);
    // printf("Num2_1 %d \tNum2_2 %d\n", nums2.x, nums2.y);



    // kruzhok zagruzki
    // for (int i = 1; i < 1000000; i++){
    //     if (i % 3 == 1){
    //         puts("\\");
    //         slepp(150);
    //         system("clear");
    //         continue;
    //     }
    //     if (i % 3 == 2){
    //         puts("/");
    //         slepp(150);
    //         system("clear");
    //         continue;
    //     }
    //     if (i % 3 == 0){
    //         puts("--");
    //         slepp(150);
    //         system("clear");
    //         continue;
    //     }
    //     if(i == 99998) i = 1;
    // }

    // size_t i = 0;
    // i = system("cd && ls");
    // printf("%ld\n", i);


//     return 0;
// }

























//Def Lab
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<wchar.h>
#include<locale.h>
#include<math.h>

// #define SIZE 10000

// int cmp(const void *a, const void *b) 
// {
//     const double *ad, *bd;
    
//     ad = (const double*)a;
//     bd = (const double*)b;
   
//     if (*ad < *bd) 
//     {   
//         return -1;   
//     }   
//     else if (*ad > *bd)
//     {   
//         return 1;
//     }   
//     else
//     {   
//         return 0;
//     }   
// }

// int main()
// {
//     char *nums = (char*) malloc (SIZE * sizeof(char));

//     fgets(nums, SIZE, stdin);
//     nums[(strlen(nums)) - 1] = '\0';
//     // printf("%s", nums);
//     // char *numscpy = (char*) malloc (SIZE * sizeof(char));
//     double *numses = (double *) malloc (sizeof(double));
//     char *pch;
//     size_t i = 1;
//     pch = strtok(nums, " ");
//     while (pch != NULL){
//         numses[i-1] = atof(pch);
//         pch = strtok(NULL, " ");
//         ++i;
//         numses = realloc(numses, i * sizeof(double));
//     }
//     // for (int j = 0; j < i - 1; j++) printf("%f ", numses[j]);
//     puts("!!");

//     qsort(numses, i-1, sizeof(double), cmp);

//     for (int j = 0; j < i - 1; j++) printf("%g ", numses[j]);

//     // int count = 0;
//     // double nums[SIZE];
//     // for (int i = 0; i < SIZE || getchar() != '\n'; i++){
//     //     scanf("%lf", &nums[i]);
//     //     ++count;
//     // }

//     // qsort(numses, i, sizeof(double), cmp);

//     // for (int i = 0; i < i; i++) printf("%f ", numses[i]);


//     return 0;
// }

// 2nd task DONE
// int main()
// {   
//     setlocale(LC_ALL, "");

//     wchar_t *str = (wchar_t*) malloc (1000 * sizeof(wchar_t));

//     fgetws (str, 100, stdin);
//     str[wcslen(str)-1] = L'\0';
//     wchar_t* strc = (wchar_t*) malloc (wcslen(str) *sizeof(wchar_t));
//     wcscpy(strc, str);
//     free(str);

//     wchar_t** pstr = (wchar_t**) malloc (sizeof(wchar_t*));
//     wchar_t* pt;
//     wchar_t* pwc;

//     pwc = wcstok(strc, L"уеёыаоэяию -", &pt);
//     int i = 1;
//     while (pwc != NULL)
//     {
//         pstr = (wchar_t**) realloc (pstr, (i+1) * sizeof(wchar_t*));
//         pstr[i-1] = pwc;
//         i++;
//         pwc = wcstok(NULL, L"уеёыаоэяию -", &pt);
//     }

//     for (int j = 0; j < i-1; j++)
//         wprintf(L"%ls ", pstr[j]);

//     // wprintf(L"%ls\n", strcpy);

//     return 0;
// }

// int main ()
// {
//     setlocale(LC_ALL, "");
//     wchar_t *wcs = (wchar_t*) malloc (200 * sizeof(wchar_t));
//     fgetws(wcs, 200, stdin);
//     wchar_t * pwc;
//     wchar_t * pt;
    
//     pwc = wcstok (wcs, L" -,", &pt);
//     while (pwc != NULL)
//     {
//         wprintf (L"%ls\n",pwc);
//         pwc = wcstok (NULL, L" -,", &pt);
//     }
//     return 0;
// }





// Sort coordinates points DONE
// typedef struct Point{
//     int x;
//     int y;
// } point;


// int comp (const void *a, const void *b)
// {
//     point* c1 = (point*) a;
//     point* c2 = (point*) b;

//     double rast1 = sqrt( pow((double)c1->x, 2.0) + pow((double)c1->y, 2.0));
//     double rast2 = sqrt( pow((double)c2->x, 2.0) + pow((double)c2->y, 2.0));

//     if (rast1 == rast2)
//     {
//         return c1->x - c2->x;
//     }
//     if (rast1 > rast2) return 1;
//     else return -1;
// }


// int main()
// {
//     // point* arr = (point*) malloc (7 * sizeof(point));
//     point arr[7];
//     for (int i = 0; i < 7; i++)
//         scanf("%d%d", &arr[i].x, &arr[i].y);

//     qsort(arr, 7, sizeof(point), comp);

//     printf("| ");
//     for (int i = 0; i < 7; i++)
//         printf("%d %d | ", arr[i].x, arr[i].y);
//     printf("\n");

//     for (int i = 0; i < 7; i++)
//         printf("%lf\n", sqrt(pow((double)arr[i].x, 2.0) + pow((double)arr[i].y, 2.0)));

//     return 0;
// }




// Making own strtok +- DONE

// char *strtokk(char *str, const char *delim)
// {
//     static const char *string;
//     if (str != NULL) 
//         string = str;

//     if (string == NULL) return NULL;
    
//     int i = 0;
//     char *retStr = (char*) malloc (strlen(string) * sizeof(char));

//     for (i; string[i] != '\0'; i++)
//     {
//         for (int j = 0; j < strlen(delim); j++)
//         {
//             if (string[i] == delim[j] && i != 0){
//                 retStr[i] = '\0';
//                 string += i+1;
//                 return retStr;
//             }
//             else continue;
//         }
//         retStr[i] = string[i];
//     }
//     retStr[i+1] = '\0';
//     string = NULL;
//     return retStr;
// }

// int main()
// {
//     char *str = (char*) malloc (50*sizeof(char));
//     fgets(str, 50, stdin);
//     str[strlen(str)-1] = '\0';

//     char *pch = strtokk(str, " ,");
//     while (pch != NULL){
//         printf("%s\n", pch);
//         pch = strtokk(NULL, " ,");
//     }
//     return 0;
// }



// int main()
// {
//     char *str = (char*) malloc (50*sizeof(char));
//     fgets(str, 50, stdin);
//     str[strlen(str)-1] = '\0';

//     printf("%s\n", str);

//     char *pch = strtok(str, " ");
//     printf("%s\n", pch);
//     pch = strtok(NULL, " ");
//     printf("%s\n", pch);
//     // char *pch = strtok(str, " ");
    
//     printf("%s\n", str);

//     // printf("%zu\n", sizeof(int));

//     return 0;
// }


typedef struct hello{
    int data;
    int lol;
    int kek;
}shalom;

// int main()
// {
//     shalom* a;
//     shalom *b;

//     a->data = 5;
//     a->kek = 120;
//     printf("%d %d %d\n", a->data, a->lol, a->kek);
//     printf("%d\n", *a);
//     b = a;
//     printf("%d %d\n", b->data, b->kek);

//     return 0;
// }

int main()
{
    shalom* a = (shalom*) malloc (sizeof(shalom));
    shalom* b = (shalom*) malloc (sizeof(shalom));

    a->data = 23;
    a->kek = 94;

    printf("%d %d %d\n", a->data, a->lol, a->kek);

    *b = *a;
    printf("%d %d\n", b->data, b->kek);

    return 0;
}