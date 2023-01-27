/*
** EPITECH PROJECT, 2023
** day12
** File description:
** Woody
*/

#include <iostream>
#include "Woody.hpp"


Woody::Woody(const std::string &name, const std::string &ascii) : Toy(WOODY, name, ascii)
{}

void Woody::speak(const std::string &message)
{
    std::cout << "WOODY: ";
    Toy::speak(message);
}
