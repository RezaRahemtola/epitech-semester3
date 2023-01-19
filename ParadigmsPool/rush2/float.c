/*
** EPITECH PROJECT, 2023
** Paradigms Seminar
** File description:
** Exercice 04
*/

#include <stdlib.h>
#include <stdio.h>
#include "new.h"
#include "float.h"
#include "raise.h"

typedef struct {
    Class base;
    float value;
} FloatClass;

static void float_ctor(FloatClass *this, va_list *args)
{
    this->value = va_arg(*args, double);
}

static void float_dtor(__attribute__((unused)) FloatClass *this)
{
    return;
}

static char *float_print(FloatClass *this)
{
    const char *format = "<Float (%f)>";
    size_t length = snprintf(NULL, 0, format, this->value) + 1;
    char *result = calloc(length, sizeof(char));

    if (!result)
        raise("Float print calloc failed");
    sprintf(result, format, this->value);
    return result;
}

static Object *float_add(const FloatClass *this, const FloatClass *other)
{
    return new(Float, this->value + other->value);
}

static Object *float_sub(const FloatClass *this, const FloatClass *other)
{
    return new(Float, this->value - other->value);
}

static Object *float_mul(const FloatClass *this, const FloatClass *other)
{
    return new(Float, this->value * other->value);
}

static Object *float_div(const FloatClass *this, const FloatClass *other)
{
    if (other->value == 0)
        raise("cannot divide by zero");
    return new(Float, this->value / other->value);
}

static bool float_eq(const FloatClass *this, const FloatClass *other)
{
    return this->value == other->value;
}

static bool float_gt(const FloatClass *this, const FloatClass *other)
{
    return this->value > other->value;
}

static bool float_lt(const FloatClass *this, const FloatClass *other)
{
    return this->value < other->value;
}

static const FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t) &float_ctor,
        .__dtor__ = (dtor_t) &float_dtor,
        .__str__ = (to_string_t) &float_print,
        .__add__ = (binary_operator_t) &float_add,
        .__sub__ = (binary_operator_t) &float_sub,
        .__mul__ = (binary_operator_t) &float_mul,
        .__div__ = (binary_operator_t) &float_div,
        .__eq__ = (binary_comparator_t) &float_eq,
        .__gt__ = (binary_comparator_t) &float_gt,
        .__lt__ = (binary_comparator_t) &float_lt
    },
    .value = 0
};

const Class *Float = (const Class *) &_description;
