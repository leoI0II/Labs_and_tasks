// /* assert example */
// #include <stdio.h>      /* printf */
// #include <assert.h>     /* assert */

// void print_number(int* myInt) {
//   assert (myInt!=NULL);
//   printf ("%d\n",*myInt);
// }

// int main ()
// {
//   int a=10;
//   int * b = NULL;
//   int * c = NULL;

//   b=&a;

//   print_number (b);
//   print_number (c);

//   return 0;
// }



//#include<time.h>
// #include<stdio.h>
// #include<stdlib.h>
//Задачи на время
//task1 DONE
// void printTimeInfo(time_t time)
// {
//         char* mon[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
//         struct tm *t = gmtime(&time);
//         printf("%d %s %d\n", t->tm_hour, mon[t->tm_mon], 1900+t->tm_year);
        
// }


//task2
// void printTimeInfo(time_t time)
// {
//     char* days[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
//     struct tm *t = *localtime(&time);
//     printf("%d %d %s\n", t->tm_sec, t->tm_mon+1, days[t->tm_wday]);
// }





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//        STRING FUNCS TESTS

// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// #include<ctype.h>
// #include<wchar.h>
// #include<locale.h>

//task2 DONE
// void changeString(char* str)
// {
//     int len = strlen(str);
//     if (islower(str[len - 2])){
//         str[len - 2] = (char)((int)str[len - 2] - 1);
//     }
//     else if (isdigit(str[len - 2])){
//         str[len - 2] = str[len - 1];
//         str[len - 1] = '\0';
//     }
//     else if (isspace(str[len - 2])){
//         str[len - 2] = '\n';
//     }
// }

//task 3 DONE
// void changeString(char* str)
// {
//     int len = strlen(str);
//     if (isdigit(str[len - 2])) str[len - 2] = '\t';
//     if (isalpha(str[len - 2]) && isupper(str[len - 2])) str[len - 2] = (char)((int)str[len - 2] + 1);
//     if (ispunct(str[len - 2])){
//         str[len - 2] = str[len - 1];
//         str[len - 1] = '\0';
//     }
//     return;
// }


// //task4 DONE
// int main()
// {
    // char *str = (char*)malloc(200*sizeof(char));
    // fgets(str, 200, stdin);

    // char* pch;
    // pch = strtok(str, " ");
    // while (pch != NULL)
    // {
    //     printf ("%s\n",pch);
    //     pch = strtok (NULL, " ");
    // }
    

//     return 0;
// }


//task5 DONE
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


//task6 DONE
// void concutTwoStrings(char* str1, char* str2){
//     printf("%s\n", strcat(str1, str2));
// }


//task7 DONE
// void substrTwoStrings(char* str1, char* str2){
//    char *istr;
//    istr = strstr (str1,str2);

//    if ( istr == NULL)
//       printf ("-1");
//    else
//       printf ("%d\n", istr-str1);
// }


//task8 DONE
// void findIndex(char* str1){
//     int i = 0, index = -1;
//     for ( i = 0; i < strlen(str1) - 1; i++){
//         if (str1[i] == '!') index = i;
//     }

//     printf("%d\n", index);
// }



// void clean_buffer()
// {
//     int c;
//     while((c = getchar()) != '\n');
// }

// int main()
// {
//     // char a = 'A';
//     // int b = a;

//     // char s[] = {"Privet"};

//     // printf("%c\n", s[strlen(s)-2]);

//     // s[strlen(s) - 2] = (char)((int)s[strlen(s) - 2] - 1);
//     // printf("%c\n", s[strlen(s)-2]);
//     // printf("%c\n", s[strlen(s) - 1]);

//     // char* str = (char*) malloc (200*sizeof(char));
//     // char* str1 = (char*) malloc (200*sizeof(char));

//     // fgets(str, 200, stdin); clean_buffer();
//     // fgets(str1, 200, stdin);

//     // char *ssss = strstr(str, str1);
//     // printf("%s\n", ssss);

//     char *str1 = (char*) malloc (100*sizeof(char));
//     fgets(str1, 100, stdin);
//     findIndex(str1);

//     return 0;
// }




////////////////////Qsort and BSearch/////////////////////////////////////
//task4
// #include <stdio.h>
// #include<stdlib.h>

// int comp(const void * a, const void * b){
//     return (*(int*)a - *(int*)b);
// }

// int main()
// {
//     int nums[7];
//     for (int i = 0; i < 7; i++) scanf("%d", &nums[i]);

//     int * pInt;
//     int key = 5;
//     pInt = (int*)bsearch (&key, nums, 7, sizeof(int), comp);
    
//     if (pInt != NULL)
//         printf("exists\n");
//     else
//         printf("doesn't exist\n");
    
//     //printf("%ld\n", pInt - nums);

//     return 0;
// }



//task5 DONE
// #include<stdlib.h>
// #include<stdio.h>
// #define SIZE 5

// int comp (const void *n1, const void * n2){
//     return (*(int*)n1 - *(int*)n2);
// }

