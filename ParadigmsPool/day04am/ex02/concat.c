/*
** EPITECH PROJECT, 2023
** Day04am
** File description:
** ex02
*/

#include <stdlib.h>
#include <string.h>
#include "concat.h"

void concat_strings(const char *str1, const char *str2, char **res)
{
    if (str1 == NULL || str2 == NULL || res == NULL)
        return;
    *res = calloc((strlen(str1) + strlen(str2) + 1), sizeof(char));
    strcat(*res, str1);
    strcat(*res, str2);
}

void concat_struct(concat_t *str)
{
    concat_strings(str->str1, str->str2, &(str->res));
}
