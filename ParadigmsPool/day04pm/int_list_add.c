/*
** EPITECH PROJECT, 2023
** day04pm
** File description:
** $DESCRIPTION
*/

#include <stddef.h>
#include <stdlib.h>
#include "int_list.h"

bool int_list_add_elem_at_front(int_list_t *front_ptr, int elem)
{
    int_list_t node = malloc(sizeof(int_node_t));

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

bool int_list_add_elem_at_back(int_list_t *front_ptr, int elem)
{
    int_list_t node = malloc(sizeof(int_node_t));
    int_list_t tmp = NULL;

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
    tmp = *front_ptr;
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

bool int_list_add_elem_at_position(int_list_t *front_ptr, int elem,
unsigned int position)
{
    int_list_t node = malloc(sizeof(int_node_t));
    int_list_t tmp = *front_ptr;
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
