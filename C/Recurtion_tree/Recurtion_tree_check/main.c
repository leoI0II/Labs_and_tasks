//#include<stdio.h>
//#include<stdlib.h>
//#include<dirent.h>
//#include<sys/types.h>
//#include<string.h>
//#include<ctype.h>
//
//int comp(const void *a, const void *b);
//
//typedef struct Node_dir
//{
//    struct Node_dir *next_dir;
//    struct Node_dir *prev_dir;
//    char *dir;
//}
//        Node_dir;
//
//Node_dir* next_dir(Node_dir* head, char* dir)
//{
//    while (head->next_dir != NULL)
//        head = head->next_dir;
//
//    Node_dir* push_dir = (Node_dir*) malloc (sizeof(Node_dir));
//
//    push_dir->next_dir = NULL;
//    head->next_dir = push_dir;
//    push_dir->prev_dir = head;
//    push_dir->dir = (char*) malloc(strlen(head->dir) +1+ strlen(dir) + 1);
//
//    strcpy(push_dir->dir, head->dir);
//
//    if (strcmp(head->dir, "/") == 0){
//        strcat(push_dir->dir, dir);
//    }
//    else{
//        strcat(push_dir->dir, "/");
//        strcat(push_dir->dir, dir);
//    }
//
//    return push_dir;
//}
//
//void prev_dir(Node_dir* head)
//{
//    while (head->next_dir != NULL)
//        head = head->next_dir;
//
//    free(head->dir);
//    head->prev_dir->next_dir = NULL;
//     head->prev_dir = NULL;
//}
//
//void rec_check_dir(Node_dir* cur_dir, FILE*log, FILE* texts)
//{
//    fprintf(log, "Current direct - %s\n", cur_dir->dir);
//    DIR* cur_open_direct = opendir(cur_dir->dir);
//    if (!cur_open_direct)
//    {
//        fprintf(log, "\nCant open direct %s\n", cur_dir->dir);
//        return;
//    }
//
//    struct dirent* entry;
//
//    while ((entry = readdir(cur_open_direct)))
//    {
//        long entry_name_len = strlen(entry->d_name);
//        if (entry->d_type == DT_REG &&
//            entry->d_name[entry_name_len - 1] == 't' &&
//            entry->d_name[entry_name_len - 2] == 'x' &&
//            entry->d_name[entry_name_len - 3] == 't' &&
//            entry->d_name[entry_name_len - 4] == '.')
//        {
//            fprintf(log, "filename and dir - %s/%s\n", cur_dir->dir, entry->d_name);
//
//            char *file = (char*) malloc (strlen(cur_dir->dir)+1+strlen(entry->d_name) + 1);
//            strcpy(file, cur_dir->dir);
//            strcat(file, "/");
//            strcat(file, entry->d_name);
//
//            FILE* open_file = fopen(file, "r");
//
//            char str_from_file[256];
//            // while (fgets(str_from_file, 256, open_file) != NULL)
//            //     fputs(str_from_file, texts);
//            fgets(str_from_file, 256, open_file);
//            if (str_from_file[0] == '-')
//            {
//                if (isdigit(str_from_file[1]))
//                {
//                    // fputs(str_from_file, texts);
//                    int i = 2;
//
//                    while(isdigit(str_from_file[i]))
//                        ++i;
//
//                    if (str_from_file[i] == ' ')
//                    {
//                        while (isgraph(str_from_file[++i]) || isspace(str_from_file[i])){}
//                        if ((str_from_file[i] == '\n' && str_from_file[i+1] == '\0') || str_from_file[i] == '\0')
//                            fputs(str_from_file, texts);
//                        else{
//                            fclose(open_file);
//                            free(file);
//                            continue;
//                        }
//                    }
//                    else
//                    {
//                        fclose(open_file);
//                        free(file);
//                        continue;
//                    }
//                }
//                else
//                {
//                    fclose(open_file);
//                    free(file);
//                    continue;
//                }
//            }
//            else if (isdigit(str_from_file[0]))
//            {
//                int i = 1;
//                while(isdigit(str_from_file[i]))
//                    ++i;
//
//                if (str_from_file[i] == ' ')
//                {
//                    while (isgraph(str_from_file[++i]) || isspace(str_from_file[i])){}
//                    // if (ispunct(str_from_file[i]))
//                    //     break;
//                    if ((str_from_file[i] == '\n' && str_from_file[i+1] == '\0') || str_from_file[i] == '\0')
//                        fputs(str_from_file, texts);
//                    else{
//                        fclose(open_file);
//                        free(file);
//                        continue;
//                    }
//                }
//                else{
//                    fclose(open_file);
//                    free(file);
//                    continue;
//                }
//            }
//            else{
//                fclose(open_file);
//                free(file);
//                continue;
//            }
//
//            fclose(open_file);
//            free(file);
//        }
//        else if (entry->d_type == DT_DIR &&
//                 strcmp(entry->d_name, "..") &&
//                 strcmp(entry->d_name, "."))
//        {
//            Node_dir* next = next_dir(cur_dir, entry->d_name);
//            fprintf(log, "Next direct %s\n-->Cur - %s\n", next->dir, cur_dir->dir);
//            rec_check_dir(next, log, texts);
//            prev_dir(next);
//        }
//    }
//    fprintf(log, "Current dir is finished %s\n", cur_dir->dir);
//    // prev_dir(cur_dir);
//    closedir(cur_open_direct);
//    return;
//}
//
//
//int main()
//{
//    Node_dir* head_direct = (Node_dir*) malloc (sizeof(Node_dir));
//    head_direct->next_dir = NULL;
//    head_direct->prev_dir = NULL;
//    head_direct->dir = (char*) malloc (strlen("/") +1);
//    strcpy(head_direct->dir, "/");
//
//    FILE* log = fopen("log", "w");
//    FILE* texts = fopen("_textx", "w");
//    rec_check_dir(head_direct, log, texts);
//    fclose(log);
//    fclose(texts);
//
//    FILE* _texts = fopen("_textx", "r");
//    fseek(_texts, 0, SEEK_END);
//    long int pos = ftell(_texts);
//    if (pos > 0)
//        rewind(_texts);
//    else
//        exit(EXIT_SUCCESS);
//
//    char str_from_file[256];
//    char** array_str = (char**) malloc (sizeof(char*));
//    // puts("here13");
//    int counter = 0;
//    while (fgets(str_from_file, 256, _texts) != NULL)
//    {
//        if (isdigit(str_from_file[0]) || (str_from_file[0] == '-' && isdigit(str_from_file[1]))){
//            array_str[counter] = (char*) malloc (strlen(str_from_file)+1);
//            strcpy(array_str[counter], str_from_file);
//            counter++;
//            array_str = (char**) realloc(array_str, (counter+1)* sizeof(char*));
//        }
//        else
//            continue;
//    }
//    fclose(_texts);
//    // puts("here14");
//
//    qsort(array_str, counter, sizeof(char*), comp);
//
//    FILE* result = fopen("resul", "w");
//
//    int i;
//    for(i = 0; i < counter; i++)
//        fprintf(result, "%s", array_str[i]);
//
//    fclose(result);
//    for(i = 0; i < counter; i++)
//        free(array_str[i]);
//    free(array_str);
//
//    return 0;
//}
//
//int comp(const void *a, const void *b)
//{
//    char* aa = *(char**) a;
//    char* bb = *(char**) b;
//
//    char num1[30];
//    int i = 0;
//    if (aa[0] == '-'){
//        num1[i++] = '-';
//        ++aa;
//        while (isdigit(*aa))
//        {
//            num1[i] = *aa;
//            ++aa; ++i;
//        }
//        num1[i] = '\0';
//    }else
//    {
//        while (isdigit(*aa))
//        {
//            num1[i] = *aa;
//            ++aa; ++i;
//        }
//        num1[i] = '\0';
//    }
//
//    char num2[30];
//    i = 0;
//    if (bb[0] == '-'){
//        num2[i++] = '-';
//        ++bb;
//        while (isdigit(*bb))
//        {
//            num2[i] = *bb;
//            ++bb; ++i;
//        }
//        num2[i] = '\0';
//    }else
//    {
//        while (isdigit(*bb))
//        {
//            num2[i] = *bb;
//            ++bb; ++i;
//        }
//        num2[i] = '\0';
//    }
//
//
//    long long int n1 = atoll(num1);
//    long long int n2 = atoll(num2);
//
//    if (n1 > n2)
//        return 1;
//    else if (n1 < n2)
//        return -1;
//    else
//        return 0;
//}


