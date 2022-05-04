#ifndef _TEXT_N_SENTENCE_
#define _TEXT_N_SENTENCE_
Sentence* createSentence();
void deleteSentence(Sentence** ps);
Text* createText();
void deleteText(Text** ptext);
wchar_t* addOneSymbol(Sentence* ps, wchar_t symbol);
Sentence* readOneSentence(int* weof);
Sentence* addOneSentence(Text* ptext, Sentence* s);
void printText(Text* t);
wint_t myWCmp(const wchar_t* a, const wchar_t* b);
Text* getFullSentencesText();
#endif // _TEXT_N_SENTENCE_
