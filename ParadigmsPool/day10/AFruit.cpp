/*
** EPITECH PROJECT, 2023
** day10
** File description:
** reza
*/

#include "AFruit.hpp"

#include <utility>

AFruit::AFruit(std::string name, unsigned int vitamins, bool peeled) : peeled(peeled), vitamins(vitamins),
                                                                       name(name)
{
}

std::string AFruit::getName() const
{
    return this->name;
}

bool AFruit::isPeeled() const
{
    return this->peeled;
}

void AFruit::peel()
{
    this->peeled = true;
}

unsigned int AFruit::getVitamins() const
{
    return this->peeled ? this->vitamins : 0;
}

IFruit *AFruit::clone() const
{
    return new AFruit(this->name, this->vitamins, this->peeled);
}