/*
** EPITECH PROJECT, 2023
** Paradigms Seminar
** File description:
** Exercice 04
*/

#include <stdlib.h>
#include <stdio.h>
#include "new.h"
#include "char.h"
#include "raise.h"

typedef struct {
    Class base;
    char c;
} CharClass;

static void char_ctor(CharClass *this, va_list *args)
{
    this->c = va_arg(*args, int);
}

static void char_dtor(__attribute__((unused)) CharClass *this)
{
    return;
}

static char *char_print(CharClass *this)
{
    const char *format = "<Char (%c)>";
    size_t length = snprintf(NULL, 0, format, this->c) + 1;
    char *result = calloc(length, sizeof(char));

    if (!result)
        raise("Char print calloc failed");
    sprintf(result, format, this->c);
    return result;
}

static Object *char_add(const CharClass *this, const CharClass *other)
{
    return new(Char, this->c + other->c);
}

static Object *char_sub(const CharClass *this, const CharClass *other)
{
    return new(Char, this->c - other->c);
}

static Object *char_mul(const CharClass *this, const CharClass *other)
{
    return new(Char, this->c * other->c);
}

static Object *char_div(const CharClass *this, const CharClass *other)
{
    if (other->c == 0)
        raise("Cannot divide by 0");
    return new(Char, this->c / other->c);
}

static bool char_eq(const CharClass *this, const CharClass *other)
{
    return (this->c == other->c);
}

static bool char_gt(const CharClass *this, const CharClass *other)
{
    return (this->c > other->c);
}

static bool char_lt(const CharClass *this, const CharClass *other)
{
    return (this->c < other->c);
}

static const CharClass _description = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t) &char_ctor,
        .__dtor__ = (dtor_t) &char_dtor,
        .__str__ = (to_string_t) &char_print,
        .__add__ = (binary_operator_t) &char_add,
        .__sub__ = (binary_operator_t) &char_sub,
        .__mul__ = (binary_operator_t) &char_mul,
        .__div__ = (binary_operator_t) &char_div,
        .__eq__ = (binary_comparator_t) &char_eq,
        .__gt__ = (binary_comparator_t) &char_gt,
        .__lt__ = (binary_comparator_t) &char_lt,
    },
    .c = '\0'
};

const Class *Char = (const Class *) &_description;
