/*
** EPITECH PROJECT, 2023
** ex03
** File description:
** $DESCRIPTION
*/

#include <iostream>
#include "Phaser.hpp"
#include "Sounds.hpp"

const int Phaser::Empty = 0;

Phaser::Phaser(int maxAmmo, AmmoType type) : maxAmmo(maxAmmo), defaultType(type), ammo(std::vector<AmmoType>(maxAmmo, type))
{
}

Phaser::~Phaser()
{
}


void Phaser::fire()
{
    if (this->ammo.size() == Empty) {
        std::cout << "Clip empty, please reload" << std::endl;
        return;
    }
    AmmoType current = this->ammo.front();
    std::string sound = std::vector<std::string>({Sounds::Regular, Sounds::Plasma, Sounds::Rocket})[current];
    std::cout << sound << std::endl;

    this->ammo.erase(this->ammo.begin());
}

void Phaser::ejectClip()
{
    this->ammo.clear();
}

void Phaser::changeType(AmmoType newType)
{
    std::string sound = std::vector<std::string>({"regular", "plasma", "rocket"})[newType];

    std::cout << "Switching ammo to type: " << sound << std::endl;
    this->defaultType = newType;
}

void Phaser::reload()
{
    std::cout << "Reloading..." << std::endl;
    this->ammo = std::vector<AmmoType>(this->maxAmmo, this->defaultType);
}

void Phaser::addAmmo(AmmoType type)
{
    if ((int)this->ammo.size() == this->maxAmmo) {
        std::cout << "Clip full" << std::endl;
        return;
    }
    this->ammo.push_back(type);
}

int Phaser::getCurrentAmmos() const
{
    return this->ammo.size();
}
