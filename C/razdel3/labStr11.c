#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>


// int delSentence(char **mainSent, int count);

// int main(){
//     int len_story = 1000000;
    
//     char * primal_text;
//     char ** main_text;
    
//     int j, i, count = 0, iter = -1, k;
    
//     primal_text = malloc(len_story * sizeof (char));
//     fgets(primal_text, len_story, stdin);
    
//     main_text = malloc (1000 * sizeof(char *));
    
//     for (int i = 0; i < strlen(primal_text); i++){
//         iter++;
//         if (primal_text[i] == '.' || primal_text[i] == '?' || primal_text[i] == ';'){
//             main_text[count] = malloc(10000 * sizeof (char));
//             for (k = 0, j = i - iter; j <= i; j++, k++){
//                 main_text[count][k] = primal_text[j];
//             }
//             main_text[count][k] = '\n'; count++; iter = -1; i++;
//         }
//     }
//     int new_count = delSentence(main_text, count);

//     for (i = 0 ; i < new_count ; i++){
//         printf("%s", main_text[i]);
//     }

//     return 0;
// }


// int delSentence(char **mainSent, int count){
//     int final_count = 0;

//     for (int i = 0; i < count; i++){
//         char **split_sentence = malloc(sizeof(char*));
//         char *spl = strtok(mainSent[i], " ,?;.");
        
//         for (int j = 0 ; spl != NULL ; j++){
        
//             split_sentence[j] = malloc(strlen(spl) * sizeof(char));
        
//             for (int k = 0 ; k < strlen(spl) ; k++){
//                 split_sentence[j][k] = spl[k];
//             }
        
//             split_sentence = realloc(split_sentence, j + 2);
//             spl = strtok(mainSent, " ,?;.");
//         }
        

//     }
// }


// int delSentence(char **mainSent, int count){
//     int returned_count = 0;
//     for (int i = 0 ; i < count ; i++){
            
//         char * splitted_word = strtok(mainSent[i], " ,?;.");
//         for (int j = 0 ; splitted_word != NULL ; j++){

//             for (int k = 1 ; k < strlen(splitted_word)-1 ; k++){

//                 if ( isdigit(splitted_word[k]) ){
                    
//                     returned_count++;
//                     //free(mainSent[i]);
//                     mainSent[i] = realloc(mainSent[i], strlen(mainSent[i + 1]));
                
//                     for (int t = 0; t <= strlen(mainSent[i + 1]) ; t++){
//                         mainSent[i][t] = mainSent[i + 1][t];
//                     }
//                     break;
//                 }
//             }
//         }
//         splitted_word = strtok(NULL, " ,?;.");
//     }
//     return returned_count;
// }



// int delSentence(char **mainSent, int count){
//     int return_count = 0;
// }



// int main(){




//     return 0;
// }

























#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* addOneSymbol(char** pstr, size_t* size, size_t* capacity, char symbol) {
    if (!*pstr) {
        *pstr = (char*)malloc(sizeof(char) * 2);
        (*pstr)[0] = symbol;
        (*pstr)[1] = '\0';
        *size = 2;
        *capacity = 2;
        return *pstr;
    }
    if (*size + 1 <= *capacity) {
        (*pstr)[*size-1] = symbol;
        (*pstr)[*size] = '\0';
        ++*size;
        return *pstr;
    }
    char* t = (char*)malloc(sizeof(char) * 2 * *capacity);
    *capacity += 2;
    strcpy(t, *pstr); free(*pstr);
    t[*size-1] = symbol; t[*size] = '\0';
    ++*size;
    *pstr = t;
    return *pstr;
}

char* readOneSentence(int* eof) {
    char* str = NULL;
    size_t capacity = 0;
    size_t size = 0;
    int symbol;
    while (!(((symbol = fgetc(stdin)) == '?') || (symbol == ';') ||(symbol == '.') || (symbol == '!'))) {
        if (!addOneSymbol(&str, &size, &capacity, symbol)) {
            return NULL;
        }
    }
    if (!addOneSymbol(&str, &size, &capacity, symbol)) {
        return NULL;
    }
    symbol = fgetc(stdin);
    if (strcmp(str, "Dragon flew away!") == 0) {
        *eof = 1;
    }
    return str;
}

// int check(const char* token) {
//     for (int i = 0; i < strlen(token); ++i) {
//         if ((isdigit(token[i])) && (i > 0) && (i < strlen(token) - 1)) {
//             return 0;
//         }
//     }
//     return 1;
// }



int check(const char* token) {
    for (int i = 0; i < strlen(token); ++i) {
        if ((isdigit(token[i])) && (i > 0) && (i < strlen(token) - 1)) {
            if (!((isdigit(token[0])) && (isdigit(token[strlen(token) - 1])))) {
                return 0;
            }
        }
    }
    return 1;
}




int PrintSentence(const char* str) {
    char* copy = (char*)malloc(sizeof(char) * (strlen(str) + 1));
    strcpy(copy, str);
    char* pch = strtok(copy, " ,.;?");
    while (pch != NULL) {
        if (check(pch)) {
            pch = strtok(NULL, " ,.;?");
        }
        else {
            return 0;
        }
    }
    fprintf(stdout, "%s\n", str);
    free(copy);
    return 1;
}

int main() {

    char* str = NULL;
    int eof = 0;

    int old = 0;
    int new = 0;

    while (!eof) {
        str = readOneSentence(&eof);
        ++old;
        if (str) {
            new += PrintSentence(str);
        }
        free(str);
    }

    printf("Количество предложений до %d и количество предложений после %d\n", old - 1, new - 1 );

    return 0;
}




























// int main(){

//     char str[22] = "Hello my dear friend!";

//     for (int i = 0; i < strlen(str); i++){
//         printf("%c", str[i]);
//         sleep(1);
//     }

//     return 0;
// }