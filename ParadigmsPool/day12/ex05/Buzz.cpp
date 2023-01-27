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

bool Buzz::speak(const std::string &message)
{
    std::cout << "BUZZ: ";
    return Toy::speak(message);
}

bool Buzz::speak_es(const std::string &message)
{
    std::cout << "BUZZ: " << this->name << " senorita \"" << message << "\" senorita" << std::endl;
    return true;
}
