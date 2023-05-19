#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "funcs_str.h"
#include "funcs_int.h"

int AutoTest() {
    char str1[] = "Artem Chernov", str2[] = "Eating meat";
    char substring1[] = "mte", substring2[] = "eati";
    int i = 2, j = 6;
    char Expected_Result1[] = "tem C";
    char Expected_concatenate1[] = "Artem ChernovEating meat";

    char result1[100];
    strcpy(result1, strFunctions.concatenateStrings(str1, str2));
    printf("Result concatenateStrings: %s\n", result1);
    if (strcmp(result1, Expected_concatenate1) != 0) {
        printf("Wrong result concatenateStrings.\n");
        return 0;
    }

    char result2[100];
    strcpy(result2, strFunctions.getSubstring(str1, i, j));
    printf("Result getSubstring: %s\n", result2);
    if (strcmp(result2, Expected_Result1) != 0) {
        printf("Wrong result getSubstring.\n");
        return 0;
    }

    const char *result3 = strFunctions.findSubstringCaseSensitive(str2, substring2);
    printf("Result findSubstringCaseSensitive: %s\n", result3);
    if (result3 != NULL) {
        return 0;
    }

    const char *result4 = strFunctions.findSubstringCaseInsensitive(str2, substring2);
    printf("Result findSubstringCaseInsensitive: %s\n", result4);
    if (result4 == NULL) {
        printf("Wrong result findSubstringCaseInsensitive.\n");
        return 0;
    }

    const char *result5 = strFunctions.findSubstringCaseInsensitive(str1, substring1);
    printf("Result findSubstringCaseInsensitive: %s\n", result5);
    if (result5 != NULL) {
        printf("Wrong result findSubstringCaseInsensitive.\n");
        return 0;
    }

    return 1;
}

void menu() {
    int check, choice = 0;
    while (1) {
        printf("MENU\n1.Input\n2.AutoTest\n3.Finish\n");
        check = check_input_int(&choice);
        if (check != 0) {
            printf("Input error.");
            exit(0);
        }
        switch(choice) {

            case (1): {
                int len1 = 0, len2 = 0;
                void *str1;
                void *str2;
                printf("Input length of the first string.\n");
                check = check_input_int(&len1);
                if (check != 0) {
                    printf("Input error.");
                    exit(0);
                }
                printf("Input first string.");
                str1 = readString(len1);

                printf("Input length of the second string.\n");
                check = check_input_int(&len2);
                if (check != 0) {
                    printf("Input error.");
                    exit(0);
                }
                printf("Input second string.");
                str2 = strFunctions.readString(len2);
                strFunctions.print(str1);
                strFunctions.print(str2);

                while (1) {
                    void* result;
                    printf("MENU\n1.Concatenate strings\n2.Get substring\n3.Find substring\n4.Finish\n");
                    int choice2 = 0;
                    check = check_input_int(&choice2);
                    if (check != 0) {
                        printf("Input error.");
                        exit(0);
                    }
                    switch (choice2) {

                        case (1): {
                            int choice3 = 0;
                            printf("MENU\n1.First + second\n2.Second + first\n");
                            check = check_input_int_2(&choice3);
                            if (check != 0) {
                                printf("Input error.");
                                exit(0);
                            }
                            if (choice3 == 1) {
                                result = strFunctions.concatenateStrings(str1, str2);
                            }
                            else {
                                result = strFunctions.concatenateStrings(str2, str1);
                            }
                            print(result);
                            free(result);
                            break;
                        }

                        case (2): {
                            printf("MENU\n1.First\n2.Second\n");
                            int choice4 = 0;
                            check = check_input_int_2(&choice4);
                            if (check != 0) {
                                printf("Input error.");
                                exit(0);
                            }
                            printf("MENU\nwrite i and j\n");
                            if (choice4 == 1){
                                int i = 0, j = 0;
                                check = check_input_int_i_and_j(&i,len1);
                                if (check != 0) {
                                    printf("Input error.");
                                    exit(0);
                                }
                                check = check_input_int_i_and_j(&j,len1);
                                if (check != 0) {
                                    printf("Input error.");
                                    exit(0);
                                }
                                result = strFunctions.getSubstring(str1,i,j);
                            }
                            else {
                                int i = 0, j = 0;
                                check = check_input_int_i_and_j(&i,len1);
                                if (check != 0) {
                                    printf("Input error.");
                                    exit(0);
                                }
                                check = check_input_int_i_and_j(&j,len1);
                                if (check != 0) {
                                    printf("Input error.");
                                    exit(0);
                                }
                                result = strFunctions.getSubstring(str2,i,j);
                            }
                            print(result);
                            free(result);
                            break;
                        }

                        case(3): {
                            printf("MENU\n1.Sensitive\n2.Insensitive\n");
                            int choiceGetSubstring = 0, choiceWhichOne = 0;
                            check= check_input_int_2(&choiceGetSubstring);
                            if (check != 0) {
                                printf("Input error");
                                exit(0);
                            }
                            printf("MENU\n1.First\n2.Second\n");
                            check = check_input_int_2(&choiceWhichOne);
                            if (check != 0) {
                                printf("Input error");
                                exit(0);
                            }
                            void* Substring;
                            int lenSubstring = 0;
                            printf("Write len of substring:");
                            check = check_input_int(&lenSubstring);
                            if(check != 0) {
                                printf("Error input.");
                                exit(0);
                            }
                            Substring = strFunctions.readString(lenSubstring);
                            if (choiceGetSubstring == 1 && choiceWhichOne == 1) {
                                result = strFunctions.findSubstringCaseSensitive(str1, Substring);
                            } else if (choiceGetSubstring == 2 && choiceWhichOne == 1) {
                                result = strFunctions.findSubstringCaseInsensitive(str1, Substring);
                            } else if (choiceGetSubstring == 1 && choiceWhichOne == 2) {
                                result = strFunctions.findSubstringCaseSensitive(str2, Substring);
                            } else if (choiceGetSubstring == 2 && choiceWhichOne == 2) {
                                result = strFunctions.findSubstringCaseInsensitive(str2, Substring);
                            }
                            if (result != NULL) {
                                printf("Yes, subsrting is exist\n");
                            }
                            else {
                                printf("No, substring is not exist\n");
                            }
                            break;
                        }

                        case (4): {
                            free(str1);
                            free(str2);
                            exit(0);
                        }
                        default: {
                            printf("Incorrect incert, try again.");
                            break;
                        }
                    }
                }

            }

            case (2): {
                if (AutoTest() == 1) {
                    printf("Success!!");
                }else {
                    printf("Error");
                }
                exit(0);
            }
            case(3): {
                exit(0);
            }
        }
    }
}
