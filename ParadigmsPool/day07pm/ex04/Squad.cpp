/*
** EPITECH PROJECT, 2023
** ex04
** File description:
** $DESCRIPTION
*/

#include "Squad.hpp"
#include "Sounds.hpp"

const std::string Sounds::Regular = "Bang";
const std::string Sounds::Plasma = "Fwooosh";
const std::string Sounds::Rocket = "Boouuuuuum";

Squad::Squad(int posXBegin, int posYBegin, Phaser::AmmoType ammoType, int size) : _skats(new Skat *[size + 1])
{
    for (int i = 0; i < size; i++) {
        this->_skats[i] = new Skat("bob", 15, i, posXBegin + i * 10, posYBegin + i * 15, ammoType);
    }
    this->_skats[size] = nullptr;

    for (int i = 0; i < size - 1; i++) {
        this->_skats[i]->com().addCom(&(this->_skats[i + 1]->com()));
    }
}

Squad::~Squad()
{
    for (int i = 0; this->_skats[i] != nullptr; i++) {
        delete this->_skats[i];
    }
    delete [] this->_skats;
}

void Squad::fire() const
{
    for (int i = 0; this->_skats[i] != nullptr; i++)
        this->_skats[i]->fire();
}

void Squad::localisation() const
{
    for (int i = 0; this->_skats[i] != nullptr; i++)
        this->_skats[i]->com().ping();
}

Skat *Squad::at(int idx) const
{
    if (idx < 0)
        return (nullptr);
    for (int i = 0; this->_skats[i] != nullptr; i++) {
        if (i == idx)
            return this->_skats[i];
    }
    return (nullptr);
}

int Squad::size() const
{
    int count = 0;

    for (int i = 0; this->_skats[i] != nullptr; i++)
        count++;
    return (count);
}

Skat **Squad::skats() const
{
    return this->_skats;
}

void foreach(Skat **beginIdx, void (Skat::*actionPtr)() const)
{
    for (int i = 0; beginIdx[i] != nullptr; i++)
        (beginIdx[i]->*actionPtr)();
}
