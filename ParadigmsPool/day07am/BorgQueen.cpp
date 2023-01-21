/*
** EPITECH PROJECT, 2023
** day07am
** File description:
** $DESCRIPTION
*/

#include "BorgQueen.hpp"

bool Borg::BorgQueen::move(Borg::Ship *ship, Destination dest)
{
    return (ship->*this->movePtr)(dest);
}

void Borg::BorgQueen::fire(Borg::Ship *ship, Federation::Starfleet::Ship *target)
{
    return (ship->*this->firePtr)(target);
}

void Borg::BorgQueen::destroy(Borg::Ship *ship, Federation::Ship *target)
{
    return (ship->*this->destroyPtr)(target);
}
