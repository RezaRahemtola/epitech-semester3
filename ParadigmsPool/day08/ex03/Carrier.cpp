/*
** EPITECH PROJECT, 2023
** ex03
** File description:
** $DESCRIPTION
*/

#include <iostream>
#include "Carrier.hpp"

Carrier::Carrier(std::string id) : Id(id), Energy(300), Attack(100), Toughness(90)
{
    this->Droids = new Droid *[5];
    for (short i = 0; i < 5; i++)
        this->Droids[i] = NULL;
}

Carrier::~Carrier()
{
    for (short i = 0; i < 5; i++)
        if (this->Droids[i])
            delete this->Droids[i];
    delete [] this->Droids;
}

std::string Carrier::getId() const
{
    return (this->Id);
}

size_t Carrier::getEnergy() const
{
    return (this->Energy);
}

size_t Carrier::getSpeed() const
{
    return (100 - this->getBoardedCount() * 10);
}

size_t Carrier::getBoardedCount() const
{
    int len = 0;
    for (short i = 0; i < 5; i++)
        if (this->Droids[i])
            len++;
    return (len);
}

Droid *&Carrier::operator[](int position) const
{
    return (this->Droids[position]);
}

bool Carrier::operator()(int x, int y)
{
    size_t cost = (std::abs(x) + std::abs(y)) * (10 + this->getBoardedCount());

    if (this->Speed == 0 || cost > this->Energy)
        return (false);

    this->Energy -= cost;
    return (true);
}

void Carrier::operator<<(size_t &amount)
{
    std::size_t required = 600 - this->Energy;

    this->Energy += std::min(amount, required);
    amount -= std::min(amount, required);
}

Carrier &Carrier::operator<<(Droid *&droid)
{
    for (short i = 0; i < 5; i++) {
        if (this->Droids[i] == nullptr) {
            this->Droids[i] = droid;
            droid = nullptr;
            return (*this);
        }
    }
    return (*this);
}

Carrier &Carrier::operator>>(Droid *&droid)
{
    for (short i = 0; i < 5; i++) {
        if (this->Droids[i] != nullptr) {
            droid = this->Droids[i];
            this->Droids[i] = nullptr;
            return (*this);
        }
    }
    return (*this);
}

Carrier &Carrier::operator~()
{
    this->Speed = (100 - this->getBoardedCount() * 10);
    return (*this);
}

std::ostream &operator<<(std::ostream&stream, const Carrier &carrier)
{
    stream << "Carrier '" << carrier.getId() << "' Droid(s) on-board:" << std::endl;
    for (short i = 0; i < 5; i++) {
        stream << "[" << i << "] : ";
        if (carrier[i] != nullptr) {
            stream << *carrier[i];
        } else {
            stream << "Free";
        }
        stream << std::endl;
    }
    stream << "Speed : " << carrier.getSpeed() << ", Energy " << carrier.getEnergy();
    return (stream);
}
