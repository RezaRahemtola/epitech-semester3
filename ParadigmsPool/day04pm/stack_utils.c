/*
** EPITECH PROJECT, 2023
** day04pm
** File description:
** $DESCRIPTION
*/

#include "stack.h"

unsigned int stack_get_size(stack_t stack)
{
    return list_get_size(stack);
}

bool stack_is_empty(stack_t stack)
{
    return list_is_empty(stack);
}
