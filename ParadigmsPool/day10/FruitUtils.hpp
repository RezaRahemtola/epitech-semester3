/*
** EPITECH PROJECT, 2023
** day10
** File description:
** reza
*/

#pragma once

#include "FruitBox.hpp"

class FruitUtils {
    public:
        static void sort(FruitBox &unsorted, FruitBox &lemon, FruitBox &citrus, FruitBox &berry);
        static FruitBox **pack(IFruit **fruits, unsigned int boxSize);
        static IFruit **unpack(FruitBox **fruitBoxes);
};