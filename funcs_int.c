#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int check_input_int(void *arg) {
    int *argument = (int*) arg;
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
        if (flag == 1 || input < 0) {
            printf("Некорректный ввод, попробуйте еще раз ");
            input = scanf("%d", argument);
            checker = getchar();
            flag = 0;
        }
        else {
            flag = 1;
        }
    }
    return 0;
}

int check_input_int_2(void *arg) {
    int *argument = (int*) arg;
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
        if (flag == 1 || input < 1 || input > 2) {
            printf("Некорректный ввод, попробуйте еще раз ");
            input = scanf("%d", argument);
            checker = getchar();
            flag = 0;
        }
        else {
            flag = 1;
        }
    }
    return 0;
}

int check_input_int_i_and_j(void *arg, int len) {
    int *argument = (int*) arg;
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
        if (flag == 1 || input > len - 1) {
            printf("Некорректный ввод, попробуйте еще раз ");
            input = scanf("%d", argument);
            checker = getchar();
            flag = 0;
        }
        else {
            flag = 1;
        }
    }
    return 0;
}