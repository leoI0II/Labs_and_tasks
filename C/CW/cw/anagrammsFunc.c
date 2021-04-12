#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include <string.h>
#include "structs.h"


int isEnglishLetter(wchar_t symbol) {                                                       //Проверка: является ли символ буквой из латинского алфавита
    return (symbol >= L'a') && (symbol <= L'z');
}

int isRussianLetter(wchar_t symbol) {                                                       //Проверка: является ли символ буквой кириллического алфавита
    return (symbol >= L'а') && (symbol <= L'я');
}

int isNumberLetter(wchar_t symbol) {                                                        //Проверка: является ли символ цифрой
    return (symbol >= L'0') && (symbol <= L'9');
}

int isOkSymbolForAnagramm(wchar_t symbol) {                                                 //Проверка символа на латиницу/кириллицу/цифру
    return isEnglishLetter(symbol) || isRussianLetter(symbol) || isNumberLetter(symbol);
}

void setAlphabet(Sentence* s, size_t* english, size_t* russian, size_t* numbers) {          //Функция считает сколько букв каждого алфавита каждого языка или цифр
    for (size_t i = 0; i < 26; ++i) {
        english[i] = 0;
    }
    for (size_t i = 0; i < 33; ++i) {
        russian[i] = 0;
    }
    for (size_t i = 0; i < 10; ++i) {
        numbers[i] = 0;
    }
    wchar_t* p = s->sentence;
    while (*p != L'\0') {
        wchar_t symbol = towlower(*p);
        if (isOkSymbolForAnagramm(symbol)) {
            if (isEnglishLetter(symbol)) {              //В массиве счетчик букв каждого алфавита по порядку
                ++english[symbol - L'a'];
            }
            else if (isRussianLetter(symbol)) {
                ++russian[symbol - L'а'];
            }
            else {
                ++numbers[symbol - L'0'];
            }
        }
        ++p;
    }
}

int isAnagramm(size_t* english1, size_t* russian1, size_t* numbers1, size_t* english2, size_t* russian2, size_t* numbers2) {
    for (size_t i = 0; i < 26; ++i) {
        if (english1[i] != english2[i]) {                                           //Функция проверки массивов, содержащих флаги кол-ва букв каждого алфавита
            return 0;                                                               //на равность
        }
    }
    for (size_t i = 0; i < 33; ++i) {
        if (russian1[i] != russian2[i]) {
            return 0;
        }
    }
    for (size_t i = 0; i < 10; ++i) {
        if (numbers1[i] != numbers2[i]) {
            return 0;
        }
    }
    return 1;
}



void printAnagramms(Text* t) {                                                              //Функция, печатающая на экран предложения-анаграммы
    size_t english1[26];
    size_t russian1[33];
    size_t numbers1[10];

    size_t english2[26];
    size_t russian2[33];
    size_t numbers2[10];

    int* flags = (int*)malloc(sizeof(int) * t->size);
    for (size_t i = 0; i < t->size; ++i) {
        flags[i] = 1;
    }
    int counter1 = 0;
    for (size_t i = 0; i < t->size; flags[i] = 0, ++i) {
        int counter2 = 0;
        if (flags[i]) {
            setAlphabet(t->text[i], english1, russian1, numbers1);
            int first = 1;
            for (size_t j = i + 1; j < t->size; ++j) {
                if (flags[i]) {
                    setAlphabet(t->text[j], english2, russian2, numbers2);
                    if (isAnagramm(english1, russian1, numbers1, english2, russian2, numbers2)) {
                        if (first) {
                            wprintf(L"%ls\n", t->text[i]->sentence);
                            first = 0;
                            counter1++;
                        }
                        wprintf(L"%ls\n", t->text[j]->sentence);
                        flags[j] = 0;
                        counter1++;
                        counter2++;
                    }
                }
            }
            if (counter2){
                wprintf(L"\n");
            }
        }
    }
    if (!(counter1)) wprintf(L"No match!");
    wprintf(L"\n");
    free(flags);
}