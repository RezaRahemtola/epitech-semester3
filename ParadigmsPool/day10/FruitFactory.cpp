/*
** EPITECH PROJECT, 2023
** day10
** File description:
** reza
*/

#include <iostream>
#include <algorithm>
#include "FruitFactory.hpp"

FruitFactory::FruitFactory() : fruits(std::vector<IFruit *>())
{}

FruitFactory::~FruitFactory()
{
    for (IFruit *fruit: this->fruits) {
        if (fruit != nullptr)
            delete fruit;
    }
}

void FruitFactory::registerFruit(IFruit *fruit)
{
    bool replaced = false;

    std::transform(this->fruits.begin(), this->fruits.end(), this->fruits.begin(), [fruit, &replaced](IFruit *i) {
        if (i != nullptr && i->getName() == fruit->getName()) {
            replaced = true;
            delete i;
            return fruit;
        }
        return i;
    });
    if (!replaced)
        this->fruits.push_back(fruit);
}

void FruitFactory::unregisterFruit(const std::string &name)
{
    std::transform(this->fruits.begin(), this->fruits.end(), this->fruits.begin(), [name](IFruit *i) -> IFruit * {
        if (i != nullptr && i->getName() == name) {
            delete i;
            return nullptr;
        }
        return i;
    });
}

IFruit *FruitFactory::createFruit(const std::string &name) const
{
    for (IFruit *fruit: this->fruits) {
        if (fruit != nullptr && fruit->getName() == name) {
            return fruit->clone();
        }
    }
    return nullptr;
}