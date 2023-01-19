/*
** EPITECH PROJECT, 2022
** PDG-Rush2
** File description:
** Main
*/

#include <criterion/criterion.h>

#include "new.h"
#include "point.h"
#include "vertex.h"
#include "int.h"
#include "char.h"
#include "float.h"

typedef struct {
    Class base;
} EmptyClass;

static const EmptyClass _description = {
    {
        .__size__ = sizeof(EmptyClass),
        .__name__ = "Empty",
        .__ctor__ = NULL,
        .__dtor__ = NULL,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
};

const Class *Empty = (const Class *) &_description;


static Object *abs_va_list(const Class *class, ...)
{
    va_list list;
    Object *obj = NULL;

    va_start(list, class);
    obj = va_new(class, &list);
    va_end(list);
    return obj;
}

Test(empty, basic)
{
    Object *empty = new(Empty);

    cr_assert_not_null(empty);
    delete(empty);
}

Test(point, new)
{
    Object *point = new(Point, 42, -42);

    cr_assert_not_null(point);
    delete(point);
}

Test(vertex, new)
{
    Object *vertex = abs_va_list(Vertex, 1, 2, 3);

    cr_assert_not_null(vertex);
    delete(vertex);
}

Test(point, str)
{
    Object *point = new(Point, 1, 2);
    char *str = str(point);

    cr_assert_str_eq(str, "<Point (1, 2)>");
}

Test(vertex, str)
{
    Object *vertex = new(Vertex, 1, 2, 3);
    char *str = str(vertex);

    cr_assert_str_eq(str, "<Vertex (1, 2, 3)>");
}

Test(point, add)
{
    Object *first = new(Point, 1, 2);
    Object *second = new(Point, 3, 4);
    Object *add = addition(first, second);
    Object *sub = subtraction(second, first);
    char *str_add = str(add);
    char *str_sub = str(sub);

    cr_assert_str_eq(str_add, "<Point (4, 6)>");
    cr_assert_str_eq(str_sub, "<Point (2, 2)>");
}

Test(vertex, add)
{
    Object *first = new(Vertex, 1, 2, 3);
    Object *second = new(Vertex, 3, 4, 5);
    Object *add = addition(first, second);
    Object *sub = subtraction(second, first);
    char *str_add = str(add);
    char *str_sub = str(sub);

    cr_assert_str_eq(str_add, "<Vertex (4, 6, 8)>");
    cr_assert_str_eq(str_sub, "<Vertex (2, 2, 2)>");
}

Test(int_, ops)
{
    Object *a = new(Int, 1);
    Object *b = new(Int, 2);
    Object *add = addition(a, b);
    Object *sub = subtraction(a, b);
    Object *mul = multiplication(a, b);
    Object *div = division(a, b);
    char *s1 = str(add);
    char *s2 = str(sub);
    char *s3 = str(mul);
    char *s4 = str(div);

    cr_assert_str_eq(s1, "<Int (3)>");
    cr_assert_str_eq(s2, "<Int (-1)>");
    cr_assert_str_eq(s3, "<Int (2)>");
    cr_assert_str_eq(s4, "<Int (0)>");
}

Test(float_, ops)
{
    Object *a = new(Float, 1.5);
    Object *b = new(Float, 3.0);
    Object *add = addition(a, b);
    Object *sub = subtraction(a, b);
    Object *mul = multiplication(a, b);
    Object *div = division(a, b);
    char *s1 = str(add);
    char *s2 = str(sub);
    char *s3 = str(mul);
    char *s4 = str(div);

    cr_assert_str_eq(s1, "<Float (4.500000)>");
    cr_assert_str_eq(s2, "<Float (-1.500000)>");
    cr_assert_str_eq(s3, "<Float (4.500000)>");
    cr_assert_str_eq(s4, "<Float (0.500000)>");
}

Test(char_, ops)
{
    Object *a = new(Char, 80);
    Object *b = new(Char, 30);
    Object *c = new(Char, 2);
    Object *add = addition(a, b);
    Object *sub = subtraction(a, b);
    Object *mul = multiplication(b, c);
    Object *div = division(a, c);
    char *s1 = str(add);
    char *s2 = str(sub);
    char *s3 = str(mul);
    char *s4 = str(div);

    cr_assert_str_eq(s1, "<Char (n)>");
    cr_assert_str_eq(s2, "<Char (2)>");
    cr_assert_str_eq(s3, "<Char (<)>");
    cr_assert_str_eq(s4, "<Char (()>");
}

Test(int_, cmp)
{
    Object *a = new(Int, 1);
    Object *b = new(Int, 2);

    cr_assert_eq(eq(a, b), false);
    cr_assert_eq(gt(a, b), false);
    cr_assert_eq(lt(a, b), true);
}

Test(float_, cmp)
{
    Object *a = new(Float, 1.5);
    Object *b = new(Float, 1.4);

    cr_assert_eq(eq(a, b), false);
    cr_assert_eq(gt(a, b), true);
    cr_assert_eq(lt(a, b), false);
}

Test(char_, cmp)
{
    Object *a = new(Char, 'a');
    Object *b = new(Char, 'a');

    cr_assert_eq(eq(a, b), true);
    cr_assert_eq(gt(a, b), false);
    cr_assert_eq(lt(a, b), false);
}