////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////


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

void rec_check_dir(Node_dir* cur_dir, FILE*log, FILE* texts)
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

            FILE* open_file = fopen(file, "r");

            // char str_from_file[256];
            char * str_from_file = (char*) malloc (256);
            // while (fgets(str_from_file, 256, open_file) != NULL)
            //     fputs(str_from_file, texts);
            fgets(str_from_file, 256, open_file);
            if (str_from_file[0] == '-')
            {
                if (isdigit(str_from_file[1]))
                {
                    // fputs(str_from_file, texts);
                    int i = 2;

                    while(isdigit(str_from_file[i]))
                        ++i;

                    if (str_from_file[i] == ' ')
                    {
                        while (isalpha(str_from_file[++i]) || isspace(str_from_file[i]) || ispunct(str_from_file[i])){}
                        if ((str_from_file[i] == '\n' && str_from_file[i+1] == '\0') || str_from_file[i] == '\0')
                            fputs(str_from_file, texts);
                        else{
                            fclose(open_file);
                            free(file);
                            continue;
                        }
                    }
                    else
                    {
                        fclose(open_file);
                        free(file);
                        continue;
                    }
                }
                else
                {
                    fclose(open_file);
                    free(file);
                    continue;
                }
                fclose(open_file);
                free(file);
                free(str_from_file);
            }
            else if (isdigit(str_from_file[0]))
            {
                int i = 1;
                while(isdigit(str_from_file[i]))
                    ++i;

                if (str_from_file[i] == ' ')
                {
                    while (isalpha(str_from_file[++i]) || isspace(str_from_file[i]) || ispunct(str_from_file[i])){}
                    // if (ispunct(str_from_file[i]))
                    //     break;
                    if ((str_from_file[i] == '\n' && str_from_file[i+1] == '\0') || str_from_file[i] == '\0')
                        fputs(str_from_file, texts);
                    else{
                        fclose(open_file);
                        free(file);
                        continue;
                    }
                }
                else{
                    fclose(open_file);
                    free(file);
                    continue;
                }
            }
            else{
                fclose(open_file);
                free(file);
                continue;
            }

            fclose(open_file);
            free(file);
            free(str_from_file);
        }
        else if (entry->d_type == DT_DIR &&
                 strcmp(entry->d_name, "..") &&
                 strcmp(entry->d_name, "."))
        {
            Node_dir* next = next_dir(cur_dir, entry->d_name);
            fprintf(log, "Next direct %s\n", next->dir, cur_dir->dir);
            rec_check_dir(next, log, texts);
            prev_dir(next);
        }
    }
    fprintf(log, "Current dir is finished %s\n", cur_dir->dir);
    // prev_dir(cur_dir);
    closedir(cur_open_direct);
    return;
}


