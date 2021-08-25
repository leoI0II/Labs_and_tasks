// #include<stdio.h>
// #include<stdlib.h>
// #include<dirent.h>
// #include<sys/types.h>
// #include<string.h>

// //work
// int rec_power(int num, int p)
// {
//     if (p == 0)
//         return 1;
//     if (p == 1)
//         return num;
//     else return num * rec_power(num, p - 1);
// }

// //work
// int rec_sum_of_array(int *arr, int *end_arr)
// {
//     if (arr == end_arr)
//         return 0;
//     else return *arr + rec_sum_of_array(arr + 1, end_arr);
// }


// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// //work
// int check_files(FILE* file1, FILE* file2)
// {
//     char sym_f1, sym_f2;

//     do
//     {
//         sym_f1 = fgetc(file1);
//         sym_f2 = fgetc(file2);

//         if (sym_f1 != sym_f2)
//             return 0;

//     } while (sym_f1 != EOF && sym_f2 != EOF);

//     if (sym_f1 == EOF && sym_f2 == EOF)
//         return 1;
//     else
//         return 0;
// }

// void find_same_content()
// {
//     DIR* dirp = opendir(".");

//     struct dirent* entry;
//     long len_name, tell;

//     while ((entry = readdir(dirp)) != NULL)
//     {
//         len_name = strlen(entry->d_name);

//         if (entry->d_type == DT_REG && entry->d_name[len_name-1] == 't' && entry->d_name[len_name-2] == 'x' && entry->d_name[len_name-3] == 't' && entry->d_name[len_name-4] == '.')
//         {
//             tell = telldir(dirp);
//             struct dirent* s_entry;

//             while ((s_entry = readdir(dirp)) != NULL)
//             {
//                 long l = strlen(s_entry->d_name);
//                 if (s_entry->d_type == DT_REG && s_entry->d_name[l-1] == 't' && s_entry->d_name[l-2] == 'x' && s_entry->d_name[l-3] == 't' && s_entry->d_name[l-4] == '.')
//                 {
//                     FILE* f_file = fopen(entry->d_name, "r");
//                     FILE* s_file = fopen(s_entry->d_name, "r");
//                     printf("Curr files open - %s and %s\n", entry->d_name, s_entry->d_name);
                    
//                     char flag = check_files(f_file, s_file);
//                     if (flag)
//                         printf("\n%s and %s have same content!\n\n", entry->d_name, s_entry->d_name);
//                     fclose(f_file); 
//                     fclose(s_file);
//                 }
//             }
//             free(s_entry);
//             seekdir(dirp, tell);
//         }
//     }
//     printf("Process finished!\n");
// }
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// typedef struct list_of_current_direct
// {
//     char* path;
//     struct list_of_current_direct* next;
//     struct list_of_current_direct* prev;
// } direct;

// direct* init_list(char* starting_point)
// {
//     direct* head = (direct*) malloc (sizeof(direct));
//     head->next = NULL;
//     head->prev = NULL;
//     head->path = (char*) malloc (strlen(starting_point)+1);
//     strcpy(head->path, starting_point);
//     return head;
// }

// direct* push(direct* last, char* next_dir)
// {
//     direct* addest = (direct*) malloc (sizeof(direct));

//     last->next = addest;
//     addest->next = NULL;
//     addest->prev = last;

//     addest->path = (char*) malloc (strlen(last->path) + 1+ strlen(next_dir)+1);
//     strcpy(addest->path, last->path);
//     strcat(addest->path, "/");
//     strcat(addest->path, next_dir);

//     return addest;
// }

// void pop(direct* last)
// {
//     last->prev->next = NULL;
//     free(last->path);
//     free(last);
// }

// int check_file(direct* lllll, char* name_of_file)
// {
//     char* file_path = (char*) malloc (strlen(lllll->path) + 1 + strlen(name_of_file) + 1);
//     strcpy(file_path, lllll->path);
//     strcat(file_path, "/");
//     strcat(file_path, name_of_file);
//     printf("\nChecking file - %s ==> ", file_path);

//     FILE *file = fopen(file_path, "r");
//     char* str = (char*) malloc (256);
//     size_t count = 0;                                       // fgets(...);
//     while(fgets(str, 256, file) != NULL)                    // while (!feof(file))
//         ++count;                                            // ...; fgets(...)

//     free(str);
//     fclose(file);
//     free(file_path);
//     if (count % 2 == 0)
//         return 1;
//     else
//         return 0;
// }

// void find_files_even_str(direct* last)
// {
//     DIR* dir_stream = opendir(last->path);
//     if(!dir_stream){
//         printf("Cant open directory %s\n", last->path);
//         return;
//     }
//     printf("Current directory - %s\n", last->path);

//     struct dirent* entry;

//     while ((entry = readdir(dir_stream)) != NULL)
//     {
//         long entry_name_len = strlen(entry->d_name);
//         if (entry->d_type == DT_REG &&
//             entry->d_name[entry_name_len - 1] == 't' &&
//             entry->d_name[entry_name_len - 2] == 'x' &&
//             entry->d_name[entry_name_len - 3] == 't' &&
//             entry->d_name[entry_name_len - 4] == '.')
//         {
//             if (check_file(last, entry->d_name))
//                 printf("Correct!\n");
//             else
//                 printf("Failed!\n");
//         }
//         else if (entry->d_type == DT_DIR &&
//                  strcmp(entry->d_name, "..") &&
//                  strcmp(entry->d_name, "."))
//         {
//             direct* next = push(last, entry->d_name);
//             find_files_even_str(next);
//             pop(next);
//         }
//     }
//     free(entry);
//     closedir(dir_stream);
//     // printf("\nProcess finished!\n");
// }


// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// int main()
// {
    
//     // int arr[] = {1, 2, 3, 4, 5};
//     // int *arr = (int*) malloc (10* sizeof(int));
//     // int count = 0;
//     // for (; count < 10; count++)
//     // {
//     //     if (!count)
//     //     {
//     //         scanf("%d", &arr[count]);
//     //         continue;
//     //     }
//     //     if (getchar() == '\n') break;
//     //     scanf("%d", &arr[count]);
//     // }

//     // for (int i = 0; i < count; i++)
//     // {
//     //     printf("%d ", arr[i]);
//     // }
//     // printf("\nCount arr is %d\n", count);
//     // printf("sum of array is %d\n", rec_sum_of_array(arr, arr+count));


//     // DIR* dir = opendir(".");

//     // struct dirent* rd;

//     // while ((rd = readdir(dir)) != NULL)
//     // {
//     //     printf("%s\n", rd->d_name);
//     // }
    
//     // printf("\nOne time gone, now again\n\n");
//     // rewinddir(dir);

//     // rd = readdir(dir);
//     // printf("%s\n", rd->d_name);
//     //     rd = readdir(dir);
//     // printf("%s\n", rd->d_name);
//     //     rd = readdir(dir);
//     // printf("%s\n", rd->d_name);

//     // rd = readdir(dir);
//     // printf("%s\n", rd->d_name);
//     // rd = readdir(dir);
//     // printf("%s\n", rd->d_name);

//     // long tell = telldir(dir), tell2;
//     // printf("\nTrying telldir func, check - %ld\n", tell);

//     // rd = readdir(dir);
//     // printf("%s\n", rd->d_name);
    
//     // rd = readdir(dir);
//     // printf("%s\n", rd->d_name);

//     // rd = readdir(dir);
//     // printf("%s\n", rd->d_name);
//     // rd = readdir(dir);
//     // printf("%s\n", rd->d_name);
//     // rd = readdir(dir);
//     // printf("%s\n", rd->d_name);

//     // seekdir(dir, tell);
    
//     // rd = readdir(dir);
//     // printf("%s\n", rd->d_name);

//     // closedir(dir);

    
    
    
//     // find_same_content();

//     // direct* head = init_list("/home/leo11/Projects");

//     // find_files_even_str(head);



//     // FILE* fp = fopen("file.txt", "r");

//     // char str[256];

//     // while (fgets(str, 256, fp) != NULL)
//     //     printf("%s", str);

//     // if (feof(fp))
//     //     printf("EOF reached!\n");

//     // fclose(fp);
    


//     return 0;
// }



/////////////////////////////////////////////////////////////////////////////////////////////


// #include<stdio.h>
// #include<stdlib.h>
// #include<dirent.h>
// #include<sys/types.h>
// #include<string.h>
// #include<ctype.h>

// int comp(const void *a, const void *b);

// typedef struct Node_dir
// {
//     struct Node_dir *next_dir;
//     struct Node_dir *prev_dir;
//     char *dir;
// }
//         Node_dir;

// Node_dir* next_dir(Node_dir* head, char* dir)
// {
//     while (head->next_dir != NULL)
//         head = head->next_dir;

//     Node_dir* push_dir = (Node_dir*) malloc (sizeof(Node_dir));

//     push_dir->next_dir = NULL;
//     head->next_dir = push_dir;
//     push_dir->prev_dir = head;
//     push_dir->dir = (char*) malloc(strlen(head->dir) +1+ strlen(dir) + 1);

//     strcpy(push_dir->dir, head->dir);

//     if (strcmp(head->dir, "/") == 0){
//         strcat(push_dir->dir, dir);
//     }
//     else{
//         strcat(push_dir->dir, "/");
//         strcat(push_dir->dir, dir);
//     }

//     return push_dir;
// }

// void prev_dir(Node_dir* head)
// {
//     while (head->next_dir != NULL)
//         head = head->next_dir;

//     free(head->dir);
//     head->prev_dir->next_dir = NULL;
//      head->prev_dir = NULL;
// }

// void rec_check_dir(Node_dir* cur_dir, FILE* log, FILE* texts)
// {
//     fprintf(log, "Current direct - %s\n", cur_dir->dir);
//     DIR* cur_open_direct = opendir(cur_dir->dir);
//     if (!cur_open_direct)
//     {
//         fprintf(log, "\nCant open direct %s\n", cur_dir->dir);
//         return;
//     }

//     struct dirent* entry;

//     while ((entry = readdir(cur_open_direct)))
//     {
//         long entry_name_len = strlen(entry->d_name);
//         if (entry->d_type == DT_REG &&
//             entry->d_name[entry_name_len - 1] == 't' &&
//             entry->d_name[entry_name_len - 2] == 'x' &&
//             entry->d_name[entry_name_len - 3] == 't' &&
//             entry->d_name[entry_name_len - 4] == '.')
//         {
//             fprintf(log, "filename and dir - %s/%s\n", cur_dir->dir, entry->d_name);

