/*
** EPITECH PROJECT, 2023
** Day04am
** File description:
** Exercise 5
*/

#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static bool exists_in(int *array, int elem, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        if (array[i] == elem) {
            return (true);
        }
    }
    return (false);
}

size_t uniq_int_array(int *array, size_t nmemb)
{
    int *new = calloc(nmemb, sizeof(int));
    size_t new_length = 0;

    for (size_t i = 0; i < nmemb; i++) {
        if (!exists_in(new, array[i], new_length)) {
            new[new_length] = array[i];
            new_length++;
        }
    }
    memcpy(array, new, new_length * sizeof(int));
    free(new);
    return (new_length);
}

static bool universal_exists_in(void *array, size_t *data, void *elem,
int(*compar)(const void *, const void *))
{
    for (size_t i = 0; i < data[0]; i++) {
        if (compar(array + i * data[1], elem) == 0) {
            return (true);
        }
    }
    return (false);
}

size_t uniq_array(void *array, size_t nmemb, size_t size,
int(*compar)(const void *, const void *))
{
    void *new = calloc(nmemb, size);
    size_t new_length = 0;

    for (size_t i = 0; i < nmemb; i++) {
        if (!universal_exists_in(new, (size_t [2]){new_length, size},
            array + i * size, compar)) {
            memcpy(new + new_length * size, array + i * size, size);
            new_length++;
        }
    }
    memcpy(array, new, new_length * size);
    free(new);
    return (new_length);
}