int main()
{
    Node_dir* head_direct = (Node_dir*) malloc (sizeof(Node_dir));
    head_direct->next_dir = NULL;
    head_direct->prev_dir = NULL;
    head_direct->dir = (char*) malloc (strlen("/home/leo11") +1);
    strcpy(head_direct->dir, "/home/leo11");

    FILE* log = fopen("dddddd_log", "w");
    FILE* texts = fopen("_textx", "w");
    rec_check_dir(head_direct, log, texts);
    fclose(log);
    fclose(texts);

    // FILE* _texts = fopen("_textx", "r");
    // fseek(_texts, 0, SEEK_END);
    // long int pos = ftell(_texts);
    // if (pos > 0)
    //     rewind(_texts);
    // else
    //     exit(EXIT_SUCCESS);

    // char str_from_file[256];
    // char** array_str = (char**) malloc (sizeof(char*));
    // // puts("here13");
    // int counter = 0;
    // while (fgets(str_from_file, 256, _texts) != NULL)
    // {
    //     if (isdigit(str_from_file[0]) || (str_from_file[0] == '-' && isdigit(str_from_file[1]))){
    //         array_str[counter] = (char*) malloc (strlen(str_from_file)+1);
    //         strcpy(array_str[counter], str_from_file);
    //         counter++;
    //         array_str = (char**) realloc(array_str, (counter+1)* sizeof(char*));
    //     }
    //     else
    //         continue;
    // }
    // fclose(_texts);
    // // puts("here14");

    // qsort(array_str, counter, sizeof(char*), comp);

    // FILE* result = fopen("resulttt", "w");

    // int i;
    // for(i = 0; i < counter; i++)
    //     fprintf(result, "%s", array_str[i]);

    // fclose(result);
    // for(i = 0; i < counter; i++)
    //     free(array_str[i]);
    // free(array_str);

    return 0;
}

int comp(const void *a, const void *b)
{
    char* aa = *(char**) a;
    char* bb = *(char**) b;

    char num1[30];
    int i = 0;
    if (aa[0] == '-'){
        num1[i++] = '-';
        ++aa;
        while (isdigit(*aa))
        {
            num1[i] = *aa;
            ++aa; ++i;
        }
        num1[i] = '\0';
    }else
    {
        while (isdigit(*aa))
        {
            num1[i] = *aa;
            ++aa; ++i;
        }
        num1[i] = '\0';
    }

    char num2[30];
    i = 0;
    if (bb[0] == '-'){
        num2[i++] = '-';
        ++bb;
        while (isdigit(*bb))
        {
            num2[i] = *bb;
            ++bb; ++i;
        }
        num2[i] = '\0';
    }else
    {
        while (isdigit(*bb))
        {
            num2[i] = *bb;
            ++bb; ++i;
        }
        num2[i] = '\0';
    }


    long long int n1 = atoll(num1);
    long long int n2 = atoll(num2);

    if (n1 > n2)
        return 1;
    else if (n1 < n2)
        return -1;
    else
        return 0;
}