//             char *file = (char*) malloc (strlen(cur_dir->dir)+1+strlen(entry->d_name) + 1);
//             strcpy(file, cur_dir->dir);
//             strcat(file, "/");
//             strcat(file, entry->d_name);

//             FILE* open_file = fopen(file, "r");

//             char * str_from_file = (char*) malloc (256);
//             fgets(str_from_file, 256, open_file);
//             while (!feof(open_file))
//             {
//                 fprintf(texts, "%s", str_from_file);
//                 fgets(str_from_file, 256, open_file);
//             }
//             fclose(open_file);
//         }
//         else if (entry->d_type == DT_DIR &&
//                  strcmp(entry->d_name, "..") &&
//                  strcmp(entry->d_name, "."))
//         {
//             Node_dir* next = next_dir(cur_dir, entry->d_name);
//             // fprintf(log, "Next direct %s\n\n", next->dir);
//             rec_check_dir(next, log, texts);
//             prev_dir(next);
//             free(next);
//         }
//     }
//     fprintf(log, "Current dir is finished %s\n", cur_dir->dir);
//     closedir(cur_open_direct);
//     return;
// }


// int main()
// {
//     Node_dir* head_direct = (Node_dir*) malloc (sizeof(Node_dir));
//     head_direct->next_dir = NULL;
//     head_direct->prev_dir = NULL;
//     char* path = "/home/leo11/Projects/C/text_files";
//     long len = strlen(path);
//     head_direct->dir = (char*) malloc (len +1);
//     strcpy(head_direct->dir, path);

//     FILE* log = fopen("lllllog.txt", "w");
//     FILE* texts = fopen("ssssssssss.txt", "w");
//     // char** texts = (char**) malloc (sizeof(char*));
//     long count_str = 0;
//     rec_check_dir(head_direct, log, texts);
//     fclose(texts);
//     fclose(log);

//     FILE* _texts = fopen("ssssssssss.txt", "r");
//     fseek(_texts, 0, SEEK_END);
//     long int pos = ftell(_texts);
//     if (pos > 0)
//         rewind(_texts);
//     else
//         exit(EXIT_SUCCESS);

//     char str_from_file[256];
//     char** array_str = (char**) malloc (sizeof(char*));

//     int counter = 0;
//     while (fgets(str_from_file, 256, _texts) != NULL)
//     {
//         array_str[counter] = (char*) malloc (strlen(str_from_file)+1);
//         strcpy(array_str[counter], str_from_file);
//         counter++;
//         array_str = (char**) realloc(array_str, (counter+1)* sizeof(char*));
//     }
//     fclose(_texts);

//     qsort(array_str, counter, sizeof(char*), comp);

//     FILE* result = fopen("vvvvvvvvvvv.txt", "w");

//     int i;
//     for(i = 0; i < counter; i++)
//         fprintf(result, "%s", array_str[i]);

//     fclose(result);
//     for(i = 0; i < counter; i++)
//         free(array_str[i]);
//     free(array_str);

//     return 0;
// }

// int comp(const void *a, const void *b)
// {
//     char* aa = *(char**) a;
//     char* bb = *(char**) b;

//     int count_c1 = 0;
//     int count_c2 = 0;

//     char *caa = aa;
//     char* cbb = bb;

//     while (*caa++)
//         count_c1 += (int)(*caa);

//     while (*cbb++)
//         count_c2 += (int)(*cbb);

//     if (count_c1 > count_c2)
//         return 1;
//     else if (count_c1 < count_c2)
//         return -1;
//     else
//         return 0;
// }


////////////////////////////////////////////////////////////////////////////////////


// int main()
// {
//     FILE* open_file = fopen("aaaa.txt", "r");

//     // char str[256];

//     char * str_from_file = (char*) malloc (256);
//     fgets(str_from_file, 256, open_file);
//     while (!feof(open_file))
//     {
//         // fprintf(texts, "%s", str_from_file);
//         printf("%s", str_from_file);
//         fgets(str_from_file, 256, open_file);
//     }
//     fclose(open_file);

//     return 0;
// }


/////////////////////////////////////////////////////////////////////////////////////////////
//DONE
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>
#include<string.h>
#include<ctype.h>

int comp(const void *a, const void *b);

typedef struct Node_dir
{
    struct Node_dir *next_dir;
    struct Node_dir *prev_dir;
    char *dir;
}
        Node_dir;

Node_dir* next_dir(Node_dir* head, char* dir)
{
    while (head->next_dir != NULL)
        head = head->next_dir;

    Node_dir* push_dir = (Node_dir*) malloc (sizeof(Node_dir));

    push_dir->next_dir = NULL;
    head->next_dir = push_dir;
    push_dir->prev_dir = head;
    push_dir->dir = (char*) malloc(strlen(head->dir) +1+ strlen(dir) + 1);

    strcpy(push_dir->dir, head->dir);

    if (strcmp(head->dir, "/") == 0){
        strcat(push_dir->dir, dir);
    }
    else{
        strcat(push_dir->dir, "/");
        strcat(push_dir->dir, dir);
    }

    return push_dir;
}

void prev_dir(Node_dir* head)
{
    while (head->next_dir != NULL)
        head = head->next_dir;

    free(head->dir);
    head->prev_dir->next_dir = NULL;
     head->prev_dir = NULL;
}

