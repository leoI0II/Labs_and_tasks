#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>
#include<string.h>
#include<ctype.h>

typedef struct 
{
    int count_lower;
    char file_name[200];
} answer_struct;

typedef struct Node_dir
{
    struct Node_dir *next_dir;
    struct Node_dir *prev_dir;
    char *dir;
}
        Node_dir;

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

void rec_check_dir(Node_dir* cur_dir, FILE*log, answer_struct* ans)
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

            FILE* f = fopen(file, "r");

            char strs_file[255];
            long low_count = 0;
            long *ptr_low_count = &low_count;
            fgets(strs_file, 255, f);
            while (!feof(f))
            {
                count_lowers(strs_file, ptr_low_count);
                fgets(strs_file, 255, f);
            }
            if (low_count > ans->count_lower)
            {
                ans->count_lower = low_count;
                strcpy(ans->file_name, entry->d_name);
            }
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

int main()
{
    answer_struct answer = {0, ""};

    Node_dir* head_direct = init_list("./text_files");

    FILE* log = fopen("log_task5_from_def", "w");

    rec_check_dir(head_direct, log, &answer);

    printf("%d; %s\n", answer.count_lower, answer.file_name);
    return 0;
}