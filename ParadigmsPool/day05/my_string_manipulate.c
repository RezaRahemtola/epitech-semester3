/*
** EPITECH PROJECT, 2023
** day05
** File description:
** $DESCRIPTION
*/

#include <stdlib.h>
#include <string.h>
#include "string.h"

int find_c(const string_t *this, const char *str, size_t pos)
{
    char *found = NULL;

    if (this == NULL || this->str == NULL || str == NULL)
        return (-1);
    if (pos >= strlen(this->str))
        return (-1);
    found = strstr(this->str + pos, str);
    if (found == NULL)
        return (-1);
    return (strlen(this->str) - strlen(found));
}

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    if (str == NULL)
        return (-1);
    return find_c(this, str->str, pos);
}

void insert_c(string_t *this, size_t pos, const char *str)
{
    char *ts = NULL;

    if (this == NULL || str == NULL)
        return;
    if (this->str == NULL) {
        this->assign_c(this, str);
    } else {
        ts = strdup(this->str);
        pos = (pos > strlen(ts) ? strlen(ts) : pos);
        free(this->str);
        this->str = calloc(strlen(ts) + strlen(str) + 1, sizeof(char));
        this->str = strcat(strcat(strncat(this->str, ts, pos), str), ts + pos);
        free(ts);
    }
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    if (str == NULL)
        return;
    insert_c(this, pos, str->str);
}

int to_int(const string_t *this)
{
    if (this == NULL)
        return (0);
    return atoi(this->str);
}
