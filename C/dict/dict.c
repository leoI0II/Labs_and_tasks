#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


typedef struct Map {
    char* id;
    char* value;
    struct Map *next;
} map;

map* head = NULL;

void add_elem(char* key, char* str){
    if (head == NULL){
        map* new = (map*) malloc (sizeof(map));
        head = new;
        new->id = (char*) malloc (strlen(key) +1);
        strcpy(new->id, key);
        new->value = (char*) malloc (strlen(str) + 1);
        strcpy(new->value, str);
        new->next = NULL;
        return;
    }

    map *tmp = head, *h = head;
    head = head->next;

    while (head){
        tmp = head;
        head = head->next;
    }

    map* new = (map*) malloc (sizeof(map));
    tmp->next = new;
    head = new;
    new->id = (char*) malloc (strlen(key) + 1);
    strcpy(new->id, key);
    new->value = (char*) malloc (strlen(str) + 1);
    strcpy(new->value, str);
    new->next = NULL;

    head = h;
}

void pop(uint id){
    map* h = head;
    if (head == NULL){
        printf("Error!\n");
        exit(1);
    }

    map* tmp = head;
    head = head->next;
    if (head == NULL){
        head = tmp;
        free(head);
        return;
    }
    if (strcmp(tmp->id, id) == 0){
        free(tmp);
        return;
    }

    while (head && strcmp(head->id, id)){
        tmp = head;
        head = head->next;
    }

    tmp->next = head->next;
    free(head);

    head = h;
    return;
}

char* get_value(uint id){
    map* h = head;
    map* tmp = head;

    if (tmp->id == id){
        head = h;
        return tmp->value;
    }
    head = head->next;
    while (head){
        if (head->id == id){
            head = h;
            return tmp->next->value;
        }
        tmp = head;
        head = head->next;
    }
    printf("id incorrect!\n");
    head = h;
    return NULL;

}

void check_map(){
    map* h = head;

    while (head){
        printf("Key: %d, value: %s\n", head->id, head->value);
        head = head->next;
    }
    head = h;
}

int main(){

    add_elem(23, "Hello world for this dict");
    add_elem(12, "ultron is so-so");
    add_elem(34, "Avengers are good");
    add_elem(33, "vision isnt create yet");

    check_map();

    pop(12);
    printf("\n");
    check_map();

    pop(23);
    printf("\n");
    check_map();
    printf("\n");


    add_elem(123, "Work map?");
    add_elem(234, "seems to work!");
    check_map();
    printf("\n");

    printf("Value:::: %s\n", get_value(33));

    return 0;
}

//////////////////////////////////////////////////////////////////

// int main(){

//     char found[] = "ugabuga\n";
//     char **arr = malloc(100*sizeof(char*));

//     for(int i = 0; i < 100; i++)
//         arr[i] = malloc(100 *sizeof(char));

//     char* str = malloc(100 * sizeof(char));
//     int j = 0;
    
//     fgets(str, 100, stdin);
//     while(strcmp(str, found) != 0){
//         str[strlen(str)-1] = '\0';
//         strcpy(arr[j++], str);
//         fgets(str, 100, stdin);
//     }
    
//     fgets(str, 100, stdin);
//     str[strlen(str)-1] = '\0';
    
//     char key = malloc(30*sizeof(char));
//     char info = malloc(30*sizeof(char));
    
//     int flag = 0, h = 0;
    
//     for(int x = 0; x < j; x++){
//         char *r = strtok(arr[x], " ");
//         key = r;
//         while(r!=NULL){
//             info = r;
//             r = strtok(NULL, " ");
//         }
//     }   


//     return 0;
// }





//////////////////////////////////////////////

// int a1(const void* a){
//     return (*(int*)a % 2 == 0 ? 1 : 0);
// }

// int a2(const void* a){
//     if(*(double*)a < 0) *(double*)a = *(double*)a*(-1);
//     int aa = (int)*(double*)a;
//     int flag_c = 0;
//     if (aa % 2 == 0)
//         flag_c = 1;
//     else return 0;
    
//     int flag_v = 0;
//     // double eps = 1e-6;
//     if (*(double*)a - aa <= 0.000001)
//         flag_v = 1;

//     if (flag_v == 1 && flag_c == 1)
//         return 1;
//     else 
//         return 0;
// }

// int count_if(void* base, size_t num, size_t size, int (*pred)(const void*)){
    
//     int res = 0;

//     for (int i = 0; i < num; i++)
//         if (pred((char*)base+i*size) == 1)
//             ++res;

//     return res;
// }

// int main(){

//     // int d;
//     // scanf("%d", &d);
//     // int c = d;
//     // int res = 0;
//     // while (c){
//     //     c = d%10;
//     //     d /= 10;
//     //     res++;
//     // }
//     // printf("%d\n", res-1);

//     /////////////

