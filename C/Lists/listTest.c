#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// typedef struct list
// {
//     int data;
//     struct list* node;
// }List;



// int main()
// {
//     List* head = (List*) malloc (sizeof(List));
//     head->data = 100;

//     List* tmp = (List*) malloc (sizeof(List));
//     head->node = tmp;

//     for (int i = 0; i < 9; ++i)
//     {
//         tmp->data = 101 + i;
//         tmp->node = (List*) malloc (sizeof(List));
//         tmp->node->node = NULL;
//         tmp = tmp->node;
//     }
//     List* temp = (List*) malloc (sizeof(List));
//     temp = head;
//     printf("[");
//     for (int i = 0; i < 10; ++i)
//     {
//         printf("%d ", temp->data);
//         temp = temp->node;
//     }
//     printf("]\n");

//     return 0;
// }



// int main(int argc, char** argv)
// {
//     // printf("We have %d arguments\n", argc);
//     // for (int i = 0; i < argc; ++i)
//     // {
//     //     printf("Arg%d: %s\n", i, argv[i]);
//     // }

//     for (int i = 1; i < argc; ++i)
//     {
//         if (strcmp(argv[i], "--show_info") == 0)
//             printf("You entered %d arguments.\n", argc);
//         if (strcmp(argv[i], "--show_args") == 0)
//             for (int i = 1; i < argc; ++i)
//             {
//                 printf("%s\n", argv[i]);
//             }
//     }
//     return 0;
// }



// int main()
// {
//     char name_for_remove[80];
//     fgets(name_for_remove, 80, stdin);
//     printf("%s\nlol", name_for_remove);
//     (*strstr(name_for_remove,"\n")) = '\0';
//     printf("%s\nlol", name_for_remove);

//     return 0;
// }

//test vvoda IP adressa
// int main()
// {
//     int a, b, c, d;
//     scanf("%d.%d.%d.%d", &a, &b, &c, &d);
//     printf("%d %d %d %d\n", a, b, c, d);
//     return 0;
// }

static unsigned int count = 0;

typedef struct List{
    int data;
    struct List* next;
    struct List* prev;
}Node;

void creatNode(Node* head, int data)
{
    count++;
    while(head->next != NULL)
        head = head->next;
    
    Node* cur = (Node*) malloc(sizeof(Node));
    cur->data = data;
    head->next = cur;
    cur->prev = head;
    cur->next = NULL;
}

