/*
** EPITECH PROJECT, 2023
** ex00
** File description:
** $DESCRIPTION
*/

#include <iostream>
#include "Droid.hpp"

Droid::Droid(std::string serial) : Id(serial)
{
    std::cout << "Droid '" << Id << "' Activated" << std::endl;
}

Droid::Droid(const Droid &droid) : Id(droid.Id), Energy(droid.Energy), Status(new std::string(*droid.Status))
{
    std::cout << "Droid '" << droid.Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    delete this->Status;
    delete this->BattleData;
    std::cout << "Droid '" << Id << "' Destroyed" << std::endl;
}

std::string Droid::getId() const
{
    return this->Id;
}

void Droid::setId(std::string id)
{
    this->Id = id;
}

std::size_t Droid::getEnergy() const
{
    return this->Energy;
}

void Droid::setEnergy(std::size_t energy)
{
    this->Energy = std::min((std::size_t)100, std::max(energy, (std::size_t)0));
}

std::size_t Droid::getAttack() const
{
    return this->Attack;
}

std::size_t Droid::getToughness() const
{
    return this->Toughness;
}

std::string *Droid::getStatus() const
{
    return this->Status;
}

void Droid::setStatus(std::string *status)
{
    this->Status = status;
}


// Operators
Droid &Droid::operator=(const Droid &source)
{
    if (this == &source)
        return *this;

    delete this->Status;
    delete this->BattleData;

    this->Id = source.Id;
    this->Energy = source.Energy;
    this->Status = new std::string(*source.Status);
    this->BattleData = new DroidMemory(*source.BattleData);
    return *this;
}

bool Droid::operator==(const Droid &other) const
{
    return *(this->Status) == *(other.Status);
}

bool Droid::operator!=(const Droid &other) const
{
    return *(this->Status) != *(other.Status);
}

void Droid::operator<<(std::size_t &amount)
{
    std::size_t required = 100 - this->Energy;

    this->Energy += std::min(amount, required);
    amount -= std::min(amount, required);
}

std::ostream &operator<<(std::ostream&stream, const Droid &droid)
{
    return stream << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy();
}

DroidMemory *Droid::getBattleData() const
{
    return this->BattleData;
}

void Droid::setBattleData(DroidMemory *mem)
{
    this->BattleData = mem;
}
