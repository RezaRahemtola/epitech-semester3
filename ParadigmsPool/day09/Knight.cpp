/*
** EPITECH PROJECT, 2023
** day09
** File description:
** reza
*/

#include <iostream>
#include "Knight.hpp"

Knight::Knight(const std::string &name, int power) : Peasant(name, power)
{
    std::cout << this->name << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight()
{
    std::cout << this->name << " takes off his armor." << std::endl;
}

int Knight::attack()
{
    if (!this->canUseTechnique(10))
        return 0;
    std::cout << this->name << " strikes with his sword." << std::endl;
    return 20;
}

int Knight::special()
{
   if (!this->canUseTechnique(30))
        return 0;
   std::cout << this->name << " impales his enemy." << std::endl;
   return 50;
}

void Knight::rest()
{
     if (!canUseTechnique(0))
        return;
    std::cout << this->name << " eats." << std::endl;
    this->power = std::min(this->power + 50, 100);
}