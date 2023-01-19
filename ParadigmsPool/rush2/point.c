/*
** EPITECH PROJECT, 2023
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdlib.h>
#include <stdio.h>
#include "point.h"
#include "raise.h"
#include "new.h"

typedef struct {
    Class base;
    int x;
    int y;
} PointClass;

static void point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void point_dtor(__attribute__((unused)) PointClass *this)
{
    return;
}

static char *point_print(PointClass *this)
{
    size_t length = snprintf(NULL, 0, "<Point (%d, %d)>", this->x, this->y) + 1;
    char *result = calloc(length, sizeof(char));

    if (result == NULL)
        raise("Point print calloc failed");
    sprintf(result, "<Point (%d, %d)>", this->x, this->y);
    return (result);
}

static Object *point_add(const PointClass *this, const PointClass *other)
{
    return new(Point, this->x + other->x, this->y + other->y);
}

static Object *point_sub(const PointClass *this, const PointClass *other)
{
    return new(Point, this->x - other->x, this->y - other->y);
}

static const PointClass _description = {
    {
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t) &point_ctor,
        .__dtor__ = (dtor_t) &point_dtor,
        .__str__ = (to_string_t) &point_print,
        .__add__ = (binary_operator_t) &point_add,
        .__sub__ = (binary_operator_t) &point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Point = (const Class *) &_description;
