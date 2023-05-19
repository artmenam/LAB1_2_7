#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int check_input_int(void *arg) {
    int *argument = (int *) arg;
    int checker = 0, flag = 0, input = scanf("%d", argument);
    checker = getchar();
    if (input == -1) {
        return -1;
    }
    while (input != 1 || flag == 0) {
        while (checker != '\n') {
            checker = getchar();
            flag = 1;
        }
        if (flag == 1 || argument < 0) {
            printf("Incorrect input, try again ");
            input = scanf("%d", argument);
            checker = getchar();
            flag = 0;
        } else {
            flag = 1;
        }
    }
    return 0;
}

int check_input_int_2(void *arg) {
    int *argument = (int *) arg;
    int checker = 0, flag = 0, input = scanf("%d", argument);
    checker = getchar();
    if (input == -1) {
        return -1;
    }
    while (input != 1 || flag == 0) {
        while (checker != '\n') {
            checker = getchar();
            flag = 1;
        }
        if (flag == 1 || *argument < 1 || *argument > 2) {
            printf("Incorrect input, try again ");
            input = scanf("%d", argument);
            checker = getchar();
            flag = 0;
        } else {
            flag = 1;
        }
    }
    return 0;
}

int check_input_int_i_and_j(void *arg, int len) {
    int *argument = (int *) arg;
    int checker = 0, flag = 0, input = scanf("%d", argument);
    checker = getchar();
    if (input == -1) {
        return -1;
    }
    while (input != 1 || flag == 0) {
        while (checker != '\n') {
            checker = getchar();
            flag = 1;
        }
        if (flag == 1 || *argument > len - 1) {
            printf("Incorrect input, try again ");
            input = scanf("%d", argument);
            checker = getchar();
            flag = 0;
        } else {
            flag = 1;
        }
    }
    return 0;
}