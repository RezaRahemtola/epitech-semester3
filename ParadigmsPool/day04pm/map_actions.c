/*
** EPITECH PROJECT, 2023
** day04pm
** File description:
** $DESCRIPTION
*/

#include <stddef.h>
#include <stdlib.h>
#include "map.h"

static pair_t *create_pair(void *key, void *value)
{
    pair_t *pair = malloc(sizeof(pair_t));

    if (pair == NULL)
        return (NULL);
    pair->key = key;
    pair->value = value;
    return (pair);
}

bool map_add_elem(map_t *map_ptr, void *key, void *value,
key_comparator_t key_cmp)
{
    map_t tmp = NULL;
    pair_t *tmp_pair = NULL;
    pair_t *pair = create_pair(key, value);

    if (key == NULL || value == NULL)
        return (false);
    if (map_ptr == NULL || *map_ptr == NULL)
        return (list_add_elem_at_front(map_ptr, pair));
    tmp = *map_ptr;
    while (tmp != NULL) {
        tmp_pair = tmp->value;
        if (key_cmp(tmp_pair->key, key) == 0) {
            tmp_pair->value = value;
            free(pair);
            return (true);
        }
        tmp = tmp->next;
    }
    return (list_add_elem_at_back(map_ptr, pair));
}

void *map_get_elem(map_t map, void *key, key_comparator_t key_cmp)
{
    pair_t *pair = NULL;

    if (list_is_empty(map) || key == NULL)
        return (NULL);
    while (map != NULL) {
        pair = map->value;
        if (key_cmp(pair->key, key) == 0)
            return (pair->value);
        map = map->next;
    }
    return (NULL);
}

bool map_del_elem(map_t *map_ptr, void *key, key_comparator_t key_cmp)
{
    map_t tmp = NULL;
    pair_t *pair = NULL;
    unsigned int idx = 0;

    tmp = *map_ptr;
    for (unsigned int i = 0; tmp != NULL; i++) {
        pair = tmp->value;
        if (key_cmp(pair->key, key) == 0) {
            free(pair);
            return (list_del_elem_at_position(map_ptr, idx));
        }
        tmp = tmp->next;
    }
    return (false);
}
