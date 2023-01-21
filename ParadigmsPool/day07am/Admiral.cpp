/*
** EPITECH PROJECT, 2023
** day07am
** File description:
** $DESCRIPTION
*/

#include <iostream>
#include "Admiral.hpp"

Federation::Starfleet::Admiral::Admiral(std::string name) : _name(name)
{
    std::cout << "Admiral " << _name << " ready for action." << std::endl;
}

bool Federation::Starfleet::Admiral::move(Federation::Starfleet::Ship *ship, Destination dest)
{
    return (ship->*this->movePtr)(dest);
}

void Federation::Starfleet::Admiral::fire(Federation::Starfleet::Ship *ship, Borg::Ship *target)
{
    std::cout << "On order from Admiral " << this->_name << ":" << std::endl;
    (ship->*this->firePtr)(target);
}
