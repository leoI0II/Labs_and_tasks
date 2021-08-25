#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>
#include<string.h>
#include<ctype.h>

int comp(const void *a, const void *b);

void rec_check_dir(char* cur_dir, FILE* log, FILE* texts)
{
    fprintf(log, "current dir - %s\n", cur_dir);
    DIR* cur_open_dir = opendir(cur_dir);
    if (!cur_open_dir)
        return;

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
                fprintf(log, "filename and dir - %s/%s\n",cur_dir, entry->d_name);
                
                char *file = (char*) malloc (strlen(cur_dir)+1+strlen(entry->d_name) + 1);
                strcpy(file, cur_dir);
                strcat(file, "/");
                strcat(file, entry->d_name);

                FILE* open_file = fopen(file, "r");

                char str_from_file[256];
                while (fgets(str_from_file, 256, open_file) != NULL)
                    fputs(str_from_file, texts);

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
                    rec_check_dir(tmp, log, texts);
                    free(tmp);
                    // free(cpy_cur_dir);
                }
                else
                {
                    cpy_cur_dir = (char*) realloc(cpy_cur_dir, 1 + strlen(cur_dir) +1 + strlen(entry->d_name));
                    strcpy(cpy_cur_dir, cur_dir);
                    strcat(cpy_cur_dir, "/");
                    strcat(cpy_cur_dir, entry->d_name);
                    fprintf(log, "Next dir %s\n-->Cur is %s\n", cpy_cur_dir, cur_dir);
                    char* tmp = (char*) malloc (strlen(cpy_cur_dir)+1);
                    strcpy(tmp, cpy_cur_dir);
                    rec_check_dir(tmp, log, texts);
                    free(tmp);
                    // free(cpy_cur_dir);
                }
            }
    }
    fprintf(log, "Current dir is finished %s\n", cur_dir);
    closedir(cur_open_dir);
    return;
}


int main()
{
    FILE* log = fopen("new_log_4lab", "w");
    FILE* texts = fopen("_textx", "w");
    rec_check_dir("/home/leo11/Projects/C", log, texts);
    fclose(log);
    fclose(texts);

    FILE* _texts = fopen("_textx", "r");
    char str_from_file[256];
    char** array_str = (char**) malloc (sizeof(char*));
    // puts("here13");
    int counter = 0;
    while (fgets(str_from_file, 256, _texts) != NULL)
    {
        array_str[counter] = (char*) malloc (strlen(str_from_file)+1);
        strcpy(array_str[counter], str_from_file);
        counter++;
        array_str = (char**) realloc(array_str, (counter+1)* sizeof(char*));
    }
    fclose(_texts);
// puts("here14");

    qsort(array_str, counter, sizeof(char*), comp);

    FILE* result = fopen("last_result", "w");

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