#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include <string.h>
#include "structs.h"


int isVowel(wchar_t symbol) {                                                            //Проверяем, является ли символ гласной буквой
    symbol = towlower(symbol);
    if ((symbol == L'e') || (symbol == L'y') || (symbol == L'u') || (symbol == L'i') || (symbol == L'o') ||
        (symbol == L'a') || (symbol == L'у') || (symbol == L'е') || (symbol == L'ы') || (symbol == L'ё') ||
        (symbol == L'а') || (symbol == L'о') || (symbol == L'э') || (symbol == L'я') || (symbol == L'и') ||
        (symbol == L'ю')) {
        return 1;
    }
    return 0;
}

void changeTwoNextSymbol(Text* t) {
    for (size_t i = 0; i < t->size; ++i) {
        size_t new_size = t->text[i]->size;
        for (size_t j = 0; j < t->text[i]->size; ++j) {
            if (isVowel(t->text[i]->sentence[j])) {
                new_size += 1;                                                  //Считаем, сколько гласных в предложении
            }
        }
        wchar_t* s = (wchar_t*)malloc(sizeof(wchar_t) * new_size);              //Выделяем новую память в куче для измененного в дальнейшем предложения
        for (size_t j = 0, k = 0; j < t->text[i]->size; ++j) {
            wchar_t symbol = t->text[i]->sentence[j];
            if (isVowel(symbol)) {
                wchar_t s1;
                wchar_t s2;
                if ((symbol == L'д') || (symbol == L'Д')) {                     //Следующие три проверки (if) исключительно для проверки символа Ё/ё
                    if (iswupper(symbol)) {
                        s1 = L'Е';
                        s2 = L'Ё';
                    }
                    else {
                        s1 = L'е';
                        s2 = L'ё';
                    }
                    s[k++] = s1;
                    s[k++] = s2;
                    continue;
                }
                if ((symbol == L'е') || (symbol == L'Е')) {
                    if (iswupper(symbol)) {
                        s1 = L'Ё';
                        s2 = L'Ж';
                    }
                    else {
                        s1 = L'ё';
                        s2 = L'ж';
                    }
                    s[k++] = s1;
                    s[k++] = s2;
                    continue;
                }
                if ((symbol == L'ё') || (symbol == L'Ё')) {
                    if (iswupper(symbol)) {
                        s1 = L'Ж';
                        s2 = L'З';
                    }
                    else {
                        s1 = L'ж';
                        s2 = L'з';
                    }
                    s[k++] = s1;
                    s[k++] = s2;
                    continue;
                }
                if (iswupper(symbol)) {
                    if ((symbol >= L'A') && (symbol <= L'Z')) {
                        s1 = (symbol - L'A' + 1) % 26 + L'A';
                        s2 = (s1 - L'A' + 1) % 26 + L'A';;
                        s[k++] = s1;
                        s[k++] = s2;
                    }
                    else {
                        s1 = (symbol - L'А' + 1) % 32 + L'А';
                        s2 = (s1 - L'А' + 1) % 32 + L'А';
                        s[k++] = s1;
                        s[k++] = s2;
                    }
                }
                else {
                    if ((symbol >= L'a') && (symbol <= L'z')) {
                        s1 = (symbol - L'a' + 1) % 26 + L'a';
                        s2 = (s1 - L'a' + 1) % 26 + L'a';
                        s[k++] = s1;
                        s[k++] = s2;
                    }
                    else {
                        s1 = (symbol - L'а' + 1) % 32 + L'а';
                        s2 = (s1 - L'а' + 1) % 32 + L'а';
                        s[k++] = s1;
                        s[k++] = s2;
                    }
                }
            }
            else {
                s[k++] = symbol;
            }
        }
        free(t->text[i]->sentence);
        t->text[i]->sentence = s;
        t->text[i]->size = new_size;
        t->text[i]->capacity = new_size;
    }
}