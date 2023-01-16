/*
** EPITECH PROJECT, 2023
** ex05
** File description:
** $DESCRIPTION
*/

#include <stddef.h>
#include <stdlib.h>

static int comparator (const void *p1, const void *p2)
{
    int a = *(int *)p1;
    int b = *(int *)p2;

    return a - b;
}

void sort_int_array(int *array, size_t nmemb)
{
    qsort(array, nmemb, sizeof(int), comparator);
}

void sort_array(void *array, size_t nmemb, size_t size,
int(*compar)(const void *, const void *))
{
    qsort(array, nmemb, size, compar);
}
