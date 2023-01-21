/*
** EPITECH PROJECT, 2023
** day07am
** File description:
** $DESCRIPTION
*/

#include "BaseShip.hpp"

// Constructors
BaseShip::BaseShip(short maxWarp, Destination home) : _maxWarp(maxWarp), _home(home), _location(home)
{
}

BaseFederationShip::BaseFederationShip(int length, int width, std::string name, int maxWarp, Destination home) : BaseShip(maxWarp, home), _length(length), _width(width), _name(name)
{
}


// Movements
bool BaseShip::move(int warp, Destination d)
{
    if (_core == nullptr || _core->checkReactor() == NULL)
        return (false);
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable()) {
        _location = d;
        return (true);
    }
    return (false);
}

bool BaseShip::move(int warp)
{
    return this->move(warp, _home);
}

bool BaseShip::move(Destination d)
{
    return this->move(_maxWarp, d);
}

bool BaseShip::move()
{
    return this->move(_home);
}
