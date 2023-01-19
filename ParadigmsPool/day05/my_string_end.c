/*
** EPITECH PROJECT, 2023
** day05
** File description:
** $DESCRIPTION
*/

#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include "string.h"

void print_str(const string_t *this)
{
    if (this == NULL || this->str == NULL)
        return;
    write(1, this->str, strlen(this->str));
}
