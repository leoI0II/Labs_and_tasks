//1)
// #include <stdlib.h>
// #include <stdio.h>
// #include <ctype.h>
// #include <string.h>
 
// struct Stack{
//     char info;
//     struct Stack *next;
// };
// struct Stack* CreateElem(char val, struct Stack *next){
//     struct Stack *newElem = malloc(sizeof(struct Stack));
//     newElem->info = val;
//     newElem->next = next;
//     return newElem;
// }
// void push(struct Stack **head, char val){
//     if(!(*head)){
//         struct Stack *newElem = CreateElem(val, *head);
//         *head = newElem;
//     }
//     struct Stack *header = *head;
//     while(header->next != NULL)
//         header = header->next;
//     struct Stack *newElem = CreateElem(val, NULL);
//     header->next = newElem;
// }
// size_t size(struct Stack *head){
//     struct Stack *header = head;
//     int count = 0;
//     if(header == NULL) return 0;
//     while(header->next != NULL){
//         header = header->next;
//         count++;
//     }
//     return count;
// }
// void pop(struct Stack **head){
//     struct Stack *header = *head;
//     if(header == NULL) return;
//     if(size(*head) == 1){
//         free(*head);
//         *head = NULL;
//         return;
//     }
//     while(header->next->next != NULL){
//         header = header->next;
//     }
//     header->next = NULL;
// }
// char top(struct Stack *head){
//     while(head->next != NULL)
//         head = head->next;
//     return head->info;
// }
// int IsEmpty(struct Stack *head){
//     if(head == NULL) return 0;
//     else return 1;
// }
 
// int main(){
 
//     struct Stack *head = NULL;
//     char *a = malloc(500*sizeof(char));
//     fgets(a, 500, stdin);
//     for(int i=0; i<strlen(a); i++){
//         if(a[i] == '(' || a[i] == '[' || a[i] == '{' || a[i] == '<'){
//             push(&head, a[i]);
//         }
//         if(a[i] == ')' || a[i] == ']' || a[i] == '}' || a[i] == '>'){
//             if(IsEmpty(head) == 0){
//                 printf("wrong");
//                 return 0;
//             }
//             if(a[i] == ')' && top(head) == '('){
//                 pop(&head);
//             }
//             else if(a[i] == ']' && top(head) == '['){
//                 pop(&head);
//             }
//             else if(a[i] == '}' && top(head) == '{'){
//                 pop(&head);
//             }
//             else if(a[i] == '>' && top(head) == '<'){
//                 pop(&head);
//             }
//             else{
//                 printf("wrong");
//                 return 0;
//             }
//         }
//     }
//     printf("correct");
//     return 0;
// }


//////////////////////////////////////////////////////////////
//2)
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct Stack{
    char *arr[500];
    int peak;
};
void push(struct Stack *stack, char *val){
    stack->arr[++(stack->peak)] = val;
}
size_t size(struct Stack *stack){
    return stack->peak+1;
}
void pop(struct Stack *stack){
    stack->peak--;
}
char top(struct Stack *stack){
    char res =  *stack->arr[stack->peak];
    return res;
}
int IsEmpty(struct Stack *stack){
    if(stack->peak == -1) return 0;
    else return 1;
}

int main(){
    struct Stack stack = {{0}, -1};
    char *a = malloc(500*sizeof(char));
    fgets(a, 500, stdin);
    for(int i=0; i<strlen(a); i++){
        if(a[i] == '(' || a[i] == '[' || a[i] == '{' || a[i] == '<'){
            push(&stack, &a[i]);
        }
        if(a[i] == ')' || a[i] == ']' || a[i] == '}' || a[i] == '>'){
            if(IsEmpty(&stack) == 0){
                printf("wrong");
                return 0;
            }
            if(a[i] == ')' && top(&stack) == '('){
                pop(&stack);
            }
            else if(a[i] == ']' && top(&stack) == '['){
                pop(&stack);
            }
            else if(a[i] == '}' && top(&stack) == '{'){
                pop(&stack);
            }
            else if(a[i] == '>' && top(&stack) == '<'){
                pop(&stack);
            }
            else{
                printf("wrong");
                return 0;
            }
        }
    }
    if(IsEmpty(&stack) == 0) printf("correct");
    else printf("wrong");

    return 0;
}