void rec_check_dir(Node_dir* cur_dir, char*** texts, long* counter)
{
    DIR* cur_open_direct = opendir(cur_dir->dir);
    if (!cur_open_direct)
    {
        return;
    }

    struct dirent* entry;

    while ((entry = readdir(cur_open_direct)))
    {
        long entry_name_len = strlen(entry->d_name);
        if (entry->d_type == DT_REG &&
            entry->d_name[entry_name_len - 1] == 't' &&
            entry->d_name[entry_name_len - 2] == 'x' &&
            entry->d_name[entry_name_len - 3] == 't' &&
            entry->d_name[entry_name_len - 4] == '.')
        {

            char *file = (char*) malloc (strlen(cur_dir->dir)+1+strlen(entry->d_name) + 1);
            strcpy(file, cur_dir->dir);
            strcat(file, "/");
            strcat(file, entry->d_name);

            FILE* open_file = fopen(file, "r");

            char *str_files = (char*) malloc (255);
            while (fgets(str_files, 255, open_file) != NULL)
            {
                (*texts)[*counter] = (char*) malloc (strlen(str_files) +1);
                strcpy((*texts)[*counter], str_files);
                (*counter)++;
                *texts = (char**) realloc(*texts, ((*counter)+1)* sizeof(char*));
            }
            fclose(open_file);

        }
        else if (entry->d_type == DT_DIR &&
                 strcmp(entry->d_name, "..") &&
                 strcmp(entry->d_name, "."))
        {
            Node_dir* next = next_dir(cur_dir, entry->d_name);
            rec_check_dir(next, texts, counter);
            prev_dir(next);
            free(next);
        }
    }
    closedir(cur_open_direct);
    return;
}


int main()
{
    Node_dir* head_direct = (Node_dir*) malloc (sizeof(Node_dir));
    head_direct->next_dir = NULL;
    head_direct->prev_dir = NULL;
    char* path = "/home/box/root";
    long len = strlen(path);
    head_direct->dir = (char*) malloc (len +1);
    strcpy(head_direct->dir, path);

    char** texts = (char**) malloc (sizeof(char*));
    long count_str = 0;
    long *pcounter = &count_str;
    rec_check_dir(head_direct, &texts, pcounter);

    qsort(texts, count_str, sizeof(char*), comp);

    FILE* result = fopen("result.txt", "w");

    int i;
    for(i = 0; i < count_str; i++)
        fprintf(result, "%s", texts[i]);

    fclose(result);
    for(i = 0; i < count_str; i++)
        free(texts[i]);
    free(texts);

    return 0;
}

int comp(const void *a, const void *b)
{
    char* aa = *(char**) a;
    char* bb = *(char**) b;

    long int count_c1 = strlen(aa);
    long int count_c2 = strlen(bb);

    return count_c1 - count_c2;
}


///////////////////////////////////////////////////////////////////////////////////////


//task na 5 WORK!
// #include<stdio.h>
// #include<stdlib.h>
// #include<dirent.h>
// #include<sys/types.h>
// #include<string.h>
// #include<ctype.h>

// typedef struct 
// {
//     int count_lower;
//     char file_name[200];
// } answer_struct;

// typedef struct Node_dir
// {
//     struct Node_dir *next_dir;
//     struct Node_dir *prev_dir;
//     char *dir;
// }
//         Node_dir;

// Node_dir* init_list(char* starting_point)
// {
//     Node_dir* head = (Node_dir*) malloc (sizeof(Node_dir));
//     head->next_dir = NULL;
//     head->prev_dir = NULL;
//     head->dir = (char*) malloc (strlen(starting_point)+1);
//     strcpy(head->dir, starting_point);
//     return head;
// }

// Node_dir* push(Node_dir* head, char* dir)
// {
//     while (head->next_dir != NULL)
//         head = head->next_dir;

//     Node_dir* push_dir = (Node_dir*) malloc (sizeof(Node_dir));

//     push_dir->next_dir = NULL;
//     head->next_dir = push_dir;
//     push_dir->prev_dir = head;
//     push_dir->dir = (char*) malloc(strlen(head->dir) +1+ strlen(dir) + 1);

//     strcpy(push_dir->dir, head->dir);

//     if (strcmp(head->dir, "/") == 0){
//         strcat(push_dir->dir, dir);
//     }
//     else{
//         strcat(push_dir->dir, "/");
//         strcat(push_dir->dir, dir);
//     }

//     return push_dir;
// }

// void pop(Node_dir* head)
// {
//     free(head->dir);
//     head->prev_dir->next_dir = NULL;
//     free(head);
// }

// void count_lowers(char* pstr, long* counter)
// {
//     char* str = pstr;
//     while (*str){
//         if( islower(*str))
//             (*counter)++;
//         str++;
//     }
// }

// void rec_check_dir(Node_dir* cur_dir, FILE*log, answer_struct* ans)
// {
//     fprintf(log, "Current direct - %s\n", cur_dir->dir);
//     DIR* cur_open_direct = opendir(cur_dir->dir);
//     if (!cur_open_direct)
//     {
//         fprintf(log, "\nCant open direct %s\n", cur_dir->dir);
//         return;
//     }

//     struct dirent* entry;

