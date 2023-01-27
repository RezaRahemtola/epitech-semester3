/*
** EPITECH PROJECT, 2023
** day13
** File description:
** Algorithm
*/

#pragma once

template<typename T>
void swap(T &a, T &b)
{
    T c = a;

    a = b;
    b = c;
}

template<typename T>
T min(T a, T b)
{
    return (a < b) ? a : b;
}

template<typename T>
T max(T a, T b)
{
    return (a < b) ? b : a;
}

template<typename T>
T clamp(T value, T min, T max)
{
    if (value < min) {
        return min;
    } else if (max < value) {
        return max;
    }
    return value;
}