/*
** EPITECH PROJECT, 2023
** day04pm
** File description:
** $DESCRIPTION
*/

#include "queue.h"

bool queue_push(queue_t *queue_ptr, void *elem)
{
    return list_add_elem_at_back(queue_ptr, elem);
}

bool queue_pop(queue_t *queue_ptr)
{
    return list_del_elem_at_front(queue_ptr);
}

void queue_clear(queue_t *queue_ptr)
{
    return list_clear(queue_ptr);
}

void *queue_front(queue_t queue)
{
    return list_get_elem_at_front(queue);
}
