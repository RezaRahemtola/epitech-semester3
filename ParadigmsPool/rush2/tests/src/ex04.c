/*
** EPITECH PROJECT, 2023
** Paradigms Seminar
** File description:
** Exercise 4
*/

#include <stdio.h>
#include "object.h"
#include "int.h"
#include "float.h"
#include "char.h"
#include "new.h"

static void compareAndDivide(Object *a, Object *b)
{
    if (gt(a, b))
        printf("a > b \n");
    else if (lt(a, b))
        printf("a < b \n");
    else
        printf("a == b \n");
    printf("b / a = %s \n", str(division(b, a)));
}

int main(void)
{
    Object *i1 = new(Int, 42);
    Object *i2 = new(Int, 2);

    compareAndDivide(i1, i2);

    Object *f1 = new(Float, 66.6);
    Object *f2 = new(Float, (float) 3);

    compareAndDivide(f1, f2);

    Object *c1 = new(Char, 'a');
    Object *c2 = new(Char, '\n');

    compareAndDivide(c1, c2);
}
