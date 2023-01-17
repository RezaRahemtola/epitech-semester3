/*
** EPITECH PROJECT, 2023
** day04pm
** File description:
** $DESCRIPTION
*/

#include "queue.h"

unsigned int queue_get_size(queue_t queue)
{
    return list_get_size(queue);
}

bool queue_is_empty(queue_t queue)
{
    return list_is_empty(queue);
}