// int main()
// {
//     int *nums = (int*) malloc (SIZE * sizeof(int));
//     for (int i = 0; i < SIZE; i++) scanf("%d", &nums[i]);

//     int key = 0, *pInt;
//     pInt = (int*) bsearch (&key, nums, SIZE, sizeof(int), comp);
//     printf("%ld\n", pInt- nums +1);

//     return 0;
// }




/////////////////////TESTS/////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// unsigned strl(const char *str)
// {
//     int i = 0;
//     while(str[i++] != '\0');
//     return i-1;
// }

// void strc(char *to, const char *from)
// {
//     while (*(++to) != '\0');
//     while (*from != '\0') *to++ = *from++;
//     *to = '\0';
// }


char* addOneSymbol(char* pstr, size_t* size, size_t* capacity, char symbol) {
    if (!pstr) {
        pstr = (char*)malloc(sizeof(char) * 2);
        pstr[0] = symbol;
        pstr[1] = '\0';
        *size = 2;
        *capacity = 2;
        return pstr;
    }
    if (*size + 1 <= *capacity) {
        pstr[*size-1] = symbol;
        pstr[*size] = '\0';
        ++*size;
        return pstr;
    }
    char* t = (char*)malloc(sizeof(char) * *capacity);
    *capacity += 2;
    strcpy(t, pstr); free(pstr);
    t[*size-1] = symbol; t[*size] = '\0';
    ++*size;
    pstr = t;
    free(t);
    return pstr;
}

char* readText() {
    char* str = NULL;
    size_t capacity = 0;
    size_t size = 0;
    char symbol;
    while ((symbol = fgetc(stdin)) != '\n') {
        // if (!addOneSymbol(&str, &size, &capacity, symbol)) {
        //     return NULL;
        // }
        addOneSymbol(str, &size, &capacity, symbol);
    }
    if (!addOneSymbol(str, &size, &capacity, symbol)) {
        return NULL;
    }
    symbol = fgetc(stdin);
    // if (strcmp(str, "Dragon flew away!") == 0) {
    //     *eof = 1;
    // }
    return str;
}


// void strc(char *to, const char *from)
// {
//     // unsigned int i = strl(to), j = 0;
//     // while(i < strl(to)+strl(from)){
//     //     to[i++] = from[j++];
//     // }
//     // to[i] = '\0';
//     while (*to != '\0'){
//         printf("%c\n", *to);
//         to++;
//     }
//     while (*from != '\0'){
//         printf("%c\n", *from);
//         *to++ = *from++;
//     }
//     *to = '\0';

// }

int main()
{
    // int a[] = {500, 200, 300};
    // int *pa, **pa1;
    // pa = &a;
    // pa1 = &pa;
    // int *pa = &a;

    // printf("%d %d %d %d %d\n", *pa--, *(pa)--, *(pa++), (*pa)++, *pa);


    // printf("%p\n", pa1);

    // int arr[] = {2, 4, 5, 7, 8,3};

    // for (int i = 0; i < sizeof(arr)/sizeof(int); i++){
    //     *(arr + i) += 2;
    // }

    // for (int i = 0; i < sizeof(arr)/sizeof(int); i++){
    //     printf("%d ", *(arr + i));
    // }
    // printf("\n");

    // char str[30], str1[30];
    // scanf("%s", str);
    // scanf("%s", str1);
    // strc(str, str1);
    // printf("%s\n", str);


    // char ch;
    // while ((ch = getchar()) != '#') putchar(ch);


    // int ch;
    // while ((ch = getchar()) != EOF) putchar(ch);


    // // char *head = "Im Millie!";
    // char *head = (char*) malloc(20 * sizeof(char));
    // fgets(head, 20, stdin);
    // printf("%ld\n", strlen(head));
    // head[strlen(head) - 1] = '\0';
    // printf("%ld\n", strlen(head));
    
    // while (*head != '\0') putchar(*(head++));
    // putchar('\n');
    // head = head - 10;
    // // *(head + 3) = 'F';   //Seg fault
    // while (*head != '\0') putchar(*(head++));
    // putchar('\n');

    // char* str = "A";
    // printf("%ld\n", strlen(str));

    char *str = readText();
    printf("%s\n", str);
    return 0;
}


// char* text()
// {
//     char sym;
//     size_t size;
//     char *str = NULL;
//     while((sym = fgetc(stdin)) != '\n') addSym(&size, str, sym);
//     return str;
// }

// void addSym(size_t *size, char* str, char sym)
// {
//     if(!str){
//         str = (char*) malloc (2 * sizeof(char));
//         str[0] = sym;
//         str[1] = '\0';
//         *size = 2;
//         return;
//     }

//     char *st = (char*) malloc (++*size * sizeof(char));
//     strcpy(st, str);
//     free(str);
//     st[*size - 2] = sym;
//     st[*size - 1] = '\0';
//     str = st;
//     return;
// }





char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val){
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n' )
                continue;
    }
    return ret_val;
}