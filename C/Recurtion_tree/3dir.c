// #include<stdio.h>
// #include<dirent.h>
// #include<sys/types.h>
// #include <stdlib.h>
// #include<string.h>

// int count_line = 0;

// void rec_check_tree(char* dir_path, FILE* log)
// {
//     fprintf(log, "%d)\n", count_line++);
//     DIR* open_dir = opendir(dir_path);
//     if (!open_dir){
//         fprintf(log, "LAST folder in the dir %s\n", dir_path);
//         return;
//     }

//     struct dirent* entry = readdir(open_dir);

//     char* next_folder, *folder ;
//     while (entry)
//     {
//         if (entry->d_type == DT_DIR && strcmp(entry->d_name, "..") && strcmp(entry->d_name, "."))
//         {
//             folder = (char*) malloc ((strlen(entry->d_name)+1) * sizeof(char));
//             strcpy(folder, entry->d_name);
//             // printf("!!%s\n", folder);
            
//             if (strcmp(dir_path, "/") == 0){
//                 // puts("!!!");
//                 next_folder = (char*) malloc ((strlen(dir_path) + strlen(folder) +1) * sizeof(char));
//                 strcpy(next_folder, dir_path);
//                 // printf("?%s\n", next_folder);
//                 strcat(next_folder, folder);
//                 fprintf(log, "current dir = %s\n", next_folder);
//                 rec_check_tree(next_folder, log);
//             }
//             else
//             {
//                 // fprintf(stdout, "len = %ld, dir = %s\n", strlen(dir_path), dir_path);
                
//                 if (dir_path[strlen(dir_path) -1] != '/'){
//                     dir_path = realloc(dir_path, strlen(dir_path) + 2);
//                     strcat(dir_path, "/");
//                 }

//                 next_folder = (char*) malloc ((strlen(dir_path) + strlen(entry->d_name)+1) * sizeof(char));
//                 strcpy(next_folder, dir_path);
//                 strcat(next_folder, entry->d_name);
//                 fprintf(log, "current dir = %s\n", next_folder);
//                 // printf("!%s\n", next_folder);
//                 rec_check_tree(next_folder, log);
//             }
//         }
//         // free(folder);
//         // free(next_folder);
//         entry = readdir(open_dir);
//     }
//     // free(folder);
//     // free(next_folder);
//     // fprintf(log, "FINISH\n");
//     closedir(open_dir);
//     return;
// }

// int main()
// {
//     FILE* log = fopen("log.txt", "w");
//     rec_check_tree("/", log);

//     return 0;
// }

// #include<stdio.h>
// #include<stdlib.h>
// #include<dirent.h>
// #include<sys/types.h>
// #include<string.h>


// int count_line = 0;

// void rec_check_tree(char* dir_path, FILE* res_file)
// {
//     fprintf(stdout, "%d)\n", count_line++);
//     DIR* open_dir = opendir(dir_path);
//     if (!open_dir){
//         fprintf(stdout, "LAST folder in the dir %s\n", dir_path);
//         return;
//     }

//     struct dirent* entry = readdir(open_dir);

//     char* next_folder, *folder, *file, *dir_file;
//     while (entry)
//     {
//         long int strLen = strlen(entry->d_name);
//         if (entry->d_type == DT_REG &&
//             entry->d_name[strLen -1] == 't' &&
//             entry->d_name[strLen -2] == 'x' &&
//             entry->d_name[strLen -3] == 't' &&
//             entry->d_name[strLen -4] == '.')
//         {
//             // printf("%s/%s\n", dir_path, entry->d_name);
//             file = (char*) malloc (strlen(dir_path) + 1 + strlen(entry->d_name) +1);
//             strcpy(file, dir_path);
//             strcat(file, "/");
//             strcat(file, entry->d_name);

//             printf("file = %s\n", file);

//             FILE* file_txt = fopen(file, "r");

//             if(!file_txt)
//             {
//                 printf("Error opening the file %s\n", file);
//                 continue;
//             }else printf("Open file %s\n", file);

