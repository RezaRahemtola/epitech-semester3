/*
** EPITECH PROJECT, 2023
** day10
** File description:
** reza
*/

#include <iostream>
#include "FruitMixer.hpp"

void FruitMixer::setBlade(IBlade *blade)
{
    this->_blade = blade;
}

unsigned int FruitMixer::mixFruits(FruitBox &box) const
{
    IFruit *fruit = nullptr;
    unsigned int vitamins = 0;
    unsigned int nbFruits = box.nbFruits();

    if (this->_blade == nullptr) {
        std::cout << "mixer has no blade" << std::endl;
        return 0;
    }

    for (unsigned int i = 0; i < nbFruits; i++) {
        fruit = box.popFruit();
        if (fruit == nullptr)
            continue;
        if (fruit->isPeeled()) {
            vitamins += (*this->_blade)(*fruit);
        } else {
            box.pushFruit(fruit);
        }
    }
    return vitamins;
}