void printListForward(Node *head)
{
    // for (int i = 0; i < count; i++){
    //     printf("%d ", head->data);
    //     head = head->next;
    // }
    // printf("\n");

    while (head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void printListBackward(Node *head)
{
    while(head->next != NULL)
        head = head->next;

    // for (int i = count; i > 0; i--)
    // {
    //     printf("%d ", head->data);
    //     head = head->prev;
    // }
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->prev;
    }

    printf("\n");

}

void pushForward(Node* head, int data)
{
    count++;
    while(head->next != NULL){
        head = head->next;
    }
    Node* new = (Node*) malloc (sizeof(Node));
    new->data = data;
    head->next = new;
    new->next = NULL;
    new->prev = head;
}

// void anotherPrint(Node* head){
//     for (int i = 0; i < count; i++)
//     {
//         printf("%d ", head->data);
//         head = head->next;
//     }
//     printf("\n");
// }

void pushBack(Node* head, int data)
{
    count++;

    Node* new = (Node*) malloc (sizeof(Node));
    Node* tmp = (Node*) malloc (sizeof(Node));
    
    *tmp = *head;

    // head->prev = head;

    new->next = new;
    new->prev = NULL;
    new->data = data;
    *head = *new;
    *new = *tmp;
    tmp->next->prev = new;
    new->prev = head;
    

    // new->data = data;
    // new->prev = NULL;
    // new->next = head;
    // head->prev = new;
    // *head = *new;
    // *new = *tmp;

    // *head = *new;
    // *new = *tmp;
    // head->prev = NULL;
    // head->next = new;
    // head->data = data;
    // new->data = tmp->data;
    // new->next = tmp->next;
    // new->prev = head;
    // tmp->next->prev = new;

}

void insertElemInd(Node* head, int data, int index)
{
    // count++;
    Node* cur = (Node*) malloc (sizeof(Node));
    cur->data = data;
    for (int i = 1; i < index; i++)
        head = head->next;
    
    Node* tmp = (Node*) malloc(sizeof(Node));

    *tmp = *head;
    head->next = cur;
    cur->next = tmp->next;
    cur->prev = head;
    tmp->next->prev = cur;
    free(tmp);
    count++;
}

void insertElem(Node* head, int data, int afterData)
{
    count++;
    Node* cur = (Node*) malloc (sizeof(Node));
    cur->data = data;
    while(head->data != afterData)
        head = head->next;

    Node* tmp = (Node*) malloc (sizeof(Node));

    *tmp = *head;
    head->next = cur;
    cur->next = tmp->next;
    tmp->next->prev = cur;
    cur->prev = head;

    free(tmp);
}
//это я пишу комментарий
void deleteElem(Node* head, int elem)
{
    while (head != NULL) // 
    {
        if (head->data == elem)
        {
            if (head->prev != NULL && head->next == NULL){
                head->prev->next = NULL;
                count--;
                // free(head);
                return;
            }
            else if(head->prev != NULL){
                head->prev->next = head->next;
                head->next->prev = head->prev;
                count--;
                // free(head);
                return;
            }
            else
            {
                // head->next->prev = NULL;
                Node* tmp = head;
                tmp = tmp->next;
                
                // tmp->prev->data = 155;
                // tmp->data = 1222;
                tmp->prev = NULL;
                // printf("head %p\n", head);
                // printf("tmp %p\n", tmp);
                *head = *tmp;

                count--;
                return;
            }
        }
        head = head->next;
    }
    printf("No one elem found!\n");
}

void qw(char* str){
    printf("%p\n", str);
    while (*(str++))
        printf("%c", *str);
    printf("%p\n", str);
}

void swap(Node* head, int x, int y)
{
    Node* tmp = (Node*) malloc (sizeof(Node));

    *tmp = *head;

    while( head != NULL && head->data != x)
    {
        head = head->next;
    }

    if (head == NULL){
        printf("didn't find the first elem in the list!\n");
        return;
    }

    while (tmp && tmp->data != y)
        tmp = tmp->next;

    if (tmp == NULL)
    {
        printf("didn't find the second elem in the list!\n");
        return;
    }

    // Node* tmp2 = tmp;
    // Node* tmpH = head;

    // head->prev->next = tmp;
    // head->next->prev = tmp;
    // head->next = tmp->next;
    // head->prev = tmp->prev;

    // tmp2->prev->next = head;
    // tmp2->next->prev = head;
    // tmp2->next = tmpH->next;
    // tmp2->prev = tmpH->prev;



    Node* tmp2 = (Node*) malloc (sizeof(Node));

    Node* nextTmp = (tmp)->next;
    Node* nextHead = (head)->next;
    Node* prevTmp = tmp->prev;
    Node* prevHead = head->prev;

    // printf("%p\t%d\t%p\t%p\n", head, (head)->data, (head)->next, (head)->prev);
    // printf("%p\t%d\t%p\t%p\n",tmp, (tmp)->data, (tmp)->next, (tmp)->prev);

    *tmp2 = *head;
    *head = *tmp;
    *tmp = *tmp2;

    head->next = nextHead;
    tmp->next = nextTmp;
    head->prev = prevHead;
    tmp->prev = prevTmp;

    // printf("%p\t%d\t%p\t%p\n", head, (head)->data, (head)->next, (head)->prev);
    // printf("%p\t%d\t%p\t%p\n",tmp, (tmp)->data, (tmp)->next, (tmp)->prev);

    return;
}

Node* del_second(Node* head){
    int count = 0;
    Node* tmp = head;
    while (head->next!=NULL){
        if(count%2 == 0 && count!=0){
            head->prev->next = head->next;
            head->next->prev = head->prev;
            head = head->next;
            count++;
        }
        else if(count == 0){
            head = head->next;
            head->prev->next = NULL;
            head->prev = NULL;
            tmp = head;
            count++;
        }
        else {
            count++;
            head = head->next;
        }
    }
    if(count%2==0){
        head->prev->next = NULL;
    }
    return tmp;
}

void swap_p(Node **a, Node **b){
  Node *tmp = *a;
  *a = *b;
  *b = tmp;
}

void swap_nodes(Node *a_pred, Node *b_pred){
  if(a_pred == b_pred)
    return;
  Node *a = a_pred->next;
  Node *b = b_pred->next;
  if(b->next == a){ // if a > b in order
    swap_p(&a, &b);
    swap_p(&a_pred, &b_pred);
  }
  if(a->next == b){
    a_pred->next = b;
    a->next = b->next;
    b->next = a;
    return;
  }
  swap_p(&(a->next), &(b->next));
    swap_p(&(a_pred->next), &(b_pred->next));
}

//void swap(struct Elem** head, struct Elem* a_prev, struct Elem* b_prev){
//
//    struct Elem * b = b_prev->next;
//    struct Elem * a = *head;
//    struct Elem* tmp = b->next;
//    if(a_prev == NULL){
//        b->next = a->next;
//        a->next=tmp;
//        b_prev ->next=a;
//        *head=b;
//        return;
//    }
//    a = a_prev->next;
//    if(b_prev == a){
//        a_prev->next = b;
//        b->next = a;
//        a->next = tmp;
//        return;
//    }
//    b->next = a->next;
//    a->next = tmp;
//    tmp = b_prev->next;
//    b_prev->next=a_prev->next;
//    a_prev->next=tmp;
//}
//
//void swap_use(struct Elem** head, int a, int b){
//    struct Elem *cur = *head;
//    struct Elem *a_prev = NULL;
//    struct Elem *b_prev = NULL;
//    while(cur->next){
//        if(cur->next->data == a)
//            a_prev = cur;
//        if(cur->next->data == b)
//            b_prev = cur;
//        cur = cur->next;
//    }
//    swap(head, a_prev, b_prev);
//}
//
//void sort(struct Elem**head){
//    struct Elem*cur = *head;
//    struct Elem *cur_prev = NULL;
//    while(cur){
//        if(cur->data > cur->next->data){
//            swap(head,cur_prev, cur);
//        }
//        cur_prev = cur;
//        cur = cur->next;
//    }
//}

int main()
{   
    Node* head = (Node*) malloc (sizeof(Node));
    count++;
    head->prev = NULL;
    head->data = 10;
    puts("1");
    creatNode(head, 20);
    puts("2");
    creatNode(head, 30);
    puts("3");
    creatNode(head, 40);

    // printf("%p\n", head);

    printListForward(head);

    // printf("%p\n", head);


    // char* strr = (char*) malloc (50 * sizeof(char));
    // fgets(strr, 50, stdin);
    // strr[strlen(strr) -1] = '\0';
    // printf("%p\n", strr);
    // qw(strr);
    // printf("%s\n", strr);
    // printf("%p\n", strr);


    printListBackward(head);


    pushForward(head, 50);
    printListForward(head);
    printListBackward(head);

    pushBack(head, 5);
    printListForward(head);
    printListBackward(head);
    puts("!");
    
    insertElemInd(head, 24, 2);
    printListForward(head);
    printListBackward(head);
    puts("!");

    insertElem(head, 44, 40);
    printListForward(head);
    printListBackward(head);
    puts("!");

    // printf("%p\n", head);
    deleteElem(head, 5);
    // printf("%p\n", head);
    printListForward(head);
    printListBackward(head);
    puts("!");

    swap(head, 24, 20);
    printListForward(head);
    printListBackward(head);

    // printListBackward(head);


    return 0;
}