//             // char ch;
//             // while ((ch = fgetc(file_txt)) != EOF)
//             //     fputc(ch, res_file);

//             char files_str[256];
//             while (fgets(files_str, 256, file_txt) != NULL)
//                 fputs(files_str, res_file);

//             // fputc('\n', res_file);
//             if (feof(file_txt))
//                 printf("all ok!\n");

//             fclose(file_txt);

//             free(file);

//         }
//         else if (entry->d_type == DT_DIR && strcmp(entry->d_name, "..") && strcmp(entry->d_name, "."))
//         {
//             folder = (char*) malloc ((strlen(entry->d_name)+1) * sizeof(char));
//             strcpy(folder, entry->d_name);
//             // printf("!!%s\n", folder);
            
//             if (strcmp(dir_path, "/") == 0){
//                 // puts("!!!");
//                 next_folder = (char*) malloc ((strlen(dir_path) + strlen(folder) +1) * sizeof(char));
//                 strcpy(next_folder, dir_path);
//                 // printf("?%s\n", next_folder);
//                 strcat(next_folder, folder);
//                 fprintf(stdout, "current dir = %s\n", next_folder);
//                 rec_check_tree(next_folder, res_file);
//             }
//             else
//             {
//                 // fprintf(stdout, "len = %ld, dir = %s\n", strlen(dir_path), dir_path);
                
//                 if (dir_path[strlen(dir_path) -1] != '/'){
//                     char* tmp = (char*) malloc (strlen(dir_path)+2);
//                     strcpy(tmp, dir_path);
//                     // free(dir_path);
//                     strcat(tmp, "/");
//                     dir_path = (char*) malloc (strlen(tmp));
//                     strcpy(dir_path, tmp);
//                     free(tmp);
//                     // dir_path = realloc(dir_path, strlen(dir_path) + 2);
//                     // strcat(dir_path, "/");
//                 }

//                 next_folder = (char*) malloc ((strlen(dir_path) + strlen(entry->d_name)+1) * sizeof(char));
//                 strcpy(next_folder, dir_path);
//                 strcat(next_folder, entry->d_name);
//                 fprintf(stdout, "current dir = %s\n", next_folder);
//                 // printf("!%s\n", next_folder);
//                 rec_check_tree(next_folder, res_file);
//             }
//             // free(folder);
//             // free(next_folder);
//         }
//         entry = readdir(open_dir);
//     }
//     // free(folder);
//     // free(next_folder);
//     // fprintf(stdout, "FINISH\n");
//     closedir(open_dir);
//     return;
// }

// int comp(const void *a, const void *b)
// {
//     char* aa = *(char**) a;
//     char* bb = *(char**) b;

//     int ia = *aa - '0';
//     int ib = *bb - '0';

//     if (ia > ib)
//         return 1;
//     else if (ia < ib)
//         return -1;
//     else 
//         return 0;
// }

// int main()
// {
//     long int *stLen = (long int*) malloc (sizeof(int));
//     // FILE* log = fopen("log3.txt", "w");
//     FILE* text_txt = fopen("texts.txt", "w");
//     rec_check_tree("/home/leo11/Projects/C", text_txt);
//     fclose(text_txt);

//     FILE* res_txt = fopen("texts.txt", "r");

//     char str_from_file[256];
//     char** array_str = (char**) malloc (sizeof(char*));
//     // char* array_str[15];
//     int counter = 0;
//     while (fgets(str_from_file, 256, res_txt) != NULL)
//     {
//         array_str[counter] = (char*) malloc (strlen(str_from_file)+1);
//         strcpy(array_str[counter], str_from_file);
//         counter++;
//         array_str = (char**) realloc(array_str, (counter+1)* sizeof(char*));
//     }

//     qsort(array_str, counter, sizeof(char*), comp);

//     for(int i = 0; i < counter; i++)
//         printf("%s", array_str[i]);


//     return 0;
// }


