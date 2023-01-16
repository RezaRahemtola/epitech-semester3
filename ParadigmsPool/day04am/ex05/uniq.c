/*
** EPITECH PROJECT, 2023
** Day04am
** File description:
** Exercise 5
*/

#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static bool exists_before(int *array, size_t curr)
{
    for (size_t i = 0; i < curr; i++) {
        if (array[i] == array[curr]) {
            return (true);
        }
    }
    return (false);
}

size_t uniq_int_array(int *array, size_t nmemb)
{
    size_t count = nmemb;

    for (size_t i = 0; i < count; i++) {
        if (exists_before(array, i)) {
            count--;
            memmove(array + i, array + i + 1, count - i);
        }
    }
    return (count);
}

static bool universal_exists_before(void *array, size_t curr, size_t size,
int(*compar)(const void *, const void *))
{
    for (size_t i = 0; i < curr; i++) {
        if (compar(array + i * size, array + curr * size) == 0) {
            return (true);
        }
    }
    return (false);
}

size_t uniq_array(void *array, size_t nmemb, size_t size,
int(*compar)(const void *, const void *))
{
    size_t count = nmemb;

    for (size_t i = 0; i < count; i++) {
        if (universal_exists_before(array, i, size, compar)) {
            count--;
            memmove(array + i * size, array + (i + 1) * size,
            (count - i) * size);
            i--;
        }
    }
    return (count);
}
