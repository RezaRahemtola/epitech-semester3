/*
** EPITECH PROJECT, 2023
** day05
** File description:
** $DESCRIPTION
*/

#include <stdlib.h>
#include <string.h>
#include "string.h"

static size_t count_splits(const char *str, char sep)
{
    size_t count = 1;

    for (size_t i = 0; str[i] != '\0'; i++) {
        if (str[i] == sep)
            count++;
    }
    return (count);
}

static char **split_helper(char *str, char separator, size_t nb_elems)
{
    char **res = calloc(nb_elems + 1, sizeof(char *));
    char *save_ptr = NULL;
    char *token = NULL;

    if (strcmp(str, "") == 0) {
        res[0] = strdup(str);
        free(str);
        return (res);
    }
    token = strtok_r(str, (char [2]){separator, '\0'}, &save_ptr);
    for (size_t i = 0; i < nb_elems; i++) {
        res[i] = strdup(token);
        if (save_ptr != NULL && save_ptr[0] == separator) {
            res[++i] = strdup("");
            save_ptr++;
        }
        token = strtok_r(NULL, (char [2]){separator, '\0'}, &save_ptr);
    }
    free(str);
    return (res);
}

char **split_c(const string_t *this, char separator)
{
    size_t nb_elems = 0;

    if (this == NULL || this->str == NULL)
        return (NULL);
    nb_elems = count_splits(this->str, separator);
    return (split_helper(strdup(this->str), separator, nb_elems));
}

static size_t my_arraylen(char **array)
{
    size_t i = 0;

    if (array == NULL)
        return (0);
    while (array[i] != NULL)
        i++;
    return (i);
}

string_t **split_s(const string_t *this, char separator)
{
    char **res = split_c(this, separator);
    string_t **res_str = NULL;
    size_t nb_elems = 0;

    if (res == NULL)
        return (NULL);
    nb_elems = my_arraylen(res);
    res_str = calloc(nb_elems + 1, sizeof(string_t *));
    for (size_t i = 0; i < nb_elems; i++) {
        res_str[i] = malloc(sizeof(string_t));
        string_init(res_str[i], res[i]);
    }
    for (size_t i = 0; i < nb_elems; i++)
        free(res[i]);
    free(res);
    return res_str;
}
