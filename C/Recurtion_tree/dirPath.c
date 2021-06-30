#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include <stdlib.h>
#include<string.h>

void list_dir(const char *dirPath)
{
    DIR *dir = opendir(dirPath);                            // "открываем" директорию
    if(dir) {                                               // если это удалось успешно
        struct dirent *de = readdir(dir);                   // получаем очередной элемент открытой директории
        while (de) {
            if (de->d_type == 4)                                        // если это удалось
                printf("%s/%s %d %d\n", dirPath, de->d_name, de->d_reclen, de->d_type);         // печатаем имя этого элемента
            de = readdir(dir);                              // снова получаем очередной элемент открытой директории
        }
    }
    closedir(dir);                                          // не забываем "закрыть" директорию
}

int comp(const void *a, const void *b)
{
    char* aa = *(char**) a;
    char* bb = *(char**) b;

    int ia = *aa - '0';
    int ib = *bb - '0';

    if (ia > ib)
        return 1;
    else if (ia < ib)
        return -1;
    else 
        return 0;
}

int count_line = 0;

void rec_check_tree(char* dir_path)
{
    fprintf(stdout, "%d)\n", count_line++);
    DIR* open_dir = opendir(dir_path);
    if (!open_dir){
        fprintf(stdout, "LAST %s\n", dir_path);
        return;
    }

    struct dirent* entry = readdir(open_dir);

    char* next_folder, *folder ;
    while (entry)
    {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, "..") && strcmp(entry->d_name, "."))
        {
            folder = (char*) malloc ((strlen(entry->d_name)+1) * sizeof(char));
            strcpy(folder, entry->d_name);
            // printf("!!%s\n", folder);
            
            if (strcmp(dir_path, "/") == 0){
                // puts("!!!");
                next_folder = (char*) malloc ((strlen(dir_path) + strlen(folder) +1) * sizeof(char));
                strcpy(next_folder, dir_path);
                // printf("?%s\n", next_folder);
                strcat(next_folder, folder);
                fprintf(stdout, "dir = %s\n", next_folder);
                rec_check_tree(next_folder);
            }
            else
            {
                fprintf(stdout, "len = %ld, dir = %s\n", strlen(dir_path), dir_path);
                
                if (dir_path[strlen(dir_path) -1] != '/'){
                    dir_path = realloc(dir_path, strlen(dir_path) + 2);
                    strcat(dir_path, "/");
                }

                next_folder = (char*) malloc ((strlen(dir_path) + strlen(entry->d_name)+1) * sizeof(char));
                strcpy(next_folder, dir_path);
                strcat(next_folder, entry->d_name);
                fprintf(stdout, "check dir = %s\n", next_folder);
                // printf("!%s\n", next_folder);
                rec_check_tree(next_folder);
            }
        }
        // free(folder);
        // free(next_folder);
        entry = readdir(open_dir);
    }
    // free(folder);
    // free(next_folder);
    fprintf(stdout, "FINISH\n");
    closedir(open_dir);
    return;
}


int main(int argc, char **args)
{
    // FILE* log = fopen("log.txt", "w");

    rec_check_tree("/");

    // // list_dir(args[1]);
    // char* dir_path = (char*) malloc(strlen(args[1]) * sizeof(char));
    // strcpy(dir_path, args[1]);

    // DIR* dir = opendir(dir_path);

    // if (!dir){
    //     perror("Error opening dirPath");
    //     exit(EXIT_FAILURE);
    // }
    // struct dirent *dP;
    
    // // char* next_dir_path;
    // while (dir_path[strlen(dir_path) -1] != '.' && (dP = readdir(dir)))
    // {
    //     if (dP->d_type == DT_DIR && strcmp(dP->d_name, ".") == 0)
    //     {
    //         // next_dir_path = (char*) malloc (strlen(dP->d_name) * sizeof(char));
    //         // strcpy(dirP, dP->d_name);
    //         strcat(dir_path, "/.");
    //         dir = opendir(dir_path);
    //     }
    // }
    // puts(dir_path);
    // puts("here!");
    // struct dirent* new_dP = readdir(dir);
    // puts("here2");
    // while (new_dP){
    //     printf("%s\n", new_dP->d_name);
    //     new_dP = readdir(dir);
    // }



    // puts("Finish");

    // DIR* dir = opendir(args[1]);

    // if(!dir) { printf("ERROR!\n"); exit(1);}
    
    // struct dirent *d = readdir(dir);

    // printf("%-50s %ld\n", args[1], d->d_ino);
    // printf("%ld\n", d->d_ino);
    // printf("%s\n", d->d_name);
    // printf("%d\n", d->d_reclen);
    // printf("%u\n", d->d_type);

    // d = readdir(dir);
    // printf("%-50s %ld\n", args[1], d->d_ino);
    // printf("%ld\n", d->d_ino);
    // printf("%s\n", d->d_name);
    // printf("%d\n", d->d_reclen);
    // printf("%u\n", d->d_type);

    // d = readdir(dir);
    // // rewinddir(dir);
    // // d = readdir(dir);

    // printf("%-50s %ld\n", args[1], d->d_ino);
    // printf("%ld\n", d->d_ino);
    // printf("%s\n", d->d_name);
    // printf("%d\n", d->d_reclen);
    // printf("%u\n", d->d_type);

    // long int loc = telldir(dir);
    // printf("%ld\n", loc);

    // seekdir(dir, loc);

    // d = readdir(dir);
    // printf("%-50s %ld\n", args[1], d->d_ino);
    // printf("%ld\n", d->d_ino);
    // printf("%s\n", d->d_name);
    // printf("%d\n", d->d_reclen);
    // printf("%u\n", d->d_type);

    // // struct dirent* entry = NULL;
    // // struct dirent* result = NULL;
    // // readdir_r(dir, entry, &result);

    // closedir(dir);



    // char** arr_str = (char**) malloc (3* sizeof(char*));

    // for (int i = 0; i < 3; i++)
    // {
    //     arr_str[i] = (char*) malloc (50 * sizeof(char));
    //     fgets(arr_str[i], 50, stdout);
    //     arr_str[i][strlen(arr_str[i])-1] = '\0';
    // }

    // for (int i = 0; i < 3; i++){
    //     printf("%s\n", arr_str[i]);
    //     printf("%d\n", arr_str[i][0] - '0');
    // }

    // qsort(arr_str, 3, sizeof(char*), comp);

    //     for (int i = 0; i < 3; i++)
    //     printf("%s\n", arr_str[i]);


    // char* str1 = "Hello world!";
    // char* str2 = "wor";

    // printf("%ld\n", strcspn(str1, str2));


    return 0;
}


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
//             printf("%s\n", entry->d_name);
//         }
//         //     file = (char*) malloc ((strlen(entry->d_name)+1) * sizeof(char));
//         //     strcpy(file, entry->d_name);
//         //     dir_path = realloc(dir_path, strlen(dir_path) + 2);
//         //     strcat(dir_path, "/");
            
//         //     dir_file = (char*) malloc (sizeof(char) * (strlen(dir_path)+1));
//         //     strcpy(dir_file, dir_path);
//         //     strcat(dir_file, file);

//         //     FILE* file_txt = fopen(dir_file, "r");
//         //     char ch;
//         //     while ((ch = fgetc(file_txt)) != EOF)
//         //     {
//         //         fputc(ch, res_file);
//         //     }
//         //     fclose(file_txt);
//         //     // free(dir_file);
//         //     // free(file_txt);
//         //     free(file);
//         // }
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