/*
** EPITECH PROJECT, 2023
** day07am
** File description:
** $DESCRIPTION
*/

#include <iostream>
#include "Federation.hpp"
#include "WarpSystem.hpp"
#include "Borg.hpp"

// Federation::Ship
Federation::Ship::Ship(int length, int width, std::string name) : BaseFederationShip(length, width, name, 1, VULCAN)
{
    std::cout << "The independent ship " << name << " just finished its construction." << std::endl;
    std::cout << "It is " << length << " m in length and " << width << " m in width." << std::endl;
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << _name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore(void)
{
    std::string result;

    if (_core == nullptr)
        return;
    result = _core->checkReactor()->isStable() ? "stable" : "unstable";

    std::cout << _name << ": The core is " << result << " at the time." << std::endl;
}

WarpSystem::Core *Federation::Ship::getCore()
{
    return this->_core;
}




// Federation::Starfleet::Ship
Federation::Starfleet::Ship::Ship() : Ship(289, 132, "Entreprise", 6)
{
}

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo) : BaseFederationShip(length, width, name, maxWarp, EARTH), _photonTorpedo(torpedo), _shield(100)
{
    std::cout << "The ship USS " << _name << " has been finished." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
    if (torpedo > 0)
        std::cout << "Weapons are set: " << torpedo << " torpedoes ready." << std::endl;
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << "USS " << _name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore(void)
{
    std::string result;

    if (_core == nullptr || _core == nullptr || _core->checkReactor() == NULL)
        return;
    result = _core->checkReactor()->isStable() ? "stable" : "unstable";

    std::cout << "USS " << _name << ": The core is " << result << " at the time." << std::endl;
}

void Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *captain)
{
    _captain = captain;

    std::cout << captain->getName() << ": I'm glad to be the captain of the USS "
              << _name << "." << std::endl;
}

int Federation::Starfleet::Ship::getShield()
{
    return _shield;
}

void Federation::Starfleet::Ship::setShield(int shield)
{
    _shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo()
{
    return _photonTorpedo;
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    _photonTorpedo = torpedo;
}

void Federation::Starfleet::Ship::fire(int torpedos, Borg::Ship *target)
{
    int current = this->getTorpedo();
    int after_shot = current - torpedos;

    if (after_shot < 0) {
        std::cout << _name << ": No enough torpedoes to fire, "
                  << this->_captain->getName() << "!" << std::endl;
        return;
    }
    std::cout << _name << ": Firing on target. " << after_shot << " torpedoes remaining." << std::endl;
    this->setTorpedo(current - torpedos);
    if (after_shot == 0) {
        std::cout << _name << ": No more torpedo to fire, " << this->_captain->getName() << "!" << std::endl;
    }
    target->setShield(std::max(0, target->getShield() - (50 * torpedos)));
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    this->fire(1, target);
}



// Captain
Federation::Starfleet::Captain::Captain(std::string name) : _name(name)
{
}

std::string Federation::Starfleet::Captain::getName()
{
    return _name;
}

int Federation::Starfleet::Captain::getAge()
{
    return _age;
}

void Federation::Starfleet::Captain::setAge(int age)
{
    _age = age;
}



// Ensign
Federation::Starfleet::Ensign::Ensign(std::string name) : _name(name)
{
    std::cout << "Ensign " << _name << ", awaiting orders." << std::endl;
}
