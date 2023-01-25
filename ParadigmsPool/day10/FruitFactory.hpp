/*
** EPITECH PROJECT, 2023
** day10
** File description:
** reza
*/

#pragma once

#include <vector>
#include "IFruit.hpp"

class FruitFactory {
    public:
        FruitFactory();
        ~FruitFactory();
        void registerFruit(IFruit *fruit);
        void unregisterFruit(const std::string &name);
        IFruit *createFruit(const std::string &name) const;
    private:
        std::vector<IFruit *> fruits;
};