#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>
#include<string.h>
#include<ctype.h>


void rec_check_tree(char* dir_path, FILE* res_file)
{
    DIR* open_dir = opendir(dir_path);
    if (!open_dir){
        return;
    }
    puts("here1");
    struct dirent* entry = readdir(open_dir);
    puts("here2");
    char* next_folder, *folder, *file, *dir_file;
    while (entry)
    {
        long int strLen = strlen(entry->d_name);
        if (entry->d_type == DT_REG &&
            entry->d_name[strLen -1] == 't' &&
            entry->d_name[strLen -2] == 'x' &&
            entry->d_name[strLen -3] == 't' &&
            entry->d_name[strLen -4] == '.')
        {
            file = (char*) malloc (strlen(dir_path) + 1 + strlen(entry->d_name) +1);
            strcpy(file, dir_path);
            strcat(file, "/");
            strcat(file, entry->d_name);

            puts("here3");

            FILE* file_txt = fopen(file, "r");


            char files_str[256];
            while (fgets(files_str, 256, file_txt) != NULL)
                fputs(files_str, res_file);

            // if (feof(file_txt))
            //     printf("all ok!\n");

            fclose(file_txt);

            free(file);

        }
        else if (entry->d_type == DT_DIR && strcmp(entry->d_name, "..") && strcmp(entry->d_name, "."))
        {
            folder = (char*) malloc ((strlen(entry->d_name)+1) * sizeof(char));
            strcpy(folder, entry->d_name);
            puts("here4");
            if (strcmp(dir_path, "/") == 0){
                puts("here5");
                next_folder = (char*) malloc ((strlen(dir_path) + strlen(folder) +1) * sizeof(char));
                puts("here6");
                strcpy(next_folder, dir_path);
                strcat(next_folder, folder);
                rec_check_tree(next_folder, res_file);
            }
            else
            {

                if (dir_path[strlen(dir_path) -1] != '/'){
                    puts("here7");
                    char* tmp = (char*) malloc (strlen(dir_path)+2);
                    puts("here8");
                    strcpy(tmp, dir_path);
                    strcat(tmp, "/");
                    dir_path = (char*) malloc (strlen(tmp));
                    strcpy(dir_path, tmp);
                    free(tmp);
                }
                puts("here9");
                next_folder = (char*) malloc ((strlen(dir_path) + strlen(entry->d_name)+1) * sizeof(char));
                puts("here10");
                strcpy(next_folder, dir_path);
                strcat(next_folder, entry->d_name);
                rec_check_tree(next_folder, res_file);
            }

        }
        entry = readdir(open_dir);
    }

    closedir(open_dir);
    return;
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

int main()
{
    FILE* text_txt = fopen("text.txt", "w");
    rec_check_tree("/home/leo11/Projects/C", text_txt);
    fclose(text_txt);
    puts("here11");
    FILE* res_txt = fopen("text.txt", "r");
    puts("here12");
    char str_from_file[256];
    char** array_str = (char**) malloc (sizeof(char*));
    puts("here13");
    int counter = 0;
    while (fgets(str_from_file, 256, res_txt) != NULL)
    {
        array_str[counter] = (char*) malloc (strlen(str_from_file)+1);
        strcpy(array_str[counter], str_from_file);
        counter++;
        array_str = (char**) realloc(array_str, (counter+1)* sizeof(char*));
    }
    fclose(res_txt);
puts("here14");

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