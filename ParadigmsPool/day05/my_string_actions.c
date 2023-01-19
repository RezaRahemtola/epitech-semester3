/*
** EPITECH PROJECT, 2023
** day05
** File description:
** $DESCRIPTION
*/

#include <string.h>
#include "string.h"

int compare_c(const string_t *this, const char *str)
{
    if (this == NULL || str == NULL || this->str == NULL)
        return (0);
    return strcmp(this->str, str);
}

int compare_s(const string_t *this, const string_t *str)
{
    if (str == NULL)
        return (0);
    return compare_c(this, str->str);
}

size_t copy_string(const string_t *this, char *s, size_t n, size_t pos)
{
    char ch = '\0';

    if (this == NULL || this->str == NULL || pos > strlen(this->str) + 1)
        return (0);
    for (size_t i = 0; i < n; i++) {
        ch = *(this->str + pos + i);
        s[i] = ch;
        if (ch == '\0')
            return (i + 1);
    }
    return (n);
}

const char *c_str(const string_t *this)
{
    if (this == NULL)
        return (NULL);
    return this->str;
}

int empty_string(const string_t *this)
{
    if (this == NULL)
        return (1);
    return (this->length(this) <= 0 ? 1 : 0);
}
