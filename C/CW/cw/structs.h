#ifndef _STRUCTURES_
#define _STRUCTURES_
struct Text {
    size_t size;
    size_t capacity;
    struct Sentence** text;
};

struct Sentence {
    size_t size;
    size_t capacity;
    wchar_t* sentence;
};

typedef struct Text Text;
typedef struct Sentence Sentence;
#endif // _STRUCTURES_