/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

// #include<stdio.h>
// #include<stdlib.h>
// #include<dirent.h>
// #include<sys/types.h>
// #include<string.h>
// #include<ctype.h>


// void rec_check_tree(char* dir_path, FILE* res_file)
// {
//     DIR* open_dir = opendir(dir_path);
//     if (!open_dir){
//         return;
//     }

//     struct dirent* entry = readdir(open_dir);

//     char* next_folder, *folder, *file, *dir_file;
//     while (entry)
//     {
//         long int strLen = strlen(entry->d_name);
//         if (entry->d_type == DT_REG &&
//             entry->d_name[strLen -1] == 't' &&
//             entry->d_name[strLen -2] == 'x' &&
//             entry->d_name[strLen -3] == 't' &&
//             entry->d_name[strLen -4] == '.')
//         {
//             file = (char*) malloc (strlen(dir_path) + 1 + strlen(entry->d_name) +1);
//             strcpy(file, dir_path);
//             strcat(file, "/");
//             strcat(file, entry->d_name);

//             FILE* file_txt = fopen(file, "r");


//             char files_str[256];
//             while (fgets(files_str, 256, file_txt) != NULL)
//                 fputs(files_str, res_file);

//             // if (feof(file_txt))
//             //     printf("all ok!\n");

//             fclose(file_txt);

//             free(file);

//         }
//         else if (entry->d_type == DT_DIR && strcmp(entry->d_name, "..") && strcmp(entry->d_name, "."))
//         {
//             folder = (char*) malloc ((strlen(entry->d_name)+1) * sizeof(char));
//             strcpy(folder, entry->d_name);
            
//             if (strcmp(dir_path, "/") == 0){
                
//                 next_folder = (char*) malloc ((strlen(dir_path) + strlen(folder) +1) * sizeof(char));
//                 strcpy(next_folder, dir_path);
//                 strcat(next_folder, folder);
//                 rec_check_tree(next_folder, res_file);
//             }
//             else
//             {

//                 if (dir_path[strlen(dir_path) -1] != '/'){
//                     char* tmp = (char*) malloc (strlen(dir_path)+2);
//                     strcpy(tmp, dir_path);
//                     strcat(tmp, "/");
//                     dir_path = (char*) malloc (strlen(tmp));
//                     strcpy(dir_path, tmp);
//                     free(tmp);
//                 }

//                 next_folder = (char*) malloc ((strlen(dir_path) + strlen(entry->d_name)+1) * sizeof(char));
//                 strcpy(next_folder, dir_path);
//                 strcat(next_folder, entry->d_name);
//                 rec_check_tree(next_folder, res_file);
//             }

//         }
//         entry = readdir(open_dir);
//     }

//     closedir(open_dir);
//     return;
// }

// int comp(const void *a, const void *b)
// {
//     char* aa = *(char**) a;
//     char* bb = *(char**) b;

//     char num1[30];
//     int i = 0;
//     while (isdigit(*aa))
//     {
//         num1[i] = *aa;
//         ++aa; ++i;
//     }
//     num1[i] = '\0';

//     char num2[30];
//     i = 0;
//     while (isdigit(*bb))
//     {
//         num2[i] = *bb;
//         ++bb; ++i;
//     }
//     num2[i] = '\0';

//     long int n1 = atol(num1);
//     long int n2 = atol(num2);

//     if (n1 > n2)
//         return 1;
//     else if (n1 < n2)
//         return -1;
//     else 
//         return 0;
// }

// int main()
// {
//     FILE* text_txt = fopen("texts.txt", "w");
//     rec_check_tree("/", text_txt);
//     fclose(text_txt);

//     FILE* res_txt = fopen("texts.txt", "r");

//     char str_from_file[256];
//     char** array_str = (char**) malloc (sizeof(char*));
    
