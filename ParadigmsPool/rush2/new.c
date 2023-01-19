/*
** EPITECH PROJECT, 2022
** PDG-Rush2
** File description:
** Task 01
*/

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "object.h"

Object *new(const Class *class, ...)
{
    Object *obj = malloc(class->__size__);
    va_list list;

    va_start(list, class);
    if (obj == NULL)
        raise("Out of memory");
    memcpy(obj, class, class->__size__);
    if (class->__ctor__)
        class->__ctor__(obj, &list);
    va_end(list);
    return (obj);
}

Object *va_new(const Class *class, va_list *ap)
{
    Object *obj = malloc(class->__size__);

    if (obj == NULL)
        raise("Out of memory");
    memcpy(obj, class, class->__size__);
    if (class->__ctor__)
        class->__ctor__(obj, ap);
    return (obj);
}

void delete(Object *obj)
{
    Class *class = obj;

    if (class->__dtor__ != NULL)
        class->__dtor__(obj);
    free(obj);
}
