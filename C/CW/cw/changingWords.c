#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include <string.h>
#include "structs.h"
#include "text_and_sentences.h"

//-------------------------------------------------------------------------------------------------
//Четвертая функция: Замена слов

void addIndex(int** arr, size_t* size, size_t* cap, int index) {
    if (!*arr) {
        *cap = 10;
        *arr = (int*)malloc(sizeof(int) * *cap);
        (*arr)[0] = index;
        *size = 1;
        return;
    }
    if (*size + 1 <= *cap) {
        (*arr)[*size] = index;
        ++*size;
        return;
    }
    *cap *= 2;
    int* t = (int*)malloc(sizeof(int) * *cap);
    memcpy(t, *arr, sizeof(int) * *size);
    free(*arr);
    t[*size] = index;
    ++*size;
    *arr = t;
}

void changeWord(Text* t, const wchar_t* old, const wchar_t* new) {
    for (size_t i = 0; i < t->size; ++i) {

        int* indexes = NULL;                                                                //Массив индексов слов в предложении
        size_t indexes_size = 0;
        size_t indexes_cap = 0;

        wchar_t* cpy = (wchar_t*)malloc(sizeof(wchar_t) * t->text[i]->size);
        memcpy(cpy, t->text[i]->sentence, t->text[i]->size * sizeof(wchar_t));
        wchar_t* buffer;
        wchar_t* pt = wcstok(cpy, L" ,.", &buffer);
        while (pt) {
            if (wcscmp(pt, old) == 0) {
                addIndex(&indexes, &indexes_size, &indexes_cap, pt - cpy);                  //pt - cpy - получаем индекс слова в предложении
            }
            pt = wcstok(NULL, L" ,.", &buffer);
        }
        free(cpy);
        if (indexes_size > 0) {
            Sentence* ns = createSentence();
            size_t j = 0;
            size_t c = 0;
            while (c != indexes_size) {
                while (j != indexes[c]) {                                                   //Добавляем символы до индекса заменяемого слова
                    addOneSymbol(ns, t->text[i]->sentence[j++]);
                }
                const wchar_t* pt = new;
                while (*pt != L'\0') {                                                      //Добавляем символы заменямого слова
                    addOneSymbol(ns, *pt++);
                }
                j += wcslen(old);
                ++c;
            }
            while (t->text[i]->sentence[j] != L'\0') {
                addOneSymbol(ns, t->text[i]->sentence[j++]);
            }
            addOneSymbol(ns, L'\0');

            free(indexes);

            deleteSentence(&t->text[i]);
            t->text[i] = ns;
        }
    }
}
