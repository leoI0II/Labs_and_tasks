// // #include <stdio.h>
// // #include <stdlib.h>
// // #include <wchar.h>

// // typedef wchar_t * kek;


// // int main(){

// //     kek str = (kek) malloc (sizeof(kek) * 10);
// //     fgetws(str, 10, stdin);

// //     wprintf(L"%ls", str);

// //     return 0;
// // }


// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include <wchar.h>

// wchar_t* addOneSymbol(wchar_t** pstr, size_t* size, size_t* capacity, wchar_t symbol) {
//     if (!*pstr) {
//         *pstr = (wchar_t*)malloc(sizeof(wchar_t) * 2);
//         (*pstr)[0] = symbol;
//         (*pstr)[1] = '\0';
//         *size = 2;
//         *capacity = 2;
//         return *pstr;
//     }
//     if (*size + 1 <= *capacity) {
//         (*pstr)[*size-1] = symbol;
//         (*pstr)[*size] = '\0';
//         ++*size;
//         return *pstr;
//     }
//     wchar_t* t = (wchar_t*)malloc(sizeof(wchar_t) * *capacity);
//     *capacity += 2;
//     wcscpy(t, *pstr); free(*pstr);
//     t[*size-1] = symbol; t[*size] = '\0';
//     ++*size;
//     *pstr = t;
//     //free(t);
//     return *pstr;
// }

// wchar_t* readOneSentence(int* eof, size_t* size) {
//     wchar_t* str = NULL;
//     size_t capacity = 0;
//     // size_t size = 0;
//     wchar_t symbol;
//     while (!(((symbol = fgetwc(stdin)) == '?') || (symbol == ';') ||(symbol == '.') || (symbol == '!'))) {
//         // if (!addOneSymbol(&str, &size, &capacity, symbol)) {
//         //     return NULL;
//         // }
//         addOneSymbol(&str, size, &capacity, symbol);
//     }
//     if (!addOneSymbol(&str, size, &capacity, symbol)) {
//         return NULL;
//     }
//     symbol = fgetwc(stdin);
//     if (symbol == EOF || symbol == '\n') *eof = 1;
//     return str;
// }


// // int check(const char* token) {
// //     for (int i = 1; i < strlen(token)-1; ++i) {
// //         if (isdigit(token[i])) {
// //             if (!((isdigit(token[0])) && (isdigit(token[strlen(token) - 1])))) {
// //                 return 0;
// //             }
// //         }
// //     }
// //     return 1;
// // }


// void PrintSentence(const wchar_t* str, wchar_t** text, size_t* count_sentence, size_t* size) {
//         text[*count_sentence] = (wchar_t*) malloc ( (*size) * sizeof(wchar_t) );
//         for (size_t i = 0; i < *size ; i++ ){
//             text[*count_sentence][i] = str[i];
//         }
//         *count_sentence += 1;
// }

// int main() {

//     wchar_t** text = (wchar_t**) malloc (sizeof (wchar_t*));
//     wchar_t* str = NULL;
//     int eof = 0; size_t count_sentence = 0, size = 0;

//     while (!eof) {
//         str = readOneSentence(&eof, &size);
//         PrintSentence(str, text, &count_sentence, &size);
//         text = (wchar_t**) malloc (sizeof(wchar_t*) * (1 + count_sentence));
//         size = 0;
//     }

//     for (size_t i = 0 ; i < count_sentence; i++){
//         wprintf(L"%ls\n", text[i]);
//     }

//     return 0;
// }






#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>

typedef struct Sentence {
    size_t size;
    size_t capacity;
	wchar_t* sentence;
} Sentence;

Sentence* createSentence() {
    Sentence* s = (Sentence*)malloc(sizeof(Sentence));
    if (!s) {
        fprintf(stderr, "Can\'t allocate memory!\n");
        return NULL;
    }
    s->capacity = 0;
    s->size = 0;
    s->sentence = NULL;
    return s;
}

void deleteSentence(Sentence** ps) {
    if (*ps) {
        if ((*ps)->sentence) {
            free((*ps)->sentence);
        }
        free(*ps);
        *ps = NULL;
    }
}

typedef struct Text {
	size_t size;
	size_t capacity;
	Sentence** text;
} Text;

