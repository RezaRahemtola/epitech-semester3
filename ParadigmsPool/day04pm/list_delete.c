/*
** EPITECH PROJECT, 2023
** day04pm
** File description:
** $DESCRIPTION
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"

bool list_del_elem_at_front(list_t *front_ptr)
{
    list_t tmp = NULL;

    if (front_ptr == NULL || *front_ptr == NULL)
        return (false);
    tmp = (*front_ptr)->next;
    free(*front_ptr);
    *front_ptr = tmp;
    return (true);
}

bool list_del_elem_at_back(list_t *front_ptr)
{
    list_t tmp = NULL;

    if (front_ptr == NULL || *front_ptr == NULL)
        return (false);

    if ((*front_ptr)->next == NULL) {
        free(*front_ptr);
        *front_ptr = NULL;
        return (true);
    }
    tmp = *front_ptr;
    while (tmp->next->next != NULL)
        tmp = tmp->next;
    free(tmp->next);
    tmp->next = NULL;
    return (true);
}

bool list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
    list_t tmp = NULL;
    list_t after_delete = NULL;
    unsigned int curr = 1;

    if (front_ptr == NULL || *front_ptr == NULL)
        return (false);
    if (position == 0)
        return (list_del_elem_at_front(front_ptr));
    tmp = *front_ptr;
    for (; tmp->next != NULL && position != curr; curr++)
        tmp = tmp->next;
    if (position == curr) {
        after_delete = tmp->next->next;
        free(tmp->next);
        tmp->next = after_delete;
        return (true);
    }
    return (false);
}

void list_clear(list_t *front_ptr)
{
    list_t tmp = NULL;

    if (front_ptr == NULL || *front_ptr == NULL)
        return;
    while (*front_ptr != NULL) {
        tmp = (*front_ptr)->next;
        free(*front_ptr);
        *front_ptr = tmp;
    }
}
