/*
** EPITECH PROJECT, 2023
** day04pm
** File description:
** $DESCRIPTION
*/

#include <stddef.h>
#include "list.h"

unsigned int list_get_size(list_t list)
{
    unsigned int counter = 0;

    while (list != NULL) {
        counter++;
        list = list->next;
    }
    return (counter);
}

void *list_get_elem_at_front(list_t list)
{
    if (list == NULL)
        return (NULL);
    return list->value;
}

void *list_get_elem_at_back(list_t list)
{
    if (list == NULL)
        return (NULL);
    while (list->next != NULL)
        list = list->next;
    return list->value;
}

void *list_get_elem_at_position(list_t list, unsigned int position)
{
    unsigned int count = 0;

    if (position == 0 || list == NULL) {
        return list_get_elem_at_front(list);
    }
    while (list != NULL && position != count) {
        count++;
        list = list->next;
    }
    if (list == NULL)
        return (0);
    return (list->value);
}