//     int counter = 0;
//     while (fgets(str_from_file, 256, res_txt) != NULL)
//     {
//         array_str[counter] = (char*) malloc (strlen(str_from_file)+1);
//         strcpy(array_str[counter], str_from_file);
//         counter++;
//         array_str = (char**) realloc(array_str, (counter+1)* sizeof(char*));
//     }
//     fclose(res_txt);

//     qsort(array_str, counter, sizeof(char*), comp);

//     FILE* result = fopen("result.txt", "w");

//     for(int i = 0; i < counter; i++)
//         fprintf(result, "%s", array_str[i]);

//     fclose(result);
//     for(int i = 0; i < counter; i++)
//         free(array_str[i]);
//     free(array_str);

//     return 0;
// }


// int comp(const void *a, const void *b)
// {
//     char* aa = *(char**) a;
//     char* bb = *(char**) b;

//     char num1[30];
//     int i = 0;
//     if (aa[0] == '-'){
//         num1[i++] = '-';
//         ++aa;
//         while (isdigit(*aa))
//         {
//             num1[i] = *aa;
//             ++aa; ++i;
//         }
//         num1[i] = '\0';
//     }else
//     {
//         while (isdigit(*aa))
//         {
//             num1[i] = *aa;
//             ++aa; ++i;
//         }
//         num1[i] = '\0';
//     }

//     char num2[30];
//     i = 0;
//     if (bb[0] == '-'){
//         num2[i++] = '-';
//         ++bb;
//         while (isdigit(*bb))
//         {
//             num2[i] = *bb;
//             ++bb; ++i;
//         }
//         num2[i] = '\0';
//     }else
//     {
//         while (isdigit(*bb))
//         {
//             num2[i] = *bb;
//             ++bb; ++i;
//         }
//         num2[i] = '\0';
//     }


//     long int n1 = atol(num1);
//     long int n2 = atol(num2);

//     if (n1 > n2)
//         return 1;
//     else if (n1 < n2)
//         return -1;
//     else 
//         return 0;
// }

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////



#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>
#include<string.h>
#include<ctype.h>

int comp(const void *a, const void *b);

