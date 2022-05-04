#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include <string.h>
// #include "structs.h"
// #include "text_and_sentences.h"
// #include "anagrammsFunc.h"
// #include "sortingFunc.h"
// #include "vowelFunc.h"
// #include "changingWords.h"


// //-------------------------------------------------------------------------------------------------
// //Структуры и функции связанные с предложениями


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


//-------------------------------------------------------------------------------------------------
//Структура и функции связанные с Текстом

typedef struct Text {
    size_t size;
    size_t capacity;
    Sentence** text;
} Text;


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


//-------------------------------------------------------------------------------------------------
//Первая функция: Анаграмма

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


//-------------------------------------------------------------------------------------------------
//Третья функция: замена гласных букв на 2 следующие по алфавиту

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


//-------------------------------------------------------------------------------------------------


int main() {
    setlocale(LC_ALL, "");

    wprintf(L"Enter ur text: \n");
    Text* t = getFullSentencesText();
    printText(t);

    wchar_t old[100];
    wchar_t new[100];

    int choice;
    wprintf(L"Выберите функцию:\n");
    wprintf(L"1) Вывести все предложения, которые являются анаграммами друг для друга;\n");
    wprintf(L"2) Получить отсортированные предложения по кол-ву заглавных букв;\n");
    wprintf(L"3) Получить текст, в котором каждая гласная буква будет заменена на следующие две по алфавиту;\n");
    wprintf(L"4) Заменить все вхождения одного слова на другое (введенное вами);\n");
    wprintf(L"5) Выход из программы;\n");
    wprintf(L"Ваш выбор:\n");

    wscanf(L"%d", &choice);
    //system("clear");

    switch (choice)
    {
    case 1:
        printAnagramms(t);
        break;
    case 2:
        sort(t);
        printText(t);
        break;
    case 3:
        changeTwoNextSymbol(t);
        printText(t);
        break;
    case 4:

        wprintf(L"Введите слово, которое хотите заменить: ");
        wscanf(L"%ls", old);
        wprintf(L"Введите слово, на которое хотите заменить: ");
        wscanf(L"%ls", new);

        changeWord(t, old, new);
        printText(t);
        break;
    case 5:
        wprintf(L"Удачи!\n");
        break;
    default:
        wprintf(L"Введено неправильное число! Выход из программы!\n");
    }

    //wprintf(L"lalalal");

    deleteText(&t);

    return 0;
}
