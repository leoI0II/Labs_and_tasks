#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include <string.h>
#include "structs.h"

//-------------------------------------------------------------------------------------------------
//Вторая функция: сортировка предложений по кол-ву заглавных букв

int comp(const void* a, const void* b) {
    Sentence* s1 = *(Sentence**)a;
    Sentence* s2 = *(Sentence**)b;
    int c1 = 0;
    for (size_t i = 0; s1->sentence[i] != L'\0'; ++i) {             //Проверяем каждый символ предложения на то, является ли он заглавным
        if (iswupper(s1->sentence[i])) {                            //если да, инкрементируем наш флаг
            ++c1;
        }
    }
    int c2 = 0;
    for (size_t i = 0; s2->sentence[i] != L'\0'; ++i) {
        if (iswupper(s2->sentence[i])) {
            ++c2;
        }
    }
    return c1 - c2;
}

void sort(Text* t) {
    qsort((void*)t->text, t->size, sizeof(Sentence*), comp);
}