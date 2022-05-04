#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include <string.h>
#include "structs.h"

//-------------------------------------------------------------------------------------------------
//Структуры и функции связанные с предложениями


// typedef struct Sentence {
//     size_t size;
//     size_t capacity;
//     wchar_t* sentence;
// } Sentence;

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


//-------------------------------------------------------------------------------------------------
//Структура и функции связанные с Текстом

// typedef struct Text {
//     size_t size;
//     size_t capacity;
//     Sentence** text;
// } Text;


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


//-------------------------------------------------------------------------------------------------
//Функции связанные с созданием предложений

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
    if (symbol == L'\n') {
        *weof = 1;
    }
    return s;
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


//-------------------------------------------------------------------------------------------------
//Печать текста на экран

void printText(Text* t) {
    for (size_t i = 0; i < t->size; ++i) {
        wprintf(L"%ls\n", t->text[i]->sentence);
    }
    wprintf(L"\n");
}


//-------------------------------------------------------------------------------------------------


wint_t myWCmp(const wchar_t* a, const wchar_t* b)
{
    while (*a && *b && towlower(*a) == towlower(*b)) { ++a; ++b; }
    return towlower(*a) - towlower(*b);
}

//Полный текст уже после удаления одинаковых предложений
Text* getFullSentencesText() {
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