//     while ((entry = readdir(cur_open_direct)))
//     {
//         long entry_name_len = strlen(entry->d_name);
//         if (entry->d_type == DT_REG &&
//             entry->d_name[entry_name_len - 1] == 't' &&
//             entry->d_name[entry_name_len - 2] == 'x' &&
//             entry->d_name[entry_name_len - 3] == 't' &&
//             entry->d_name[entry_name_len - 4] == '.')
//         {
//             fprintf(log, "filename and dir - %s/%s\n", cur_dir->dir, entry->d_name);

//             char *file = (char*) malloc (strlen(cur_dir->dir)+1+strlen(entry->d_name) + 1);
//             strcpy(file, cur_dir->dir);
//             strcat(file, "/");
//             strcat(file, entry->d_name);

//             FILE* f = fopen(file, "r");

//             char strs_file[255];
//             long low_count = 0;
//             long *ptr_low_count = &low_count;
//             fgets(strs_file, 255, f);
//             while (!feof(f))
//             {
//                 count_lowers(strs_file, ptr_low_count);
//                 fgets(strs_file, 255, f);
//             }
//             if (low_count > ans->count_lower)
//             {
//                 ans->count_lower = low_count;
//                 strcpy(ans->file_name, entry->d_name);
//             }
//         }
//         else if (entry->d_type == DT_DIR &&
//                  strcmp(entry->d_name, "..") &&
//                  strcmp(entry->d_name, "."))
//         {
//             Node_dir* next = push(cur_dir, entry->d_name);
//             fprintf(log, "Next direct %s\n\n", next->dir);
//             rec_check_dir(next, log, ans);
//             pop(next);
//         }
//     }
//     fprintf(log, "Current dir is finished %s\n", cur_dir->dir);
//     closedir(cur_open_direct);
//     return;
// }

// int main()
// {
//     answer_struct answer = {0, ""};

//     Node_dir* head_direct = init_list("./text_files");

//     FILE* log = fopen("log_task5_from_def", "w");

//     rec_check_dir(head_direct, log, &answer);

//     printf("%d; %s\n", answer.count_lower, answer.file_name);


//     return 0;
// }

//*******************************************************************************************8
//**********************************************************************************************

// int main()
// {
//     // FILE* f1 = fopen("test1.txt", "r");
//     // FILE* f2 = fopen("test2.txt", "r");
//     FILE* f3 = fopen("test3.txt", "r");

//     // char ch;

//     // while ((ch = fgetc(f3)) != EOF)
//     //     putc(ch, stdout);


//     char str[30];
//     // fgets(str, 30, f3);

//     // // for (int i = 0; i < 30; i++)
//     // //     printf("%c", str[i]);

//     // // printf("\n");
//     // // str[strlen(str) - 1] = 0;
//     // printf("%s", str);

//     // fscanf(f3, "%s", str);
//     // printf("%s", str);
//     // fscanf(f3, "%s", str);
//     // printf("%s", str);


//     while((fgets(str, 30, f3)) != NULL)
//     {
//         str[strlen(str) -1] = 0;
//         printf("%s", str);
//     }

//     // char ch;

//     // while ((ch = fgetc(f1)) != EOF)
//     //     printf("%c", ch);


//     fclose(f3);
//     return 0;
// }

//***************************************************************************************8
//**************************************************************************************


/////////////////////////////////////////////////////////////////////////////////////////


//VRODE KAK ISPRAVLENNOE S FILOM
// #include <stdio.h>
// #include <stdlib.h>
// #include <dirent.h>
// #include <string.h>
// #include <sys/types.h>
// #include <ctype.h>

// int comp(const void *a, const void *b);

// typedef struct Node_dir
// {
//     struct Node_dir *next_dir;
//     struct Node_dir *prev_dir;
//     char *dir;
// }
//         Node_dir;

// Node_dir* next_dir(Node_dir* head, char* dir)
// {
//     while (head->next_dir != NULL)
//         head = head->next_dir;

//     Node_dir* push_dir = (Node_dir*) malloc (sizeof(Node_dir));

//     push_dir->next_dir = NULL;
//     head->next_dir = push_dir;
//     push_dir->prev_dir = head;
//     push_dir->dir = (char*) malloc(strlen(head->dir) +1+ strlen(dir) + 1);

//     strcpy(push_dir->dir, head->dir);

//     if (strcmp(head->dir, "/") == 0){
//         strcat(push_dir->dir, dir);
//     }
//     else{
//         strcat(push_dir->dir, "/");
//         strcat(push_dir->dir, dir);
//     }

//     return push_dir;
// }

// void prev_dir(Node_dir* head)
// {
//     while (head->next_dir != NULL)
//         head = head->next_dir;

//     free(head->dir);
//     head->prev_dir->next_dir = NULL;
//     head->prev_dir = NULL;
// }

// void rec_check_dir(Node_dir* cur_dir, FILE* log, FILE* texts)
// {
//     fprintf(log, "Current direct - %s\n", cur_dir->dir);
//     DIR* cur_open_direct = opendir(cur_dir->dir);
//     if (!cur_open_direct)
//     {
//         fprintf(log, "\nCant open direct %s\n", cur_dir->dir);
//         return;
//     }

//     struct dirent* entry;

