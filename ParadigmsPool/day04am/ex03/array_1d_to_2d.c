/*
** EPITECH PROJECT, 2023
** Day04am
** File description:
** Exercise 03
*/

#include <stdlib.h>

void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res)
{
    int counter = 0;

    if (res == NULL)
        return;
    *res = calloc(height, sizeof(int *));
    for (size_t i = 0; i < height; i++) {
        (*res)[i] = calloc(width, sizeof(int));
        for (size_t j = 0; j < width; j++) {
            (*res)[i][j] = array[counter];
            counter++;
        }
    }
}

void array_2d_free(int **array, size_t height, size_t width)
{
    (void) width;
    if (array == NULL)
        return;
    for (size_t i = 0; i < height; i++) {
        free(array[i]);
    }
    free(array);
}
