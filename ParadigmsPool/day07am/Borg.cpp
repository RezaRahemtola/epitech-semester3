/*
** EPITECH PROJECT, 2023
** day07am
** File description:
** $DESCRIPTION
*/

#include <iostream>
#include "Borg.hpp"
#include "Federation.hpp"

Borg::Ship::Ship(int weaponFrequency, short repair) : BaseShip(9, UNICOMPLEX), _side(300), _weaponFrequency(weaponFrequency), _repair(repair), _shield(100)
{
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl
              << "Your biological characteristics and technologies will be assimilated." << std::endl
              << "Resistance is futile." << std::endl;
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
}

void Borg::Ship::checkCore(void)
{
    if (_core == nullptr)
        return;
    if (_core->checkReactor()->isStable())
        std::cout << "Everything is in order." << std::endl;
    else
        std::cout << "Critical failure imminent." << std::endl;
}

int Borg::Ship::getShield()
{
    return this->_shield;
}

void Borg::Ship::setShield(int shield)
{
    _shield = shield;
}

int Borg::Ship::getWeaponFrequency()
{
    return this->_weaponFrequency;
}

void Borg::Ship::setWeaponFrequency(int frequency)
{
    _weaponFrequency = frequency;
}

short Borg::Ship::getRepair()
{
    return _repair;
}

void Borg::Ship::setRepair(short repair)
{
    _repair = repair;
}

void Borg::Ship::fire(Federation::Starfleet::Ship *target)
{
    std::cout << "Firing on target with " << _weaponFrequency << "GW frequency." << std::endl;
    target->setShield(std::max(0, target->getShield() - _weaponFrequency));
}

void Borg::Ship::fire(Federation::Ship *target)
{
    std::cout << "Firing on target with " << _weaponFrequency << "GW frequency." << std::endl;
    target->getCore()->checkReactor()->setStability(false);
}

void Borg::Ship::repair()
{
    if (this->_repair <= 0) {
        std::cout << "Energy cells depleted, shield weakening." << std::endl;
        return;
    }
    std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions."
              << std::endl;
    this->_repair -= 1;
    this->_shield = 100;
}