//     while ((entry = readdir(cur_open_direct)))
//     {
//         long entry_name_len = strlen(entry->d_name);
//         if (entry->d_type == DT_REG &&
//             entry->d_name[entry_name_len - 1] == 't' &&
//             entry->d_name[entry_name_len - 2] == 'x' &&
//             entry->d_name[entry_name_len - 3] == 't' &&
//             entry->d_name[entry_name_len - 4] == '.')
//         {
//             fprintf(log, "filename and dir - %s/%s\n", cur_dir->dir, entry->d_name);

//             char *file = (char*) malloc (strlen(cur_dir->dir)+1+strlen(entry->d_name) + 1);
//             strcpy(file, cur_dir->dir);
//             strcat(file, "/");
//             strcat(file, entry->d_name);

//             FILE* open_file = fopen(file, "r");

//             char * str_from_file = (char*) malloc (256);
//             //fgets(str_from_file, 256, open_file);
//             while (fgets(str_from_file, 256, open_file)!=NULL)
//             {
//                 fprintf(texts, "%s\n", str_from_file);
//                 //fgets(str_from_file, 256, open_file);
//             }
//             fclose(open_file);
//         }
//         else if (entry->d_type == DT_DIR &&
//                  strcmp(entry->d_name, "..") &&
//                  strcmp(entry->d_name, "."))
//         {
//             Node_dir* next = next_dir(cur_dir, entry->d_name);
//             fprintf(log, "Next direct %s\n\n", next->dir);
//             rec_check_dir(next, log, texts);
//             prev_dir(next);
//             free(next);
//         }
//     }
//     fprintf(log, "Current dir is finished %s\n", cur_dir->dir);
//     closedir(cur_open_direct);
//     return;
// }


// int main()
// {
//     Node_dir* head_direct = (Node_dir*) malloc (sizeof(Node_dir));
//     head_direct->next_dir = NULL;
//     head_direct->prev_dir = NULL;
//     char* path = "C:/LB";
//     long len = strlen(path);
//     head_direct->dir = (char*) malloc (len +1);
//     strcpy(head_direct->dir, path);

//     FILE* log = fopen("lllllog.txt", "w");
//     FILE* texts = fopen("ssssssssss.txt", "w");
//     // char** texts = (char**) malloc (sizeof(char*));
//     long count_str = 0;
//     rec_check_dir(head_direct, log, texts);
//     fclose(texts);
//     fclose(log);

//     FILE* _texts = fopen("ssssssssss.txt", "r");
//     fseek(_texts, 0, SEEK_END);
//     long int pos = ftell(_texts);
//     if (pos > 0)
//         rewind(_texts);
//     else
//         exit(EXIT_SUCCESS);

//     char str_from_file[256];
//     char** array_str = (char**) malloc (sizeof(char*));

//     int counter = 0;
//     while (fgets(str_from_file, 256, _texts) != NULL)
//     {
//         array_str[counter] = (char*) malloc (strlen(str_from_file)+1);
//         strcpy(array_str[counter], str_from_file);
//         counter++;
//         array_str = (char**) realloc(array_str, (counter+1)* sizeof(char*));
//     }
//     fclose(_texts);

//     qsort(array_str, counter, sizeof(char*), comp);

//     FILE* result = fopen("vvvvvvvvvvv.txt", "w");

//     int i;
//     for(i = 0; i < counter; i++)
//         fprintf(result, "%s", array_str[i]);

//     fclose(result);
//     for(i = 0; i < counter; i++)
//         free(array_str[i]);
//     free(array_str);

//     return 0;
// }

// int comp(const void *a, const void *b)
// {
//     char* aa = *(char**) a;
//     char* bb = *(char**) b;

//     int count_c1 = 0;
//     int count_c2 = 0;

//     char *caa = aa;
//     char* cbb = bb;

//     while (*caa++)
//         count_c1 += (int)(*caa);

//     while (*cbb++)
//         count_c2 += (int)(*cbb);

//     return -count_c1+count_c2;
// }



////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
//*******************************************************************************************

// #include<stdio.h>
// #include<stdlib.h>
// #include<dirent.h>
// #include<sys/types.h>
// #include<string.h>
// #include<ctype.h>

// typedef struct file_list
// {
//     char* file_name;
//     char* str_file;
//     int count;
//     struct file_list *next;
//     struct file_list *prev;
// } file_list;

// void push_file(file_list* head, char* file, char* file_path)
// {
//     while(head->next != NULL)
//     {
//         if (strcmp(head->file_name, file) == 0)
//         {
//             FILE* f = fopen(file_path, "r");

//             char* str_from_file = (char*) malloc (sizeof(char));
//             char ch;
//             size_t i = 0;
//             while ((ch = fgetc(f)) != EOF)
//             {
//                 str_from_file[i] = ch;
//                 i++;
//                 str_from_file = realloc(str_from_file, i+1);
//             }
//             str_from_file[i] = '\0';
//             fclose(f);

//             if (comp_strs...)
//             {
//                 ++head->count;
//             }
//             else
//             {
//                 free(str_from_file);
//                 return;
//             }
//         }
//         head = head->next;
//     }
//     file_list* new = (file_list*) malloc (sizeof(file_list));

//     new->count = 1;
//     new->file_name = (char*) malloc (strlen(file)+1);
//     strcpy(new->file_name, file);

//     char* str_from_file = (char*) malloc (sizeof(char));
//     char ch;
//     size_t i = 0;
//     while ((ch = fgetc(f)) != EOF)
//     {
//         str_from_file[i] = ch;
//         i++;
//         str_from_file = realloc(str_from_file, i+1);
//     }
//     str_from_file[i] = '\0';