wchar_t* addOneSymbol(Sentence* ps, wchar_t symbol) {
    if (!ps) {
        fprintf(stderr, "Poor sentence!\n");
        return NULL;
    }
    if (!ps->sentence) {
        ps->sentence = (wchar_t*)malloc(sizeof(wchar_t) * 2);
        if (!ps->sentence) {
            fprintf(stderr, "Can\'t allocate memory!\n");
            deleteSentence(&ps);
            return NULL;
        }
        (ps->sentence)[0] = symbol;
        (ps->sentence)[1] = L'\0';
        ps->size = 2;
        ps->capacity = 2;
        return ps->sentence;
    }
    if (ps->size + 1 <= ps->capacity) {
        (ps->sentence)[ps->size - 1] = symbol;
        (ps->sentence)[ps->size] = L'\0';
        ++ps->size;
        return ps->sentence;
    }
    wchar_t* t = (wchar_t*)malloc(sizeof(wchar_t) * 2 * ps->capacity);
    if (!t) {
        fprintf(stderr, "Can\'t allocate memory!\n");
        deleteSentence(&ps);
        return NULL;
    }
    ps->capacity *= 2;
    wcscpy(t, ps->sentence);
    free(ps->sentence);
    t[ps->size - 1] = symbol;
    t[ps->size] = L'\0';
    ++ps->size;
    ps->sentence = t;
    return ps->sentence;
}

Sentence* readOneSentence(int* weof) {
    Sentence* s = createSentence();
    wchar_t symbol;
    while (!((symbol = fgetwc(stdin)) == L'.')) {
        if (!addOneSymbol(s, symbol)) {
            deleteSentence(&s);
            return NULL;
        }
    }
    if (!addOneSymbol(s, symbol)) {
        deleteSentence(&s);
        return NULL;
    }
    symbol = fgetwc(stdin);
    if (symbol == '\n') {
        *weof = 1;
    }
    return s;
}

Text* createText() {
    Text* t = (Text*)malloc(sizeof(Text));
    if (!t) {
        fprintf(stderr, "Can\'t allocate memory!\n");
        return NULL;
    }
    t->capacity = 0;
    t->size = 0;
    t->text = NULL;
    return t;
}

void deleteText(Text** ptext) {
    if (*ptext) {
        if ((*ptext)->text) {
            for (size_t i = 0; i < (*ptext)->size; ++i) {
                deleteSentence(&(*ptext)->text[i]);
            }
            free((*ptext)->text);
        }
        free(*ptext);
        *ptext = NULL;
    }
}

Sentence* addOneSentence(Text* ptext, Sentence* s) {
    if (!ptext) {
        fprintf(stderr, "Poor text!\n");
        return NULL;
    }
    if (!ptext->text) {
        ptext->text = (Sentence**)malloc(sizeof(Sentence*) * 2);
        if (!ptext->text) {
            fprintf(stderr, "Can\'t allocate memory!\n");
            deleteText(&ptext);
            return NULL;
        }
        (ptext->text)[0] = s;
        ptext->size = 1;
        ptext->capacity = 2;
        return s;
    }
    if (ptext->size + 1 <= ptext->capacity) {
        (ptext->text)[ptext->size] = s;
        ++ptext->size;
        return s;
    }
    Sentence** t = (Sentence**)malloc(sizeof(Sentence*) * 2 * ptext->capacity);
    if (!t) {
        fprintf(stderr, "Can\'t allocate memory!\n");
        deleteText(&ptext);
        return NULL;
    }
    ptext->capacity *= 2;
    memcpy(t, ptext->text, sizeof(Sentence*) * ptext->size);
    free(ptext->text);
    t[ptext->size] = s;
    ++ptext->size;
    ptext->text = t;
    return s;
}

void printText(Text* t) {
    for (size_t i = 0; i < t->size; ++i) {
        wprintf(L"%ls\n", t->text[i]->sentence);
    }
}

wint_t myWCmp(const wchar_t* a, const wchar_t* b)
{
    while (*a && towlower(*a) == towlower(*b)) { ++a; ++b; }
    return towlower(*a) - towlower(*b);
}

Text* getUniqueSentencesText() {
    Sentence* s = NULL;
    Text* t = NULL;
    t = createText();
    int weof = 0;
    while (!weof) {
        s = readOneSentence(&weof);
        int n = 1;
        for (size_t i = 0; i < t->size; ++i) {
            if (myWCmp(s->sentence, t->text[i]->sentence) == 0) {
                n = 0;
                deleteSentence(&s);
                break;
            }
        }
        if (n == 1) {
            addOneSentence(t, s);
        }
    }
    return t;
}


int main() {
    Text* t = getUniqueSentencesText();
    printText(t);
    deleteText(&t);
	return 0;
}