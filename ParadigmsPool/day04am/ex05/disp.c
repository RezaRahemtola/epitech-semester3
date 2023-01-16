/*
** EPITECH PROJECT, 2023
** ex05
** File description:
** $DESCRIPTION
*/

#include <stdio.h>
#include <stddef.h>

void disp_int_array(const int *array, size_t nmemb)
{
    if (array == NULL)
        return;
    for (size_t i = 0; i < nmemb; i++) {
        printf("%d\n", array[i]);
    }
}

void disp_array(const void *array, size_t nmemb, size_t size,
void (*print)(const void *))
{
    for (size_t i = 0; i < nmemb; i++) {
        print(array);
        array += size;
    }
}
