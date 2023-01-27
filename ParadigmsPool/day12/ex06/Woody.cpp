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

bool Woody::speak(const std::string &message)
{
    std::cout << "WOODY: ";
    return Toy::speak(message);
}
