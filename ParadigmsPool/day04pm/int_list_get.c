/*
** EPITECH PROJECT, 2023
** day04pm
** File description:
** $DESCRIPTION
*/

#include <stddef.h>
#include "int_list.h"

unsigned int int_list_get_size(int_list_t list)
{
    unsigned int counter = 0;

    while (list != NULL) {
        counter++;
        list = list->next;
    }
    return (counter);
}

int int_list_get_elem_at_front(int_list_t list)
{
    if (list == NULL)
        return (0);
    return list->value;
}

int int_list_get_elem_at_back(int_list_t list)
{
    if (list == NULL)
        return (0);
    while (list->next != NULL)
        list = list->next;
    return list->value;
}

int int_list_get_elem_at_position(int_list_t list, unsigned int position)
{
    unsigned int count = 0;

    if (position == 0 || list == NULL) {
        return int_list_get_elem_at_front(list);
    }
    while (list != NULL && position != count) {
        count++;
        list = list->next;
    }
    if (list == NULL)
        return (0);
    return (list->value);
}
