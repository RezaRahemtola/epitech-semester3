/*
** EPITECH PROJECT, 2023
** Day04am
** File description:
** Exercise 04
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "print.h"

void print_normal(const char *str)
{
    if (str == NULL)
        return;
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    if (str == NULL)
        return;
    for (ssize_t i = strlen(str) - 1; i >= 0; i--)
        putchar(str[i]);
    putchar('\n');
}

void print_upper(const char *str)
{
    if (str == NULL)
        return;
    for (size_t i = 0; i < strlen(str); i++)
        putchar(toupper(str[i]));
    putchar('\n');
}

void print_42(const char *str)
{
    (void) str;
    print_normal("42");
}

void do_action(action_t action, const char *str)
{
    void (*func_ptr[PRINT_COUNT])(const char *str) = {
        print_normal,
        print_reverse,
        print_upper,
        print_42
    };

    if (action >= PRINT_COUNT) {
        return;
    }
    (*func_ptr[action])(str);
}
