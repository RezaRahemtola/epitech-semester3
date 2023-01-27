/*
** EPITECH PROJECT, 2023
** day12
** File description:
** Buzz
*/

#include <iostream>
#include <utility>
#include "Buzz.hpp"


Buzz::Buzz(const std::string &name, const std::string &ascii) : Toy(BUZZ, name, ascii)
{}

void Buzz::speak(const std::string &message)
{
    std::cout << "BUZZ: ";
    Toy::speak(message);
}
