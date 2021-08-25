#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// int main(){

//     int d;
//     scanf("%d", &d);
//     // int c = 1;
//     // d++;
//     int res = 0;
//     do {
//         d /= 10;
//         ++res;
//     } while (d);

//     printf("%d\n", res);

//     return 0;
// }

int a1(const void* a){
    return (*(int*)a % 2 == 0 ? 1 : 0);
}

int a2(const void* a){
    if (*(double*)a < 0)
        *(double*)a = *(double*)a * (-1);

    int aa = (int)*(double*)a;

    int flag_1 = 0;
    if (aa % 2 == 0)
        flag_1 = 1;
    else
        return 0;

    int flag_2 = 0;
    if (*(double*)a - aa <= 0.000001)
        flag_2 = 1;
    else return 0;
    
    if (flag_2 == 1 && flag_1 == 1)
        return 1;
    else return 0;
}

int count_if(void* base, size_t num, size_t size, int (*pred)(const void*)){
    int res = 0;

    for (int i = 0; i < num; i++)
        if(pred((char*)base+i*size) == 1)
            ++res;
    return res;
}

int main(){

    int count = 20;
    void *arr;
    int size;
    scanf("%d", &size);
    int res = 0;
    switch(size){
        case 4:
            arr = (int*) malloc (count* sizeof(int));
            for (int i = 0; i < count; i++)
                scanf("%d", (int*)arr+i);
            
            res = count_if(arr, count, sizeof(int), a1);
            break;
        
        case 8:
            arr = (double*) malloc (count* sizeof(double));
            for (int i = 0; i < count; i++)
                scanf("%lf", (double*)arr+i);

            res = count_if(arr, count, sizeof(double), a2);
            break;
    }

    printf("%d\n", res);



    return 0;
}


// typedef struct Map {
//     char* id;
//     char* value;
//     struct Map *next;
// } map;

// map* head = NULL;

// void add_elem(char* key, char* str){
//     if (head == NULL){
//         map* new = (map*) malloc (sizeof(map));
//         head = new;
//         new->id = (char*) malloc (strlen(key) +1);
//         strcpy(new->id, key);
//         new->value = (char*) malloc (strlen(str) + 1);
//         strcpy(new->value, str);
//         new->next = NULL;
//         return;
//     }

//     map *tmp = head, *h = head;
//     head = head->next;

//     while (head){
//         tmp = head;
//         head = head->next;
//     }

//     map* new = (map*) malloc (sizeof(map));
//     tmp->next = new;
//     head = new;
//     new->id = (char*) malloc (strlen(key) + 1);
//     strcpy(new->id, key);
//     new->value = (char*) malloc (strlen(str) + 1);
//     strcpy(new->value, str);
//     new->next = NULL;

//     head = h;
// }

// void pop(char* id){
//     map* h = head;
//     if (head == NULL){
//         printf("Error!\n");
//         exit(1);
//     }

//     map* tmp = head;
//     head = head->next;
//     if (head == NULL){
//         head = tmp;
//         free(head);
//         return;
//     }
//     if (strcmp(tmp->id, id) == 0){
//         free(tmp);
//         return;
//     }

//     while (head && strcmp(head->id, id)){
//         tmp = head;
//         head = head->next;
//     }

//     tmp->next = head->next;
//     free(head);

//     head = h;
//     return;
// }

// char* get_value(char* id){
//     map* h = head;
//     map* tmp = head;

//     if (strcasecmp(tmp->id, id) == 0){
//         head = h;
//         return tmp->value;
//     }
//     head = head->next;
//     while (head){
//         if (strcasecmp(head->id, id) == 0){
//             head = h;
//             return tmp->next->value;
//         }
//         tmp = head;
//         head = head->next;
//     }
//     char* sss = "<unknown>";
//     head = h;
//     return sss;

// }

// void check_map(){
//     map* h = head;

//     while (head){
//         printf("Key: %s, value: %s\n", head->id, head->value);
//         head = head->next;
//     }
//     head = h;
// }

// void clean_buff(){
//     while(getchar() != '\n'){;}
// }


// int main(){

//     char str[200];
//     char* ch = "ugabuga";
//     char** arr = (char**) malloc (200* sizeof(char*));
//     for (int i = 0; i < 200; i++)
//         arr[i] = (char*) malloc (200*sizeof(char));

//     int d = 0;

//     scanf("%s", str);
//     while(strcmp(str, ch)){
//         strcpy(arr[d], str);
//         d++;
//         scanf("%s", str);
//     }

//     // for (int i = 0; i < d; i++)
//     //     printf("%s\n", arr[i]);

//     for (int i = 0 ; i < d; i += 2){
//         add_elem(arr[i], arr[i+1]);
//     }

//     clean_buff();

//     char to_tr[200];
//     fgets(to_tr, 200, stdin);
//     to_tr[strlen(to_tr) - 1] = '\0';

//     char* a[200];
//     for (int i = 0; i < 200; i++)
//         a[i] = (char*) malloc (200);
//     int q = 0;
//     char* pch = strtok(to_tr, " ");
//     while(pch != NULL){
//         strcpy(a[q], pch);
//         q++;
//         pch = strtok(NULL, " ");
//     }

//     for (int i = 0; i < q-1; i++)
//         printf("%s ", get_value(a[i]));
//     printf("%s\n", get_value(a[q-1]));

    




//     return 0;
// }