// #include<stdio.h>
// #include<stdlib.h>

// typedef struct Node{
//     int n;
//     struct Node *next;
// } Node;

// Node* createNode(int data)
// {
//     Node* node = (Node*) malloc (sizeof(Node));
    
//     node->n = data;
//     node->next = NULL;
//     return node;
// }

// Node* createNodeList(int* datas)
// {    
//     Node* head = createNode(datas[0]);
//     Node* tmp = head;

//     for (int i = 1; i < 10; i++)
//     {
//         Node* node = createNode(datas[i]);
//         head->next = node;
//         head = node;
//     }
//     return tmp;
// }

// int solve(Node* head)
// {
//     while(head->next != NULL)
//     {
//         if (head->n > head->next->n)
//             return -1;
//         else
//             head = head->next;
//     }
//     return 1;
// }
// int main(){

//     int *nums = (int*) malloc (10* sizeof(int));

//     for (int i = 0; i < 10; i++)
//         scanf("%d", &nums[i]);

//     Node* head = createNodeList(nums);
    
//     int s = solve(head);

//     printf("%d\n", s);

//     return 0;
// }



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// typedef struct Node{
//     int n;
//     struct Node *next;
// } Node;


// Node* createNode(int data)
// {
//     Node* node = (Node*) malloc (sizeof(Node));
    
//     node->n = data;
//     node->next = NULL;
//     return node;
// }

// Node* createNodeList(int* datas, int count)
// {    
//     Node* head = createNode(datas[1]);
//     Node* tmp = head;

//     for (int i = 2; i < count; i++)
//     {
//         Node* node = createNode(datas[i]);
//         head->next = node;
//         head = node;
//     }
//     return tmp;
// }

// void print_data(Node* head)
// {
//     while(head)
//     {
//         printf("%d ", head->n);
//         head = head->next;
//     }
//     printf("\n");
// }

// void remove_item(Node* head, int del_elem)
// {
//     if (head->n == del_elem){
//         Node* tmp = head;
//         tmp = tmp->next;

//         *head = *tmp;
//         return;
//     }
//     Node* cpH = head;
//     head = head->next;
//     // printf("%p\n%p\n", cpH->next, head);
//     while (head)
//     {
//         if (head->n == del_elem && head->next == NULL)
//         {
//             cpH->next = NULL;
//             return;
//         }

//         if (head->n == del_elem)
//         {
//             cpH->next = head->next;
//             return;
//         }
//         cpH = head;
//         head = head->next;
//     }
// }

// int main()
// {
//     char *nums = (char*) malloc (1000 * sizeof(char));

//     fgets(nums, 1000, stdin);
//     nums[(strlen(nums)) - 1] = '\0';

//     int *numses = (int *) malloc (sizeof(int));
//     char *pch;
//     int i = 1;
//     pch = strtok(nums, " ");
//     while (pch != NULL){
//         numses[i-1] = atoi(pch);
//         pch = strtok(NULL, " ");
//         ++i;
//         numses = realloc(numses, i * sizeof(int));
//     }


//     int count_elem = i -1;
//     // for (int j = 0; j < count_elem; j++) printf("%d ", numses[j]);
//     // printf("\n");


//     Node* head = createNodeList(numses, count_elem);
//     // print_data(head);

//     remove_item(head, numses[0]);

//     print_data(head);

//     return 0;
// }



int main()
{
    FILE* fp;
    fp = fopen("file.txt", "w");
    if (fp == NULL){
        puts("Trubles!");
        exit(0);
    }

    char *str = (char*) malloc (30* sizeof(char));

    while (fgets(str, 30, stdin) && str[0] != '#')
    {
        // fprintf(fp, "%s\n", str);
        fputs(str, fp);
        free(str);
        str = (char*) malloc (30 * sizeof(char));
    }

    fclose(fp);


    return 0;
}