// }

// typedef struct Node_dir
// {
//     struct Node_dir *next_dir;
//     struct Node_dir *prev_dir;
//     char *dir;
// }
//         Node_dir;

// Node_dir* init_list(char* starting_point)
// {
//     Node_dir* head = (Node_dir*) malloc (sizeof(Node_dir));
//     head->next_dir = NULL;
//     head->prev_dir = NULL;
//     head->dir = (char*) malloc (strlen(starting_point)+1);
//     strcpy(head->dir, starting_point);
//     return head;
// }

// Node_dir* push(Node_dir* head, char* dir)
// {
//     while (head->next_dir != NULL)
//         head = head->next_dir;

//     Node_dir* push_dir = (Node_dir*) malloc (sizeof(Node_dir));

//     push_dir->next_dir = NULL;
//     head->next_dir = push_dir;
//     push_dir->prev_dir = head;
//     push_dir->dir = (char*) malloc(strlen(head->dir) +1+ strlen(dir) + 1);

//     strcpy(push_dir->dir, head->dir);

//     if (strcmp(head->dir, "/") == 0){
//         strcat(push_dir->dir, dir);
//     }
//     else{
//         strcat(push_dir->dir, "/");
//         strcat(push_dir->dir, dir);
//     }

//     return push_dir;
// }

// void pop(Node_dir* head)
// {
//     free(head->dir);
//     head->prev_dir->next_dir = NULL;
//     free(head);
// }

// void count_lowers(char* pstr, long* counter)
// {
//     char* str = pstr;
//     while (*str){
//         if( islower(*str))
//             (*counter)++;
//         str++;
//     }
// }

// void rec_check_dir(Node_dir* cur_dir, FILE*log, file_list* ans)
// {
//     fprintf(log, "Current direct - %s\n", cur_dir->dir);
//     DIR* cur_open_direct = opendir(cur_dir->dir);
//     if (!cur_open_direct)
//     {
//         fprintf(log, "\nCant open direct %s\n", cur_dir->dir);
//         return;
//     }

//     struct dirent* entry;

//     while ((entry = readdir(cur_open_direct)))
//     {
//         long entry_name_len = strlen(entry->d_name);
//         if (entry->d_type == DT_REG &&
//             entry->d_name[entry_name_len - 1] == 't' &&
//             entry->d_name[entry_name_len - 2] == 'x' &&
//             entry->d_name[entry_name_len - 3] == 't' &&
//             entry->d_name[entry_name_len - 4] == '.')
//         {
//             fprintf(log, "filename and dir - %s/%s\n", cur_dir->dir, entry->d_name);

//             char *file = (char*) malloc (strlen(cur_dir->dir)+1+strlen(entry->d_name) + 1);
//             strcpy(file, cur_dir->dir);
//             strcat(file, "/");
//             strcat(file, entry->d_name);

//             FILE* f = fopen(file, "r");

//             char strs_file[255];
//             long low_count = 0;
//             long *ptr_low_count = &low_count;
//             fgets(strs_file, 255, f);
//             while (!feof(f))
//             {
//                 count_lowers(strs_file, ptr_low_count);
//                 fgets(strs_file, 255, f);
//             }
//             if (low_count > ans->count_lower)
//             {
//                 ans->count_lower = low_count;
//                 strcpy(ans->file_name, entry->d_name);
//             }
//         }
//         else if (entry->d_type == DT_DIR &&
//                  strcmp(entry->d_name, "..") &&
//                  strcmp(entry->d_name, "."))
//         {
//             Node_dir* next = push(cur_dir, entry->d_name);
//             fprintf(log, "Next direct %s\n\n", next->dir);
//             rec_check_dir(next, log, ans);
//             pop(next);
//         }
//     }
//     fprintf(log, "Current dir is finished %s\n", cur_dir->dir);
//     closedir(cur_open_direct);
//     return;
// }

// int main()
// {
    

//     Node_dir* head_direct = init_list("./text_files");

//     FILE* log = fopen("log_task5_from_def", "w");

//     rec_check_dir(head_direct, log, );


//     return 0;
// }


/////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>
#include<string.h>
#include<ctype.h>

typedef struct file_list
{
    int count;
    char* file_name;
    char* str;
    struct file_list* next;
    struct file_list* prev;
} file_list;

typedef struct Node_dir
{
    struct Node_dir *next_dir;
    struct Node_dir *prev_dir;
    char *dir;
}
        Node_dir;

int compare(char* s1, char* s2)
{
    char *c1, *c2;
    c1 = s1; c2 = s2;

    while (1)
    {
        if (*c1 == 0 && *c2 == 0)
            return 1;
        if (tolower(*c1) == tolower(*c2))
            continue;
        else
            return 0;
        
        c1++; c2++;
    }
}

