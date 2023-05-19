#include <stdio.h>
#include <string.h>
#include "stdlib.h"
#include <ctype.h>
#include "funcs_str.h"


void *readString(int len) {
    char *buffer = (char *) malloc((len + 1) * sizeof(char));  // Буфер для хранения строки
    while (len + 1 != strlen(buffer)) {
        printf("Enter the string: ");
        fgets(buffer, sizeof(buffer), stdin);
        if (len + 1 != strlen(buffer)) {
            printf("%s\n", buffer);
            printf("Error input. Try again.\n");
        }
    }
    char *str = (char *) malloc((len + 1) * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation error.\n");
        return NULL;
    }


    for (size_t i = 0; i < len; i++) {
        str[i] = buffer[i];
    }
    str[len] = '\0';

    return str;
}

void *concatenateStrings(void *str1, void *str2) {
    char *s1 = (char *) str1;
    char *s2 = (char *) str2;
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    char *result = malloc(len1 + len2 + 1);

    if (result == NULL) {
        printf("Error: Failed to allocate memory.\n");
        return NULL;
    }

    strcpy(result, s1);
    strcat(result, s2);

    return result;
}

void *getSubstring(void *str, int start, int end) {
    char *s = (char *) str;
    size_t len = strlen(s);

    if (start < 0 || start >= len || end < start || end >= len) {
        printf("Error: Incorrect parameters for getting substring.\n");
        return NULL;
    }

    size_t sub_len = end - start + 1;
    char *substring = malloc(sub_len + 1);

    if (substring == NULL) {
        printf("Error: Failed to allocate memory.\n");
        return NULL;
    }

    strncpy(substring, s + start, sub_len);
    substring[sub_len] = '\0';


    return substring;
}

void *findSubstringCaseSensitive(void *str, void *substr) {
    char *substring1 = (char *) substr;
    char *string = (char *) str;
    return strstr(string, substring1);
}

void *findSubstringCaseInsensitive(const char *str, const char *substr) {
    int strLength = strlen(str);
    int substrLength = strlen(substr);

    for (int i = 0; i <= strLength - substrLength; i++) {
        int j;

        for (j = 0; j < substrLength; j++) {
            if (tolower(str[i + j]) != tolower(substr[j])) {
                break;
            }
        }

        if (j == substrLength) {
            return &str[i];
        }
    }

    return NULL;
}

void print(void *str) {
    char *s = (char *) str;
    printf("string:'%s'\n", s);
}

const struct StringFunctions strFunctions = {
        .readString = readString,
        .concatenateStrings = concatenateStrings,
        .getSubstring = getSubstring,
        .findSubstringCaseSensitive = findSubstringCaseSensitive,
        .findSubstringCaseInsensitive = findSubstringCaseInsensitive,
        .print = print
};