//     int count = 10;
//     int size;
//     scanf("%d", &size);
//     void *arr;
//     int res;
//     switch(size){
//         case 4:
//             arr = (int*) malloc (count * sizeof(int));
//             for (int i = 0; i < count; i++)
//                 scanf("%d", (int*)arr+i);
//             res = count_if(arr, count, 4, a1);
//             break;
//         case 8:
//             arr = (double*) malloc (count * sizeof(double));

//             for (int i = 0; i < count; i++)
//                 scanf("%lf", (double*)arr+i);
//             res = count_if(arr, count, 8, a2);
//             break;
//     }

//     // char found[] = "ugabuga\n";
//     // char **str = (char**) malloc(100*sizeof(char*));
//     // for (int i = 0; i < 100; i++){
//     //     str[i] = (char*) malloc(100 *sizeof(char));
//     // }
//     // char* s = (char*) malloc(100*sizeof(char));
//     // int j = 0;
//     // fgets(s, 100, stdin);
//     // while(strcmp(s, found) != 0){
//     //     strcpy(str[j++], s);
//     //     fgets(s, 100, stdin);
//     // }
//     // for(int x = 0; x < j; x++){
//     //     printf("%s", str[x]);
//     // }

//     printf("%d\n", res);
    


//     return 0;
// }

/////////////////////////////////////////////////////////

// struct Dict{
//     char *key;
//     char *info;
//     struct Dict *next;
// };

// struct Dict *head = NULL;

// int IsEmpty(){
//     if(head == NULL) return 0;
//     else return 1;
// }
// int IsKey(char *key){
//     struct Dict *header = head;
//     int check = 0;
//     while(header!=NULL){
//         if(strcmp(header->key, key) == 0){
//             check = 1;
//         }
//         header = header->next;
//     }
//     if(check == 0) return 0;
//     else return 1;
// }

// struct Dict *CreateElem(char *info, char *key, struct Dict *next){
//     struct Dict *newKey = malloc(sizeof(struct Dict));
//     newKey->info = info;
//     newKey->key = key;
//     newKey->next = next;
//     return newKey;
// }

// void push(char *info, char *key) {
//     if(IsEmpty() == 0) {
//         struct Dict *newKey = CreateElem(info, key, NULL);
//         head = newKey;
//         return;
//     }
//     struct Dict *header = head;
//     while (header->next != NULL)
//         header = header->next;
//     struct Dict *newKey = CreateElem(info, key, NULL);
//     header->next = newKey;
// }

// void Remove(char *key){
//     if(IsKey(key) == 0){
//         printf("Такого ключа нет..\n");
//         return;
//     }
//     if(head->next == NULL){
//         head = NULL;
//     }
//     if(strcmp(head->key, key)==0){
//         head = head->next;
//         return;
//     }
//     struct Dict *header = head->next;
//     struct Dict *prev = head;
//     while(strcmp(header->key, key)!=0){
//         header = header->next;
//         prev = prev->next;
//     }
//     prev->next = header->next;
// }

// void Get(char *key){
//     if(IsKey(key)==0){
//         printf("Такого ключа в словаре нет..\n");
//         return;
//     }
//     struct Dict *header = head;
//     while(header!=NULL){
//         if(strcmp(header->key, key) == 0){
//             printf("%s\n", header->info);
//         }
//         header = header->next;
//     }
// }

// void PrintKeys(){
//     if(IsEmpty() == 0)
//         printf("Словарь пуст..\n");
//     while (head->next != NULL){
//         printf("%s\n", head->key);
//         head = head->next;
//     }
//     printf("%s\n", head->key);
// }
// void PrintInfo(){
//     if(IsEmpty() == 0)
//         printf("Словарь пуст..\n");
//     while (head->next != NULL){
//         printf("%s\n", head->info);
//         head = head->next;
//     }
//     printf("%s\n", head->info);
// }

//////////////////////

// char found[] = "ugabuga\n";
//     char **arr = malloc(100*sizeof(char*));
//     for(int i = 0; i < 100; i++){
//         arr[i] = malloc(100 *sizeof(char));
//     }
//     char* str = malloc(100 * sizeof(char));
//     int j = 0;
//     fgets(str, 100, stdin);
//     while(strcmp(str, found) != 0){
//         str[strlen(str)-1] = '\0';
//         strcpy(arr[j++], str);
//         fgets(str, 100, stdin);
//     }
//     fgets(str, 100, stdin);
//     str[strlen(str)-1] = '\0';
//     char key = malloc(30*sizeof(char));
//     char info = malloc(30*sizeof(char));
//     int flag = 0, h = 0;
//     for(int x = 0; x < j; x++){
//         char *istr = strtok(arr[x], " ");
//         key = istr;
//         while(istr!=NULL){
//             //printf("%s\n", istr);
//             info = istr;
//             istr = strtok(NULL, " ");
//         }
//         push(info, key);
//     }