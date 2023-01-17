/*
** EPITECH PROJECT, 2023
** day04pm
** File description:
** $DESCRIPTION
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    list_t node = malloc(sizeof(node_t));

    if (node == NULL)
        return (false);
    if (front_ptr == NULL) {
        free(node);
        return (false);
    }
    node->value = elem;
    node->next = *front_ptr;
    *front_ptr = node;
    return (true);
}

bool list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    list_t node = malloc(sizeof(node_t));
    list_t tmp = *front_ptr;

    if (node == NULL)
        return (false);
    if (front_ptr == NULL) {
        free(node);
        return (false);
    }
    node->value = elem;
    node->next = NULL;
    if (*front_ptr == NULL) {
        *front_ptr = node;
        return (true);
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = node;
    return (true);
}

static bool free_false(void *item)
{
    free(item);
    return (true);
}

bool list_add_elem_at_position(list_t *front_ptr, void *elem,
unsigned int position)
{
    list_t node = malloc(sizeof(node_t));
    list_t tmp = *front_ptr;
    unsigned int curr = 1;

    if (node == NULL)
        return (false);
    node->value = elem;
    if (position == 0) {
        node->next = *front_ptr;
        *front_ptr = node;
        return (true);
    }
    for (; tmp->next != NULL && position != curr; curr++)
        tmp = tmp->next;
    if (position == curr) {
        node->next = tmp->next;
        tmp->next = node;
        return (true);
    }
    return free_false(node);
}
