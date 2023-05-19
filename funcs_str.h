#ifndef LAB1_2_7_FUNCS_STR_H
#define LAB1_2_7_FUNCS_STR_H

void *readString(int);

void *concatenateStrings(void *, void *);

void *getSubstring(void *, int, int);

void *findSubstringCaseSensitive(void *, void *);

void *findSubstringCaseInsensitive(const char *, const char *);

void print(void *);

struct StringFunctions {
    void *(*readString)(int);
    void *(*concatenateStrings)(void *, void *);
    void *(*getSubstring)(void *, int, int);
    void *(*findSubstringCaseSensitive)(void *, void *);
    void *(*findSubstringCaseInsensitive)(const char *, const char *);
    void (*print)(void *);
};

extern const struct StringFunctions strFunctions;

#endif //LAB1_2_7_FUNCS_STR_H
