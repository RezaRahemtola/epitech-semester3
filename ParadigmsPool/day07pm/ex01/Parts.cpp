/*
** EPITECH PROJECT, 2023
** day07pm
** File description:
** $DESCRIPTION
*/

#include <iostream>
#include "Parts.hpp"

Part::Part(const std::string &serial, bool functional, std::string name) : _serial(serial), _functional(functional), _name(name)
{
}

bool Part::isFunctional() const
{
    return _functional;
}

std::string Part::serial() const
{
    return _serial;
}

void Part::informations() const
{
    std::string status = _functional ? "OK" : "KO";
    std::cout << "\t[Parts] " << _name + " " + _serial + " status : " + status << std::endl;
}

Arms::Arms(const std::string &serial, bool functional) : Part(serial, functional, "Arms")
{
}

Legs::Legs(const std::string &serial, bool functional) : Part(serial, functional, "Legs")
{
}

Head::Head(const std::string &serial, bool functional) : Part(serial, functional, "Head")
{
}