void rec_check_dir(char* cur_dir, FILE* texts)
{
    // fprintf(log, "current dir - %s\n", cur_dir);
    DIR* cur_open_dir = opendir(cur_dir);
    if (!cur_open_dir){
        // fprintf(stderr, "Cant open dir!\n");
        return;
    }

    struct dirent* entry;

    char* cpy_cur_dir = (char*) malloc (strlen(cur_dir)+1);

    while ((entry = readdir(cur_open_dir)))
    {
        // fprintf(stdout, "dir in while %s\n//entry name %s\n", cur_dir, entry->d_name);
        long int entry_name_len = strlen(entry->d_name);
        if (entry->d_type == DT_REG &&
            entry->d_name[entry_name_len - 1] == 't' &&
            entry->d_name[entry_name_len - 2] == 'x' &&
            entry->d_name[entry_name_len - 3] == 't' &&
            entry->d_name[entry_name_len - 4] == '.')
            {
                // fprintf(log, "filename and dir - %s/%s\n",cur_dir, entry->d_name);
                
                char *file = (char*) malloc (strlen(cur_dir)+1+strlen(entry->d_name) + 1);
                strcpy(file, cur_dir);
                strcat(file, "/");
                strcat(file, entry->d_name);

                FILE* open_file = fopen(file, "r");

                char str_from_file[256];
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
                            while (isgraph(str_from_file[++i]) || isspace(str_from_file[i])){}
                            if ((str_from_file[i] == '\n' && str_from_file[i+1] == '\0') || str_from_file[i] == '\0')
                                fputs(str_from_file, texts);
                            else{
                                fclose(open_file);
                                continue;
                            }
                        }
                        else
                        {
                            fclose(open_file);
                            continue;
                        }
                    }
                    else
                    {
                        fclose(open_file);
                        continue;
                    }
                }
                else if (isdigit(str_from_file[0]))
                {
                    int i = 1;
                    while(isdigit(str_from_file[i]))
                        ++i;

                    if (str_from_file[i] == ' ')
                    {
                        while (isgraph(str_from_file[++i]) || isspace(str_from_file[i])){}
                            // if (ispunct(str_from_file[i]))
                            //     break;
                        if ((str_from_file[i] == '\n' && str_from_file[i+1] == '\0') || str_from_file[i] == '\0')
                            fputs(str_from_file, texts);
                        else{
                            fclose(open_file);
                            continue;
                        }
                    }
                    else{
                        fclose(open_file);
                        continue;
                    }
                }
                else{
                    fclose(open_file);
                    continue;
                }

                fclose(open_file);
                free(file);
            }
        else if (entry->d_type == DT_DIR &&
                 strcmp(entry->d_name, "..") &&
                 strcmp(entry->d_name, "."))
            {
                if (strcmp(cur_dir, "/") == 0)
                {
                    // char next_dir_pos[20];
                    // next_dir_pos[0] = '/'; next_dir_pos[1] = '\0';
                    cpy_cur_dir = (char*) realloc (cpy_cur_dir, (strlen(cur_dir) + strlen(entry->d_name) +1));
                    strcpy(cpy_cur_dir, cur_dir);
                    strcat(cpy_cur_dir, entry->d_name);
                    char* tmp = (char*) malloc (strlen(cpy_cur_dir)+1);
                    strcpy(tmp, cpy_cur_dir);
                    rec_check_dir(tmp, texts);
                    free(tmp);
                    // free(cpy_cur_dir);
                }
                else
                {
                    cpy_cur_dir = (char*) realloc(cpy_cur_dir, 1 + strlen(cur_dir) +1 + strlen(entry->d_name));
                    strcpy(cpy_cur_dir, cur_dir);
                    strcat(cpy_cur_dir, "/");
                    strcat(cpy_cur_dir, entry->d_name);
                    // fprintf(log, "Next dir %s\n-->Cur is %s\n", cpy_cur_dir, cur_dir);
                    char* tmp = (char*) malloc (strlen(cpy_cur_dir)+1);
                    strcpy(tmp, cpy_cur_dir);
                    rec_check_dir(tmp, texts);
                    free(tmp);
                    // free(cpy_cur_dir);
                }
            }
    }
    // fprintf(log, "Current dir is finished %s\n", cur_dir);
    closedir(cur_open_dir);
    return;
}


int main()
{
    // FILE* log = fopen("new_log_4lab", "w");
    FILE* texts = fopen("_textx", "w");
    rec_check_dir("/", texts);
    // fclose(log);
    fclose(texts);

    FILE* _texts = fopen("_textx", "r");
    fseek(_texts, 0, SEEK_END);
    long int pos = ftell(_texts);
    if (pos > 0)
        rewind(_texts);
    else
        exit(EXIT_SUCCESS);
    
    char str_from_file[256];
    char** array_str = (char**) malloc (sizeof(char*));
    // puts("here13");
    int counter = 0;
    while (fgets(str_from_file, 256, _texts) != NULL)
    {
        if (isdigit(str_from_file[0]) || (str_from_file[0] == '-' && isdigit(str_from_file[1]))){
            array_str[counter] = (char*) malloc (strlen(str_from_file)+1);
            strcpy(array_str[counter], str_from_file);
            counter++;
            array_str = (char**) realloc(array_str, (counter+1)* sizeof(char*));
        }
        else
            continue;
    }
    fclose(_texts);
// puts("here14");

    qsort(array_str, counter, sizeof(char*), comp);

    FILE* result = fopen("result.txt", "w");

    int i;
    for(i = 0; i < counter; i++)
        fprintf(result, "%s", array_str[i]);

    fclose(result);
    for(int i = 0; i < counter; i++)
        free(array_str[i]);
    free(array_str);

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


    long int n1 = atol(num1);
    long int n2 = atol(num2);

    if (n1 > n2)
        return 1;
    else if (n1 < n2)
        return -1;
    else 
        return 0;
}