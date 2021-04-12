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
    char* t = (char*)malloc(sizeof(char) * *capacity);
    *capacity += 2;
    strcpy(t, *pstr); free(*pstr);
    t[*size-1] = symbol; t[*size] = '\0';
    ++*size;
    *pstr = t;
    //free(t);
    return *pstr;
}

char* readOneSentence(int* eof) {
    char* str = NULL;
    size_t capacity = 0;
    size_t size = 0;
    char symbol;
    while (!(((symbol = fgetc(stdin)) == '?') || (symbol == ';') ||(symbol == '.') || (symbol == '!'))) {
        // if (!addOneSymbol(&str, &size, &capacity, symbol)) {
        //     return NULL;
        // }
        addOneSymbol(&str, &size, &capacity, symbol);
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
    for (int i = 1; i < strlen(token)-1; ++i) {
        if (isdigit(token[i])) {
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