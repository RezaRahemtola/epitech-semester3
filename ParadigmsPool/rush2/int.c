/*
** EPITECH PROJECT, 2023
** Paradigms Seminar
** File description:
** Exercice 04
*/

#include <stdlib.h>
#include <stdio.h>
#include "int.h"
#include "new.h"
#include "raise.h"

typedef struct {
    Class base;
    int value;
} IntClass;

static void int_ctor(IntClass *this, va_list *args)
{
    this->value = va_arg(*args, int);
}

static void int_dtor(__attribute__((unused)) IntClass *this)
{
    return;
}

static char *int_print(IntClass *this)
{
    const char *format = "<Int (%d)>";
    size_t length = snprintf(NULL, 0, format, this->value) + 1;
    char *result = calloc(length, sizeof(char));

    if (!result)
        raise("Int print calloc failed");
    sprintf(result, format, this->value);
    return result;
}

static Object *int_add(const IntClass *this, const IntClass *other)
{
    return new(Int, this->value + other->value);
}

static Object *int_sub(const IntClass *this, const IntClass *other)
{
    return new(Int, this->value - other->value);
}

static Object *int_mul(const IntClass *this, const IntClass *other)
{
    return new(Int, this->value * other->value);
}

static Object *int_div(const IntClass *this, const IntClass *other)
{
    if (other->value == 0)
        raise("Cannot divide by 0");
    return new(Int, this->value / other->value);
}

static bool int_eq(const IntClass *this, const IntClass *other)
{
    return (this->value == other->value);
}

static bool int_gt(const IntClass *this, const IntClass *other)
{
    return (this->value > other->value);
}

static bool int_lt(const IntClass *this, const IntClass *other)
{
    return (this->value < other->value);
}

static const IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t) &int_ctor,
        .__dtor__ = (dtor_t) &int_dtor,
        .__str__ = (to_string_t) &int_print,
        .__add__ = (binary_operator_t) &int_add,
        .__sub__ = (binary_operator_t) &int_sub,
        .__mul__ = (binary_operator_t) &int_mul,
        .__div__ = (binary_operator_t) &int_div,
        .__eq__ = (binary_comparator_t) &int_eq,
        .__gt__ = (binary_comparator_t) &int_gt,
        .__lt__ = (binary_comparator_t) &int_lt,
    },
    .value = 0
};

const Class *Int = (const Class *) &_description;