void check_file(file_list* head, char* file, char* file_path)
{
    file_list* tmp;
    while (head)
    {
        if (head->next == NULL){
            tmp = head;
        }

        if (compare(head->file_name, file))
        {
            FILE* f = fopen(file_path, "r");

            char *str_from_file = malloc (1);
            char ch;
            int i = 0;
            while ((ch = fgetc(f)) != EOF)
            {
                str_from_file[i] = ch;
                i++;
                str_from_file = realloc(str_from_file, i+1);
            }
            str_from_file[i] = 0;
            fclose(f);

            if (compare(head->str, str_from_file)){
                head->count++;
                free(str_from_file);
                return;
            }
            else
            {
                free(str_from_file);
                return;
            }
        }
        head = head->next;
    }

    file_list* new = (file_list*) malloc(sizeof(file_list));
    tmp->next = new;
    new->next = NULL;
    new->prev = tmp;
    new->count = 1;
    new->file_name = (char*) malloc(strlen(file) +1);
    strcpy(new->file_name, file);

    FILE* f = fopen(file_path, "r");
    char *str_from_file = malloc (1);
    char ch;
    int i = 0;
    while ((ch = fgetc(f)) != EOF)
    {
        str_from_file[i] = ch;
        i++;
        str_from_file = realloc(str_from_file, i+1);
    }
    str_from_file[i] = 0;
    fclose(f);
    
    new->str = (char*) malloc (strlen(str_from_file) +1);
    strcpy(new->str, str_from_file);
    free(str_from_file);
    return;
}


Node_dir* init_list(char* starting_point)
{
    Node_dir* head = (Node_dir*) malloc (sizeof(Node_dir));
    head->next_dir = NULL;
    head->prev_dir = NULL;
    head->dir = (char*) malloc (strlen(starting_point)+1);
    strcpy(head->dir, starting_point);
    return head;
}

Node_dir* push(Node_dir* head, char* dir)
{
    while (head->next_dir != NULL)
        head = head->next_dir;

    Node_dir* push_dir = (Node_dir*) malloc (sizeof(Node_dir));

    push_dir->next_dir = NULL;
    head->next_dir = push_dir;
    push_dir->prev_dir = head;
    push_dir->dir = (char*) malloc(strlen(head->dir) +1+ strlen(dir) + 1);

    strcpy(push_dir->dir, head->dir);

    if (strcmp(head->dir, "/") == 0){
        strcat(push_dir->dir, dir);
    }
    else{
        strcat(push_dir->dir, "/");
        strcat(push_dir->dir, dir);
    }

    return push_dir;
}

void pop(Node_dir* head)
{
    free(head->dir);
    head->prev_dir->next_dir = NULL;
    free(head);
}

void count_lowers(char* pstr, long* counter)
{
    char* str = pstr;
    while (*str){
        if( islower(*str))
            (*counter)++;
        str++;
    }
}

void rec_check_dir(Node_dir* cur_dir, FILE*log, file_list* ans)
{
    fprintf(log, "Current direct - %s\n", cur_dir->dir);
    DIR* cur_open_direct = opendir(cur_dir->dir);
    if (!cur_open_direct)
    {
        fprintf(log, "\nCant open direct %s\n", cur_dir->dir);
        return;
    }

    struct dirent* entry;

    while ((entry = readdir(cur_open_direct)))
    {
        long entry_name_len = strlen(entry->d_name);
        if (entry->d_type == DT_REG &&
            entry->d_name[entry_name_len - 1] == 't' &&
            entry->d_name[entry_name_len - 2] == 'x' &&
            entry->d_name[entry_name_len - 3] == 't' &&
            entry->d_name[entry_name_len - 4] == '.')
        {
            fprintf(log, "filename and dir - %s/%s\n", cur_dir->dir, entry->d_name);
            char *file = (char*) malloc (strlen(cur_dir->dir)+1+strlen(entry->d_name) + 1);
            strcpy(file, cur_dir->dir);
            strcat(file, "/");
            strcat(file, entry->d_name);
            check_file(ans, entry->d_name, file);
            free(file);
        }
        else if (entry->d_type == DT_DIR &&
                 strcmp(entry->d_name, "..") &&
                 strcmp(entry->d_name, "."))
        {
            Node_dir* next = push(cur_dir, entry->d_name);
            fprintf(log, "Next direct %s\n\n", next->dir);
            rec_check_dir(next, log, ans);
            pop(next);
        }
    }
    fprintf(log, "Current dir is finished %s\n", cur_dir->dir);
    closedir(cur_open_direct);
    return;
}

// typedef struct ffff
// {
//     file_list* pt;
// } ff;

int max_from_list(file_list* head)
{
    long c = 0;
    while(head)
    {
        if (head->count > c)
            c = head->count;
    }
    return c;
}

void solve(file_list* head, long dd)
{
    char* ds[1000];
    file_list *as = (ff*) malloc (sizeof(ff));
    int i = 0;
    while (head)
    {
        if (head->count == dd){
            as = head;
            i++;
            as = realloc(as, (i+1)*sizeof(ff));
        }
        head = head->next;
    }
    if (i >1)
    {
        for(int j = 0; j < i-1; j++)
        {
            if (strcmp(as[j]->))
        }
    }
}


int main()
{
    file_list* head = (file_list*) malloc(sizeof(file_list));
    head->count = 0;
    head->file_name = malloc(1);
    head->file_name = 0;
    head->next = NULL;
    head->prev = NULL;
    head->str = malloc (1);
    head->str = 0;

    Node_dir* head_direct = init_list("./text_files");

    FILE* log = fopen("log_task5_from_def", "w");

    rec_check_dir(head_direct, log, head);

    long dd = max_from_list(head);
    solve(head, dd);

    // printf("%d; %s\n", answer.count_lower, answer.file_name);


    return 0;
}