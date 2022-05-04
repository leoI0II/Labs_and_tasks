#ifndef _ANAGRAMMS_
#define _ANAGRAMMS_
int isEnglishLetter(wchar_t symbol);
int isRussianLetter(wchar_t symbol);
int isNumberLetter(wchar_t symbol);
int isOkSymbolForAnagramm(wchar_t symbol);
void setAlphabet(Sentence* s, size_t* english, size_t* russian, size_t* numbers);
int isAnagramm(size_t* english1, size_t* russian1, size_t* numbers1, size_t* english2, size_t* russian2, size_t* numbers2);
void printAnagramms(Text* t);
#endif // _ANAGRAMMS_
