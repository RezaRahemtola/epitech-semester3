/*
** EPITECH PROJECT, 2023
** day10
** File description:
** reza
*/

#pragma once

#include "IFruit.hpp"

class FruitBox {
    public:
        explicit FruitBox(unsigned int size);
        ~FruitBox();

        unsigned int getSize() const;
        unsigned int nbFruits() const;
        bool pushFruit(IFruit *);
        IFruit *popFruit();

        IFruit **getFruits() const;
    private:
        unsigned int size;
        IFruit **fruits;
};

std::ostream &operator<<(std::ostream &stream, const FruitBox &box);