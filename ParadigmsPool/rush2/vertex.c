/*
** EPITECH PROJECT, 2023
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdlib.h>
#include <stdio.h>
#include "new.h"
#include "raise.h"
#include "vertex.h"

typedef struct {
    Class base;
    int x;
    int y;
    int z;
} VertexClass;

static void vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void vertex_dtor(__attribute__((unused)) VertexClass *this)
{
    return;
}

static char *vertex_print(VertexClass *this)
{
    size_t length = snprintf(NULL, 0, "<Vertex (%d, %d, %d)>",
        this->x, this->y, this->z) + 1;
    char *result = calloc(length, sizeof(char));

    if (result == NULL)
        raise("Vertex print calloc failed");
    sprintf(result, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    return (result);
}

static Object *vertex_add(const VertexClass *this, const VertexClass *other)
{
    int x = this->x + other->x;
    int y = this->y + other->y;
    int z = this->z + other->z;
    return new(Vertex, x, y, z);
}

static Object *vertex_sub(const VertexClass *this, const VertexClass *other)
{
    int x = this->x - other->x;
    int y = this->y - other->y;
    int z = this->z - other->z;
    return new(Vertex, x, y, z);
}

static const VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t) &vertex_ctor,
        .__dtor__ = (dtor_t) &vertex_dtor,
        .__str__ = (to_string_t) &vertex_print,
        .__add__ = (binary_operator_t) &vertex_add,
        .__sub__ = (binary_operator_t) &vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class *Vertex = (const Class *) &_description;
