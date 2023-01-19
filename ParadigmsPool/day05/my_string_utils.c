/*
** EPITECH PROJECT, 2023
** day05
** File description:
** $DESCRIPTION
*/

#include <stdlib.h>
#include <string.h>
#include "string.h"

void append_c(string_t *this, const char *ap)
{
    size_t length = 0;

    if (this == NULL || ap == NULL)
        return;
    if (this->str == NULL) {
        this->str = strdup(ap);
    } else {
        length = strlen(this->str) + strlen(ap) + 1;
        this->str = realloc(this->str, sizeof(char) * length);
        strcat(this->str, ap);
    }
}

void append_s(string_t *this, const string_t *ap)
{
    if (this == NULL || ap == NULL)
        return;
    this->append_c(this, ap->str);
}

char index_of(const string_t *this, size_t pos)
{
    if (this == NULL || this->str == NULL || pos >= strlen(this->str))
        return (-1);
    return this->str[pos];
}

void clear_str(string_t *this)
{
    if (this == NULL)
        return;
    free(this->str);
    this->str = strdup("");
}

int length_str(const string_t *this)
{
    if (this == NULL || this->str == NULL)
        return (-1);
    return strlen(this->str);
}
