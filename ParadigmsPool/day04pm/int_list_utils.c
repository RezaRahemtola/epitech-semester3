/*
** EPITECH PROJECT, 2023
** day04pm
** File description:
** $DESCRIPTION
*/

#include <stddef.h>
#include <stdio.h>
#include "int_list.h"

bool int_list_is_empty(int_list_t list)
{
    return list == NULL;
}

void int_list_dump(int_list_t list)
{
    while (list != NULL) {
        printf("%d\n", list->value);
        list = list->next;
    }
}
