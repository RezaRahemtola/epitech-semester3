/*
** EPITECH PROJECT, 2023
** day04pm
** File description:
** $DESCRIPTION
*/

#include <stddef.h>
#include "list.h"

bool list_is_empty(list_t list)
{
    return list == NULL;
}

void list_dump(list_t list, value_displayer_t val_disp)
{
    while (list != NULL) {
        val_disp(list->value);
        list = list->next;
    }
}
