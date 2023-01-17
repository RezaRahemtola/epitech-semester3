/*
** EPITECH PROJECT, 2023
** day04pm
** File description:
** $DESCRIPTION
*/

#include <stddef.h>
#include <stdlib.h>
#include "map.h"

unsigned int map_get_size(map_t map)
{
    return list_get_size(map);
}

bool map_is_empty(map_t map)
{
    return list_is_empty(map);
}

static void free_map_node(map_t node)
{
    free(node->value);
    free(node);
}

void map_clear(map_t *map_ptr)
{
    map_t tmp = NULL;

    if (map_ptr == NULL || *map_ptr == NULL)
        return;
    while (*map_ptr != NULL) {
        tmp = (*map_ptr)->next;
        free_map_node(*map_ptr);
        *map_ptr = tmp;
    }
}
