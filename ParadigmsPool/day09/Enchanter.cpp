/*
** EPITECH PROJECT, 2023
** day09
** File description:
** reza
*/

#include <iostream>
#include "Enchanter.hpp"

Enchanter::Enchanter(const std::string &name, int power) : Peasant(name, power)
{
    std::cout << this->name << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << this->name << " closes his spellbook." << std::endl;
}

int Enchanter::attack()
{
    if (!this->canUseTechnique(0))
        return 0;
    std::cout << this->name << " doesn't know how to fight." << std::endl;
    return 0;
}

int Enchanter::special()
{
   if (!this->canUseTechnique(50))
        return 0;
   std::cout << this->name << " casts a fireball." << std::endl;
   return 99;
}

void Enchanter::rest()
{
     if (!canUseTechnique(0))
        return;
    std::cout << this->name << " meditates." << std::endl;
    this->power = std::min(this->power + 100, 100);
}