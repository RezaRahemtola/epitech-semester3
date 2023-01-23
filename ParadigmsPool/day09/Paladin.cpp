/*
** EPITECH PROJECT, 2023
** day09
** File description:
** reza
*/

#include <iostream>
#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int power) : Peasant(name, power), Knight(name, power), Priest(name, power)
{
    std::cout << this->name << " fights for the light." << std::endl;
}

Paladin::~Paladin()
{
    std::cout << this->name << " is blessed." << std::endl;
}

int Paladin::attack()
{
    return this->Knight::attack();
}

int Paladin::special()
{
    return this->Enchanter::special();
}

void Paladin::rest()
{
    this->Priest::rest();
}