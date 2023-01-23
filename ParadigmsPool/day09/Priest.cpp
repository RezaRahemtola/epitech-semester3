/*
** EPITECH PROJECT, 2023
** day09
** File description:
** reza
*/

#include <iostream>
#include "Priest.hpp"

Priest::Priest(const std::string &name, int power) : Peasant(name, power), Enchanter(name, power)
{
    std::cout << this->name << " enters in the order." << std::endl;
}

Priest::~Priest()
{
    std::cout << this->name << " finds peace." << std::endl;
}

void Priest::rest()
{
    if (!canUseTechnique(0))
        return;
    std::cout << this->name << " prays." << std::endl;
    this->power = std::min(this->power + 100, 100);
    this->hp = std::min(this->power + 100, 100);
}